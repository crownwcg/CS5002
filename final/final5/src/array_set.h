/*
 * array_set.h
 *
 * This file provides the structures and function declarations of a ArraySet,
 * which is a set that is backed by a HashMap
 *
 * @since 2017-12-05
 * @author philip gust
 */

#ifndef ARRAY_SET_H_
#define ARRAY_SET_H_

#include <stdlib.h>
#include <stdbool.h>
#include "array_list.h"

/**
 * Type of the map key.
 */
typedef const char* MapKey;

/**
 * Structure that defines a ArraySet. All entries are private
 */
typedef struct {
	ArrayList *list;
} ArraySet;

/**
 * Create new empty ArraySet.
 */
ArraySet* createArraySet(size_t initialCapacity, size_t maxCapacity);

/**
 * Frees a ArraySet.
 *
 * @param set the ArraySet to free
 */
void deleteArraySet(ArraySet* set);

/**
 * Removes all of the keys from this set.
 *
 * @param set the ArraySet
 */
void clearArraySet(ArraySet* set);

/**
 * Adds the specified key to this set if it is not already present.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the key was added, false otherwise
 */
bool addArraySetKey(ArraySet* set, MapKey key);

/**
 * Returns true if this set contains the specified key.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the set contains the key, false otherwise
 */
bool containsArraySetKey(ArraySet* set, MapKey key);

/**
 * Returns true if this set contains all the keys from the other set.
 *
 * @param set the ArraySet
 * @param otherSet the other ArraySet
 * @return true if the set contains all the keys, false otherwise
 */
bool containsAllArraySetKeys(ArraySet* set, ArraySet* otherSet);

/**
 * Returns true if this set contains no keys.
 *
 * @param set the ArraySet
 * @return true of the set is entry, false otherwise
 */
bool isArraySetEmpty(ArraySet* set);

/**
 * Returns the size of the set.
 *
 * @param set the ArraySet
 * @return the size of the ArraySet
 */
size_t getArraySetSize(ArraySet* set);

/**
 * Removes the specified element from this set if it is present.
 *
 * @param set the ArraySet
 * @param key the entry key to check
 * @return true if the key was removed, false otherwise
 */
bool deleteArraySetKey(ArraySet* set, MapKey key);

#endif /* ARRAY_SET_H_ */
