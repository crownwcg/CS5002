/*
 * final-5.c
 *
 * This problem tests your understanding of sets by implementing
 * an ArraySet that is backed by a sorted ArrayList. The set uses
 * a binary search mechanism similar to the binary search tree that
 * only requires time proportional to log(N) for a list of size N.
 *
 * You will implement the ArraySet functions in array_set.c, using
 * the provided binary search function that locates the position of
 * a key in the sorted list or where the key should be inserted to
 * ensure that the list remains sorted.
 *
 *  CS 5002 Fall 2017 Silicon Valley
 *  Final Problem 5
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_set.h"

/**
 * Create an ArraySet with the specified entries.
 * @param entries the entry array
 */
static ArraySet* makeArraySet(MapKey *entries, int nEntries) {
	ArraySet* set = createArraySet(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);

	for (int i = 0; i < nEntries; i++) {
		addArraySetKey(set, entries[i]);
	}

	return set;
}

/**
 * Test ArraySet functions.
 */
int main(void) {
	printf("***Starting problem #5\n");

	MapKey entries[] = {
		"key3","key1", "key4", "key2"
	};
	size_t nEntries = 4;
	ArraySet* set = makeArraySet(entries, nEntries);
	size_t size = getArraySetSize(set);
	printf("\nSet size: %lu, expected %lu\n", size, nEntries);

	// test all keys present
	printf("\nTesting all entries present\n");
	bool err = false;
	for (int i = 0; i < nEntries; i++) {
		if (!containsArraySetKey(set, entries[i])) {
			err = true;
			printf("Set does not contain key %s\n", entries[i]);
		}
	}
	if (!err) {
		printf("All entries present\n");
	}

	printf("\nTesting for '%s'\n", "unknownKey");
	if (containsArraySetKey(set, "unknownKey")) {
		printf("Set should not contain key %s\n", "unknownKey");
	} else {
		printf("Set did not contain key %s\n", "unknownKey");

	}
	// test adding duplicate keys
	printf("\nTesting adding duplicate keys\n");
	err = false;
	for (int i = 0; i < nEntries; i++) {
		if (addArraySetKey(set, entries[i])) {
			err = true;
			printf("Should not have been able to add key %s\n", entries[i]);
		}
	}
	if (!err) {
		printf("Unable to add duplicate keys\n");
	}

	// test deleting all keys
	printf("\nTesting deleting all keys\n");
	err = false;
	for (int i = 0; i < nEntries; i++) {
		if (!deleteArraySetKey(set, entries[i])) {
			err = true;
			printf("Could not delete key %s\n", entries[i]);
		}
	}
	if (!err) {
		printf("Deleted all keys keys\n");
	}

	printf("\nTesting whether set is empty.\n");
	if (!isArraySetEmpty(set)) {
		size = getArraySetSize(set);
		printf("Expected ArraySet to be empty: was size %lu\n", size);
	} else {
		printf("Set is empty\n");
	}

	printf("\n***Ending problem #5\n");

	return EXIT_SUCCESS;
}
