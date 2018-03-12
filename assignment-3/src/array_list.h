/*
 * array_list.h
 *
 *  Created on: Oct 30, 2017
 *      Author: phil
 */

#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include <stdbool.h>
#include <stdlib.h>

/** Array List data structure */
typedef struct {
	/** Allocated array storage */
	char** vals;
	/** The current size */
	size_t size;
	/** Capacity of allocated array */
	size_t capacity;
	/** Max allocated capacity */
	size_t maxCapacity;
} ArrayList;

/** Default maximum capacity for array is unlimited */
extern const size_t DEFAULT_MAX_CAPACITY;

/** Default capacity for array */
extern const size_t DEFAULT_CAPACITY;

/**
 * Create an array list with an initial capacity and max capacity.
 *
 * @param initialCapacity initial capacity of the ArrayList.
 *     Use DEFAULT_CAPACITY for default
 * @param maxCapacity maximum capacity of ArrayList.
 *     Use DEFAULT_MAX_CAPACITY for unlimited capacity
 * @return the allocated array list
 */
ArrayList *createArrayList(size_t initialCapacity, size_t maxCapacity);

/**
 * Add value to list at index. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addArrayListValAt(ArrayList *list, size_t index, const char *val);

/**
 * Add value to start of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addFirstArrayListVal(ArrayList *list, const char *val);

	/**
 * Add value to end of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addLastArrayListVal(ArrayList *list, const char *val);

/**
 * Get value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getArrayListValAt(ArrayList *list, size_t index, const char **val);

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getFirstArrayListVal(ArrayList *list, const char **val);

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getLastArrayListVal(ArrayList *list, const char **val);

/**
 * Set value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds or value is null
 */
bool setArrayListValAt(ArrayList *list, size_t index, const char *val);

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if list is empty
 */
bool setFirstArrayListVal(ArrayList *list, const char *val);

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val value to setresult value location;
 *   cannot be null
 * @return false if list is empty
 */
bool setLastArrayListVal(ArrayList *list, const char *val);

/**
 * Returns number of items in the array list.
 * @param list the array list
 * @return the number of items in the array list.
 */
size_t arrayListSize(ArrayList *list);

/**
 * Determines whether array list is empty.
 * @param list the array list
 * @return true if array list is empty, false otherwise
 */
bool isArrayListEmpty(ArrayList *list);

/**
 * Delete the array list value at the specified index.
 * @param list the array list
 * @param index the index
 * @return if index out of bounds
 */
bool deleteArrayListValAt(ArrayList *list, size_t index);

/**
 * Delete the fist array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteFirstArrayListVal(ArrayList *list);

/**
 * Delete the last array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteLastArrayListVal(ArrayList *list);

/**
 * Deletes all array list values.
 * @param list the array list
 */
void deleteAllArrayListVals(ArrayList *list) ;


/**
 * Delete the array list . Frees copies of all strings,
 * then the array list, and finally the list itself.
 * Strongly recommend resetting all struct fields to
 * default {NULL, 0, 0, 0} before freeing struct in case
 * this function is called twice with same array list
 *
 * @param list the array list
 */
void deleteArrayList(ArrayList *list);

void printArrayList(ArrayList *list);


#endif /* ARRAY_LIST_H_ */
