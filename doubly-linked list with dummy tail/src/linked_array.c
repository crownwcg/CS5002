/*
 * linked_array.c
 *
 * This file implements a singly linked array. The methods can be
 * used in one of two ways.
 *
 * If the empty list is represented by a NULL list pointer, then
 * add the first item by setting the list pointer to the first item
 * and delete the final item by freeing the node and setting the
 * list pointer to NULL.
 *
 * If the empty list is represented by a dummy first node, then
 * add the first item by calling addAfter() with the dummy node and
 * the first node, delete the last item by calling deleteAfter()
 * with the dummy first node, and get the size excluding the dummy
 * node by passing the dummy node's next pointer to getListSize().
 *
 * @since 2017-02-08
 * @author philip gust
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_array.h"

/**
 * Create and initialize new node.
 *
 * @return Node with fields set to NULL
 */
LinkedArrayNode* createLinkedArrayNode(const char* data) {
	// allocate node
	LinkedArrayNode* newNode = malloc(sizeof(LinkedArrayNode));
	// initialize fields
	newNode->data = (data == NULL) ? NULL : strdup(data);
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;

}

/**
 * Freeing node storage.  The node must be removed from its list
 * by calling deleteNode() first. A NULL node value is ignored.
 *
 * @param node the LinkedListNode to delete
 */
void deleteLinkedArrayNode(LinkedArrayNode* node) {
	if (node != NULL) {
		// free pointer to data string
		free(node->data);  // free ok with NULL
		node->data = NULL;

		// reset the next pointer
		node->next = NULL;

		// reset the previous pointer
		node->prev = NULL;

		// now free the node
		free(node);
	}
}

/**
 * Return the node at the Kth position relative to the input node.
 * If there are fewer than K items in the list, returns NULL.
 *
 * @param list the list to be measured
 * @param k the index
 * @return the Kth node from input node or NULL if fewer than K items
 */
LinkedArrayNode *getLinkedArrayNodeAt(LinkedArrayNode *list, size_t k) {
	LinkedArrayNode* n = list;
	for ( ; n != NULL && k > 0; n = n->next, k--) { }
	return n;
}

/**
 * Return the node at the Kth position relative to the input node.
 * If there are fewer than K items in the list, returns NULL.
 *
 * @param list the list
 * @param k the index
 * @param val the result parameter for  the value of the Kth node from input node
 * @return true if returned value of kth node as val, or false if index out of bounds
 */
bool getLinkedArrayNodeValAt(LinkedArrayNode *list, size_t k, const char **val) {
	LinkedArrayNode* n = getLinkedArrayNodeAt(list, k);
	if (n != NULL) {
		*val = n->data;
		return true;
	}
	return false;
}

/**
 * Return the node at the Kth position relative to the input node.
 * If there are fewer than K items in the list, returns NULL.
 *
 * @param list the list to be measured
 * @param k the index
 * @return true if set value of kth node as val, or false if index out of bounds
 */
bool setLinkedArrayNodeValAt(LinkedArrayNode *list, size_t k, const char *val) {
	LinkedArrayNode* n = getLinkedArrayNodeAt(list, k);
	if (n != NULL) {
		free(n->data);
		n->data = (val == NULL) ? NULL : strdup(val);
		return true;
	}
	return false;
}

/**
 * Return the index of the node in the list.
 *
 * @param list the list to be measured
 * @param node the node to find
 * @return the index of the node in the list or SIZE_MAX if NULL or not in list
 */
 size_t getLinkedArrayNodeIndex(LinkedArrayNode* list, LinkedArrayNode *node) {
	 if (node != NULL) {
		 size_t index = 0;
		 // look for node in list
		 for (LinkedArrayNode *nodep = node; nodep->data != NULL; nodep = nodep->next, index++) {
			 if (nodep == node) {
				 return index;
			 }
		 }
	 }
	 return SIZE_MAX;
 }

 /**
  * Returns first node in list, or NULL if list is NULL.
  *
  * @param the list of LinkedArrayNode
  * @return the first node in the list or NULL
  */
 LinkedArrayNode* getFirstLinkedArrayNode(LinkedArrayNode *list) {
	LinkedArrayNode* n = list;
	if (n != NULL) {
		for ( ; n->prev != NULL; n = n->prev) {}
	}
	return n;
 }

/**
 * Returns last node in list, or NULL if list is NULL.
 *
 * @param the list of LinkedListNodes
 * @return the last node in the list or NULL
 */
LinkedArrayNode* getLastLinkedArrayNode(LinkedArrayNode* list) {
	LinkedArrayNode* n = list;
	if (n != NULL) {
		for ( ; n->next != NULL; n = n->next) {}
	}
	return n;
}

/**
 * Return the size of the list. If the list has a dummy first node, pass
 * its next pointer to this function.
 *
 * @param list the list to be measured
 * @return the size of the list
 */
size_t linkedArraySize(LinkedArrayNode* list) {
	size_t size = 0;
	// traverse down the list, counting as it goes
	for (LinkedArrayNode* node = list; node != NULL; node= node->next, size++) {}
	return size;
}

/**
 * Add new node after the specified node in the list.
 *
 * @param list the list node after which new node will be added
 * @param the new node to insert
 */
void addAfterLinkedArrayNode(LinkedArrayNode* list, LinkedArrayNode* newNode) {  // note: refactored from addLast()
	if (list != NULL) {
		LinkedArrayNode *next = list->next;
		// make new node point to successor of list node
		newNode->next = next;
		// make new node point to the list node
		newNode->prev = list;
		// make list node point to new node
		list->next = newNode;
		if (next != NULL)
			next->prev = newNode;
	} else {
		// first node in list
		newNode->next = NULL;
		newNode->prev = NULL;
	}
}

/**
 * Delete node after specified list node. Caller is responsible for
 * freeing the deleted node by calling freeNode().
 *
 * @param the list node after which node will be deleted
 * @return the deleted node that the caller must free, or NULL if
 *   list has no next node
 */
LinkedArrayNode* deleteAfterLinkedArrayNode(LinkedArrayNode* list) {
	LinkedArrayNode *deletedNode = NULL;

	if (list != NULL) {
		// pointer to next node that will to be deleted
		deletedNode = list->next;

		// only need to do if there is a next node to delete
		if (deletedNode != NULL) {
			// make list node point to where next node pointed
			list->next = deletedNode->next;

			// reset next and previous pointer of deletedNode node
			deletedNode->next = NULL;
			deletedNode->prev = NULL;
		}
		if (list->next != NULL) {
			list->next->prev = list;
		}
	}
	return deletedNode;
}

/**
 * Deletes all linked array nodes in the list.
 * @param node the starting linked array node
 */
void deleteAllLinkedArrayNodes(LinkedArrayNode *node) {
	// delete all nodes after node
	LinkedArrayNode *n;
	while ((n = deleteAfterLinkedArrayNode(node)) != NULL) {
		deleteLinkedArrayNode(n);
	}
	// delete last node
	deleteLinkedArrayNode(node);
}

/**
 * Print the list data.
 *
 * @param list the list to print
 */
void printLinkedArrayNode(LinkedArrayNode *list) {
	printf("( ");
	for (LinkedArrayNode* n = list; n != NULL; n = n->next) {
		printf("\"%s\" ", n->data);
	}
	printf(")\n");
	fflush(stdout);
}
