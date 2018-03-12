/*
 * linked_array.h
 *
 * This file provides the structure and function definitions for a
 * singly linked array. The methods can be used in one of two ways.
 *
 * If the empty list is represented by a NULL list pointer, then
 * add the first item by setting the list pointer to the first item
 * and delete the final item by freeing the node and setting the
 * list pointer to NULL.
 *
 * If the empty list is represented by a dummy first node, then
 * add the first item by calling addAfterLinkedArrayNode() with the
 * dummy node and the first node, delete the last item by calling
 * deleteAfterLinkedArrayNode() with the dummy first node, and get
 * the size excluding the dummy node by passing the dummy node's
 * next pointer to getLinkedArraySize().
 *
 *
 * @since 2017-02-08
 * @author philip gust
 */

#ifndef LINKED_ARRAY_H_
#define LINKED_ARRAY_H_

/**
 * Singly linked array node
 * Note how "C" requires node next field to be declared
 */
typedef struct LinkedArrayNode {
	/** node data for a string array */
	char* data;
	/** link to next node */
	struct LinkedArrayNode* next;
	/** link to previous node */
	struct LinkedArrayNode* prev;
} LinkedArrayNode;

/**
 * Create and initialize new node.
 *
 * @param data the node data
 * @return Node with fields set to NULL
 */
LinkedArrayNode* createLinkedArrayNode(const char* data);

/**
 * Free node storage.  The node must be removed from its list
 * by calling deleteLinkedArrayNode() first.
 *
 * @param node the LinkedArrayNode to delete
 */
void deleteLinkedArrayNode(LinkedArrayNode* node);

/**
 * Returns first node in list, or NULL if list is NULL.
 *
 * @param the list of LinkedArrayNode
 * @return the first node in the list or NULL
 */
LinkedArrayNode* getFirstLinkedArrayNode(LinkedArrayNode *list);

/**
 * Returns last node in list, or NULL if list is NULL.
 *
 * @param the list of LinkedArrayNode
 * @return the last node in the list or NULL
 */
LinkedArrayNode* getLastLinkedArrayNode(LinkedArrayNode* list);

/**
 * Deletes all linked array nodes in the list.
 * @param node the starting linked array node
 */
void deleteAllLinkedArrayNodes(LinkedArrayNode *node);

/**
 * Return the size of the list. If the list has a dummy first node, pass
 * its next pointer to this function.
 *
 * @param list the list to be measured
 * @return the size of the list
 */
size_t getLinkedArraySize(LinkedArrayNode* list);

/**
 * Return the node at the Kth position relative to the input node.
 * If there are fewer than K items in the list, returns NULL.
 *
 * @param list the list to be measured
 * @return the Kth node from input node or NULL if fewer than K items
 */
LinkedArrayNode *getLinkedArrayNodeAt(LinkedArrayNode* list, size_t k);

/**
 * Return the index of the node in the node in the list.
 *
 * @param list the list to be measured
 * @param node the node to find
 * @return the index of the node in the list or SIZE_MAX if NULL or not in list
 */
 size_t getLinkedArrayNodeIndex(LinkedArrayNode* list, LinkedArrayNode *node);

 /**
  * Return the node at the Kth position relative to the input node.
  * If there are fewer than K items in the list, returns NULL.
  *
  * @param list the list
  * @param k the index
  * @param val the result parameter for  the value of the Kth node from input node
  * @return true if returned value of kth node as val, or false if index out of bounds
  */
 bool getLinkedArrayNodeValAt(LinkedArrayNode *list, size_t k, const char **val);

 /**
  * Return the node at the Kth position relative to the input node.
  * If there are fewer than K items in the list, returns NULL.
  *
  * @param list the list to be measured
  * @param k the index
  * @return true if set value of kth node as val, or false if index out of bounds
  */
 bool setLinkedArrayNodeValAt(LinkedArrayNode *list, size_t k, const char *val);

 /**
 * Add new node after the specified node in the list.
 *
 * @param list the list node after which new node will be added
 * @param the new node to insert
 */
void addAfterLinkedArrayNode(LinkedArrayNode* list, LinkedArrayNode* newNode);

/**
 * Delete node after specified list node. Caller is responsible for
 * freeing the deleted node by calling deleteLinkedArrayNode().
 *
 * @param the list node after which node will be deleted
 * @return the deleted node that the caller must free, or NULL if
 *   list has no next node
 */
LinkedArrayNode* deleteAfterLinkedArrayNode(LinkedArrayNode* list);

/**
 * Print the list data.
 *
 * @param list the list to print
 */
void printLinkedArrayNode(LinkedArrayNode *list);

#endif /* LINKED_ARRAY_H_ */
