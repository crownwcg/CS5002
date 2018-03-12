/*
 * array_list.c
 *
 * Code example of ArrayList for lecture 2.
 *
 *  Created on: Oct 24, 2017
 *  Author: philip gust
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"


/** Default maximum capacity for array is unlimited */
const size_t DEFAULT_MAX_CAPACITY = SIZE_MAX;

/** Default capacity for array */
const size_t DEFAULT_CAPACITY = 4;

/**
 * Create an array list with an initial capacity and max capacity.
 *
 * @param initialCapacity initial capacity of the ArrayList.
 *     Use DEFAULT_CAPACITY for default
 * @param maxCapacity maximum capacity of ArrayList.
 *     Use DEFAULT_MAX_CAPACITY for unlimited capacity
 * @return the allocated array list
 */
ArrayList *createArrayList(size_t initialCapacity, size_t maxCapacity) {
	ArrayList *list = malloc(sizeof(ArrayList));
	list->size = 0;
	list->capacity = initialCapacity;
	list->maxCapacity = maxCapacity;
	list->vals = malloc(list->capacity * sizeof(char*));

	return list;
}

/**
 * Add value to list at index. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addArrayListValAt(ArrayList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (val == NULL) {
		return false;
	}

	// beyond end of list
	if (index > list->size) {
		return false;
	}

	// need to grow array if size is at capacity
	if (list->size == list->capacity) {
		// done if already at maxCapacity
		if (list->size == list->maxCapacity) {
			return false;
		}

		// double capacity
		size_t newCapacity = list->capacity * 2;

		// if over, use maxCapacity
		if (newCapacity > list->maxCapacity) {
			newCapacity = list->maxCapacity;
		}

		// realloc memory to new capacity
		list->capacity = newCapacity;
		list->vals = realloc(list->vals, newCapacity * sizeof(char*));
	}

	// copy array down to make room at index position
	for (int p = list->size; p > index; p--) {
		list->vals[p] = list->vals[p-1];
	}

	// add copy of value at index position
	list->size++;
	list->vals[index] = strdup(val);  // must copy input string

	return true;
}

/**
 * Add value to start of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addFirstArrayListVal(ArrayList *list, const char *val) {
	 return addArrayListValAt(list, 0, val);
 }

/**
 * Add value to end of list. Cannot add NULL string to the list.
 * @param list the ArrayList
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if index out of bounds or exceeds max capacity
 */
bool addLastArrayListVal(ArrayList *list, const char *val) {
	 return addArrayListValAt(list, list->size, val);
 }

/**
 * Get value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if index out of bounds
 */
bool getArrayListValAt(ArrayList *list, size_t index, const char **val) {
	if (index <= list->size-1) {
		*val = list->vals[index];
		return true;
	}
	return false;
}

/**
 * Get value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getFirstArrayListVal(ArrayList *list, const char **val) {
	return getArrayListValAt(list, 0, val);
}

/**
 * Get value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if list is empty
 */
bool getLastArrayListVal(ArrayList *list, const char **val) {
	if (list->size == 0) {
		return NULL;
	}
	return getArrayListValAt(list, list->size-1, val);
}


/**
 * Set value at index.
 * @param list the ArrayList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if index out of bounds or value is null
 */
bool setArrayListValAt(ArrayList *list, size_t index, const char *val) {
	// cannot add NULL to list
	if (val == NULL) {
		return false;
	}
	if (index <= list->size-1) {
		free(list->vals[index]);
		list->vals[index] = strdup(val);
		return true;
	}
	return false;
}

/**
 * Set value at first index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val the value to set; cannot be null
 * @return false if list is empty
 */
bool setFirstArrayListVal(ArrayList *list, const char *val) {
	return setArrayListValAt(list, 0, val);
}

/**
 * Set value at last index.
 * @param list the LinkedList
 * @param the index for the new value
 * @param val value to setresult value location;
 *   cannot be null
 * @return false if list is empty
 */
bool setLastArrayListVal(ArrayList *list, const char *val) {
	if (list->size == 0) {
		return false;
	}
	return setArrayListValAt(list, list->size-1, val);
}

/**
 * Returns number of items in the array list.
 * @param list the array list
 * @return the number of items in the array list.
 */
size_t arrayListSize(ArrayList *list) {
    return list->size;
}

/**
 * Determines whether array list is empty.
 * @param list the array list
 * @return true if array list is empty, flase otherwise
 */
bool isArrayListEmpty(ArrayList *list) {
	return list->size == 0;
}

/**
 * Delete the array list value at the specified index.
 * @param list the array list
 * @param index the index
 * @return if index out of bounds
 */
bool deleteArrayListValAt(ArrayList *list, size_t index) {
	if (index >= list->size) {
		return false;
	}

	// free string before overwriting location
	free(list->vals[index]);

	// move elements down
	list->size--;
	for (int i = index; i < list->size; i++) {
		// move string down
		list->vals[i] = list->vals[i+1];
	}

	return true;
}

/**
 * Delete the first array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteFirstArrayListVal(ArrayList *list) {
	return deleteArrayListValAt(list, 0);
}

/**
 * Delete the last array list value.
 * @param list the array list
 * @return if list is empty
 */
bool deleteLastArrayListVal(ArrayList *list) {
	return deleteArrayListValAt(list, list->size-1);
}


/**
 * Deletes all array list values.
 * @param list the array list
 */
void deleteAllArrayListVals(ArrayList *list) {
	for (int i = 0; i < list->size; i++) {
		free(list->vals[i]);
		list->vals[i] = NULL;
	}
	list->size = 0;
}

/**
 * Delete the array list. Frees copies of all strings,
 * then the array list, and finally the list itself.
 * Strongly recommend resetting all struct fields to
 * default {NULL, 0, 0, 0} before freeing struct in case
 * this function is called twice with same array list
 *
 * @param list the array list
 */
void deleteArrayList(ArrayList *list) {
	// free the strings in the array
	deleteAllArrayListVals(list);

	// free the list array
	free(list->vals);
	list->vals = NULL;

	// free the list itself
	free(list);

}

void printArrayList(ArrayList *list) {
	char *c = "";
	printf("(");
	for (int i = 0; i < list->size; i++) {
		const char *val;
		getArrayListValAt(list, i, &val);
		printf("%s\"%s\"", c, val);
		c = ", ";
	}
	printf(")\n");
}
