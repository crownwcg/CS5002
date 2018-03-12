/*
 * tree_set.h
 *
 * This file provides the implementations of a ArraySet, which is
 * a Set that is backed by a sorted array list.  Inserting and
 * deleting a value requires moving the array beyond the position
 * down for insertion or up for deletion.
 *
 * The provided findArraySetKey() function locates the index for a
 * key in the sorted list. Either the key will be at the returned
 * index, or the returned index indicates where the key should be
 * added to the list for it to remain sorted. The function uses a
 * binary search mechanism similar to the binary search tree that
 * only requires time proportional to log(N) for a list of size N.
 *
 * Function used to implement addArraySetKey(), deleteArraySetKey(),
 * and containsArraySetKey().
 *
 * @since 2017-12-05
 * @author philip gust
 */

#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include "array_set.h"

/**
 * Find index of specified key in sorted list, or the position where
 * it should be added to remain sorted.
 *
 * Function assumes items are in ascending order, and uses a binary
 * search mechanism similar to a binary search tree to locate the
 * position.
 *
 * Algorithm works by finding midpoint between low and high indexes,
 * and determining which side of midpoint the key is or should be,
 * then repeats on that side.
 *
 * @param set the ArraySet
 * @param key the key to find
 * @return the index of the key, or where to insert the key if not present
 */
static size_t findArraySetKey(ArraySet* set, MapKey key) {
	// indicate position 0 for key if list is empty
	size_t size = getArraySetSize(set);
	if (size == 0) {
		return 0;
	}

	// start at two ends of list
	size_t low = 0;
	size_t high = size-1;

	// search region to determine which side of the midpoint
	// the value is or should be
	while (high >= low) {
		// compare key to value at midpoint
		size_t midpoint = (high+low)/2;
		MapKey midpointKey;
		if (getArrayListValAt(set->list, midpoint, &midpointKey)) {
			int cmp = strcmp(key, midpointKey);
			if (cmp == 0) {
				return midpoint;   // found value
			} else if (cmp < 0) {
				if (midpoint == 0) {
					return midpoint;
				}
				high = midpoint-1; // value is to left of midpoint
			} else {
				low = midpoint+1;  // value is to right of midpoint
			}
		}
	}
	return low;
}

/**
 * Create new empty ArraySet.
 *
 * @return a new ArraySet
 */
ArraySet *createArraySet(size_t initialCapacity, size_t maxCapacity) {
	// allocate memory and initiate the filed
	ArraySet *set = (ArraySet *) malloc(sizeof(ArraySet));
	set->list     = createArrayList(initialCapacity, maxCapacity);
	return set;
}

/**
 * Frees a ArraySet.
 *
 * @param set the ArraySet to free
 */
void deleteArraySet(ArraySet* set) {
	clearArraySet(set);
	deleteArrayList(set->list);
	set->list = NULL;
	free(set);
}

/**
 * Removes all of the keys from this set.
 *
 * @param set the ArraySet
 */
void clearArraySet(ArraySet* set) {
	deleteAllArrayListVals(set->list);
}

/**
 * Adds the specified key to this set if it is not already present.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the key was added, false otherwise
 */
bool addArraySetKey(ArraySet* set, MapKey key) {
	if (containsArraySetKey(set, key)) return false;
	return addArrayListValAt(set->list, findArraySetKey(set, key), key);
}

/**
 * Returns true if this set contains the specified key.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the set contains the key, false otherwise
 */
bool containsArraySetKey(ArraySet* set, MapKey key) {
	MapKey oldKey;
	if (getArrayListValAt(set->list, findArraySetKey(set, key), &oldKey))
		return strcmp(oldKey, key) == 0;
	return false;
}

/**
 * Removes the specified element from this set if it is present.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the key was removed, false otherwise
 */
bool deleteArraySetKey(ArraySet* set, MapKey key) {
	if (!containsArraySetKey(set, key)) return false;
	return deleteArrayListValAt(set->list, findArraySetKey(set, key));
}

/**
 * Returns the size of the set.
 *
 * @param set the ArraySet
 * @return the size of the ArraySet
 */
size_t getArraySetSize(ArraySet* set) {
	return arrayListSize(set->list);
}

/**
 * Returns true if this set contains no keys.
 *
 * @param set the ArraySet
 * @return true of the set is entry, false otherwise
 */
bool isArraySetEmpty(ArraySet* set) {
	return isArrayListEmpty(set->list);
}
