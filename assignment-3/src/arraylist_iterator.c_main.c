/*
 * linked_list_iterator_main.c
 *
 * This file exercises the singly linked list and singly linked list
 * iterators functions.
 *
 * @since 2017-02-14
 * @author philip gust
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "arraylist_iterator.h"

/**
 * This function exercises some of the linked list operations.
 */
int main(void) {
	printf("Initial list\n");
	ArrayList *list = createArrayList(4, 8);
	printArrayList(list);
	printf("list size: %ld\n", arrayListSize(list));

	// add 4 nodes to the list
	printf("\nAdding 4 values to list\n");
	addLastArrayListVal(list, "A");
	addLastArrayListVal(list, "B");
	addLastArrayListVal(list, "C");
	addLastArrayListVal(list, "D");
	addLastArrayListVal(list, "E");
	printArrayList(list);

	printf("list size: %ld\n", arrayListSize(list));

	printf("\nTraversing list forward with iterator\n");
	ArrayListIterator *itr = createArrayListIterator(list);
	printf("iterator count: %ld\n", getArrayListIteratorCount(itr));
	printf("iterator avail: %ld\n", getArrayListIteratorAvailable(itr));
	while (hasNextArrayListIteratorVal(itr)) {
		const char *val;
		if (getNextArrayListIteratorVal(itr, &val)) {
			printf("iterator next: \"%s\"\n", val);
		} else {
			printf("iterator next: unavailable\n");
		}
	}
	printf("iterator count: %ld\n", getArrayListIteratorCount(itr));
	printf("iterator avail: %ld\n", getArrayListIteratorAvailable(itr));

	printf("\nMoving back one from end with iterator\n");
	printf("iterator has prev: %s\n", hasPrevArrayListIteratorVal(itr) ? "true" : "false");
	const char *val;
	if (getPrevArrayListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}
	printf("iterator count: %ld\n", getArrayListIteratorCount(itr));
	printf("iterator avail: %ld\n", getArrayListIteratorAvailable(itr));

	printf("\nMoving forward one to end with iterator\n");
	if (getNextArrayListIteratorVal(itr, &val)) {
		printf("iterator next: \"%s\"\n", val);
	} else {
		printf("iterator next: unavailable\n");
	}
	printf("iterator count: %ld\n", getArrayListIteratorCount(itr));
	printf("iterator avail: %ld\n", getArrayListIteratorAvailable(itr));

	printf("\nResetting iterator\n");
	resetArrayListIterator(itr);
	printf("iterator has next: %s\n", hasNextArrayListIteratorVal(itr) ? "true" : "false");
	printf("iterator count: %ld\n", getArrayListIteratorCount(itr));
	printf("iterator avail: %ld\n", getArrayListIteratorAvailable(itr));

	printf("\nTrying to move back one from beginning with iterator\n");
	printf("iterator has prev: %s\n", hasPrevArrayListIteratorVal(itr) ? "true" : "false");
	if (getPrevArrayListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}

	return EXIT_SUCCESS;
}

