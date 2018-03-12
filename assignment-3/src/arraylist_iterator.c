/*
 * linked_list_iterator_alt.c
 *
 * This file provides implements the functions of an iterator
 * for a singly linked list.
 *
 * Alternate implementation initializes the iterator curNode to the
 * dummy head node rather than to the first array node in the list.
 * This implementation is better when using a doubly-linked array
 * because at the end of forward iteration, curNode points to the
 * last node in the list, rather than to NULL. This simplifies
 * backward iteration using the linked array node back pointer.
 *
 *
 * @since 2017-11-03
 * @author philip gust
 */

#include <stdlib.h>
#include <stdbool.h>

#include "arraylist_iterator.h"

/**
 * Value returned by getArrayListIteratorAvailable if count unavailable.
 */
const size_t UNAVAILABLE = SIZE_MAX;

/**
 * Create and initialize new iterator.
 *
 * @param theList the ArrayList to iterate
 * @return an iterator for the list
 */
ArrayListIterator* createArrayListIterator(ArrayList *theList) {
	ArrayListIterator* itr = malloc(sizeof(ArrayListIterator));

	itr->theList = theList;
	itr->curNode = 0;
	itr->count   = 0;

	return itr;
}

/**
 * Delete the iterator by freeing its storage.
 *
 * @param itr the ArrayListIterator to delete
 */
void deleteArrayListIterator(ArrayListIterator* itr) {
	itr->count = 0;
	itr->curNode = 0;
	itr->theList = NULL;
	free(itr);
}

/**
 * Gets next link value in the linked list.
 *
 * @param itr the ArrayListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if next value returned, false if iterator is at end of list
 */
 bool getNextArrayListIteratorVal(ArrayListIterator* itr, const char **val) {
	if (hasNextArrayListIteratorVal(itr)) {
		if (getArrayListValAt(itr->theList, itr->curNode, val)) {
			itr->curNode++;
			itr->count++;
			return true;
		}
	}
	return false;
}

/**
 * Determines whether there is another value in the linked list.
 *
 * @param itr the ArrayListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextArrayListIteratorVal(ArrayListIterator* itr) {
	return itr->curNode < itr->theList->size;
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
 * @param itr the ArrayListIterator
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return true if previous value returned, false if iterator is at
 *  the start of list
 */
bool getPrevArrayListIteratorVal(ArrayListIterator* itr, const char **val) {
	if (hasPrevArrayListIteratorVal(itr)) {
		if (getArrayListValAt(itr->theList, itr->curNode - 1, val)) {
			itr->curNode--;
			itr->count--;
			return true;
		}
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
 * @param itr the ArrayListIterator
 * @return true if there is a previous value, false otherwise
 */
bool hasPrevArrayListIteratorVal(ArrayListIterator* itr) {
	return itr->curNode > 0;
}

/**
 * Resets the linked list iterator to the start of the list.
 *
 * @param itr the ArrayListIterator
 * @return true if successful, false if not supported
 */
bool resetArrayListIterator(ArrayListIterator* itr) {
	itr->curNode = 0;
	itr->count = 0;
	return true;
}

/**
 * Returns the number of values returned so far.
 *
 * @param itr the ArrayListIterator
 * @return the number of values returned so far
 */
size_t getArrayListIteratorCount(ArrayListIterator* itr) {
	return itr->count;
}


/**
 * Returns the number of values available.
 *
 * @param itr the ArrayListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getArrayListIteratorAvailable(ArrayListIterator* itr) {
	return itr->theList->size - itr->count;
}
