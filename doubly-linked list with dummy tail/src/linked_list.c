/*
 * linked_list.c
 *
 * This file implements a singly linked list if strings.
 *
 * @since 2017-02-08
 * @author philip gust
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "linked_list.h"
#include "linked_array.h"

/**
 * Create and initialize a new linked list
 * @return the new linked list
 */
LinkedList *createLinkedList(void) {
	LinkedList *list = malloc(sizeof(LinkedList));
	list->size = 0;
	list->head.next = &list->tail;
	list->head.prev = NULL;
	list->head.data = NULL;
	list->tail.next = NULL;
	list->tail.prev = &list->head;
	list->tail.data = NULL;

	return list;
}

/**
 * Add value to list at index. Cannot add NULL string to the list.
 * @param list the LinkedList
 * @param index the index for the new value
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addLinkedListValAt(LinkedList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (val == NULL) {
		return false;
	}
	// find node to insert after
	LinkedArrayNode *node = getLinkedArrayNodeAt(&list->head, index);
	if (node == NULL) {
		return false;
	}

	// create and add new node
	LinkedArrayNode *newNode = createLinkedArrayNode(val);
	addAfterLinkedArrayNode(node, newNode);
	list->size++;

	return true;
}

/**
 * Add value to start of list. Cannot add NULL string to the list.
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addFirstLinkedListVal(LinkedList *list, const char *val) {
	return addLinkedListValAt(list, 0, val);
}

/**
 * Add value to end of list. Cannot add NULL string to the list.
 * @param list the LinkedList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addLastLinkedListVal(LinkedList *list, const char *val) {
	return addLinkedListValAt(list, list->size, val);
}

/**
 * Get value at index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLinkedListValAt(LinkedList *list, size_t index, const char **val) {
	return getLinkedArrayNodeValAt(list->head.next, index, val);
}

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getFirstLinkedListVal(LinkedList *list, const char **val) {
	return getLinkedListValAt(list, 0, val);
}

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getLastLinkedListVal(LinkedList *list, const char **val) {
	if (list->size == 0) {
		return NULL;
	}
	return getLinkedListValAt(list, list->size-1, val);
}

/**
 * Set value at index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds or value is null
 */
bool setLinkedListValAt(LinkedList *list, size_t index, const char *val) {
	if (val == NULL) {
		return false;
	}
	return setLinkedArrayNodeValAt(list->head.next, index, val);
}

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds
 */
bool setFirstLinkedListVal(LinkedList *list, const char *val) {
	return setLinkedListValAt(list, 0, val);
}

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds
 */
bool setLastLinkedListVal(LinkedList *list, const char *val) {
	if (list->size == 0) {
		return false;
	}
	return setLinkedListValAt(list, list->size-1, val);
}

/**
 * Returns number of items in the linked list.
 * @param list the linked list
 * @return the number of items in the linked list.
 */
size_t linkedListSize(LinkedList *list) {
    return list->size;
}

/**
 * Determines whether linked list is empty.
 * @param list the linked list
 * @return true if linked list is empty, flase otherwise
 */
bool isLinkedListEmpty(LinkedList *list) {
	return list->size == 0;
}

/**
 * Delete the linked list value at the specified index.
 * @param list the linked list
 * @param index the index
 * @return if index out of bounds
 */
bool deleteLinkedListValAt(LinkedList *list, size_t index) {
	// node before one to delete
	LinkedArrayNode *node = getLinkedArrayNodeAt(&list->head, index);
	if (node != NULL) {
		// delete node from linked array
		node = deleteAfterLinkedArrayNode(node);
		if (node != NULL) {
			// free node and decrement count if deleted
			deleteLinkedArrayNode(node);
			list->size--;
			return true;
		}
	}
	return false;
}

/**
 * Delete the first linked list value.
 * @param list the linked list
 * @return false if list is empty
 */
bool deleteFirstinkedListVal(LinkedList *list) {
	return deleteLinkedListValAt(list, 0);
}

/**
 * Delete the last linked list value.
 * @param list the linked list
 * @return false if list is empty
 */
bool deleteLastLinkedListVal(LinkedList *list) {
	if (list->size == 0) {
		return false;
	}
	return deleteLinkedListValAt(list, list->size-1);
}

/**
 * Deletes all linked list values.
 * @param node the starting linked array node
 */
void deleteAllLinkedListVals(LinkedList *list) {
	deleteAllLinkedArrayNodes(list->head.next);
	list->head.next = &list->tail;
	list->tail.prev = &list->head;

	list->size = 0;
}

/**
 * Delete the linked list . Frees copies of all strings,
 * then the linked array, and finally the list itself.
 *
 * @param list the linked list
 */
void deleteLinkedList(LinkedList *list) {
	deleteAllLinkedListVals(list);
	free(list);
}

/**
 * Print the linked list.
 * @param list the linked list
 */
void printLinkedList(LinkedList *list) {
	printLinkedArrayNode(&list->head);
}
