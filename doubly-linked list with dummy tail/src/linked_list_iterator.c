/*
 * linked_list_iterator.c
 *
 * This file provides implements the functions of an iterator
 * for a singly linked list.
 *
 * @since 2017-02-14
 * @author philip gust
 */

#include <stdlib.h>
#include <stdbool.h>
#include "linked_list_iterator.h"

/**
 * Value returned by getLinkedListIteratorAvailable if count unavailable.
 */
const size_t UNAVAILABLE = SIZE_MAX;

/**
 * Create and initialize new iterator.
 *
 * @param theList the LinkedList to iterate
 * @return an iterator for the list
 */
LinkedListIterator* createLinkedListIterator(LinkedList *theList) {
	LinkedListIterator* itr = (LinkedListIterator*)malloc(sizeof(LinkedListIterator));

	itr->theList = theList;
	itr->curNode = theList->head.next;
	itr->count = 0;

	return itr;
}

/**
 * Delete the iterator by freeing its storage.
 *
 * @param itr the LinkedListIterator to delete
 */
void deleteLinkedListIterator(LinkedListIterator* itr) {
	itr->count = UNAVAILABLE;
	itr->curNode = NULL;
	itr->theList = NULL;
	free(itr);
}

/**
 * Gets next link value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if next value returned, false if iterator is at end of list
 */
 bool getNextLinkedListIteratorVal(LinkedListIterator* itr, const char **val) {
	if (hasNextLinkedListIteratorVal(itr)) {
		LinkedArrayNode* node = itr->curNode;
		if (node->data != NULL) {
			itr->curNode = node->next;
			itr->count++;
			*val = node->data;
			return true;
		}
	}
	return false;
}

/**
 * Determines whether there is another value in the linked list.
 *
 * @param itr the LinkedListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextLinkedListIteratorVal(LinkedListIterator* itr) {
	return itr->count < itr->theList->size;
}

/**
 * Gets previous link value in the linked list.
 *
 * The previous value is the one prior to the value returned by a
 * call to getNextLinkListVal(). In other words, it is the value
 * returned by the last call to getNextLinkListVal(). The count
 * will be decremented by 1, so that the sum of the count and the
 * available values is the length of list. If the iterator is at
 * the beginning of the list, there is no previous value.
 *
 * @param itr the LinkedListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if previous value returned, false if iterator is at end of list
 */
bool getPrevLinkedListIteratorVal(LinkedListIterator* itr, const char **val) {
	if (hasPrevLinkedListIteratorVal(itr)) {
		LinkedArrayNode* node = itr->curNode->prev;
		itr->count--;
		itr->curNode = node;
		*val = node->data;
		return true;
	}
	return false;
}

/**
 * Determines whether there is a previous value in the linked list.
 *
 * The previous value is the one prior to the value returned by a call
 * to getNextLinkListVal(). In other words, it is the value returned
 * by the last call to getNextLinkListVal(). If the iterator is at
 * the beginning of the list, there is no previous value.
 *
 * @param itr the LinkedListIterator
 * @return true if there is a previous node, false otherwise
 */
bool hasPrevLinkedListIteratorVal(LinkedListIterator* itr) {
	return itr->count > 0;
}

/**
 * Resets the linked list iterator to the head of the list.
 *
 * @param itr the LinkedListIterator
 * @return true if successful, false if not supported
 */
bool resetLinkedListIterator(LinkedListIterator* itr) {
	itr->curNode = itr->theList->head.next;
	itr->count = 0;
	return true;
}

/**
 * Returns the number of values returned so far.
 *
 * @param itr the LinkedListIterator
 * @return the number of values returned so far
 */
size_t getLinkedListIteratorCount(LinkedListIterator* itr) {
	return itr->count;
}


/**
 * Returns the number of values available.
 *
 * @param itr the LinkedListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getLinkedListIteratorAvailable(LinkedListIterator* itr) {
	if (itr->count != UNAVAILABLE) {
		return itr->theList->size - itr->count;
	}
	return UNAVAILABLE;
}
