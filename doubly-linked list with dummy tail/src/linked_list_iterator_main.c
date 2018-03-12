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
#include "linked_list_iterator.h"


/**
 * This function exercises some of the linked list operations.
 */
int main(void) {
	printf("Initial list\n");
	LinkedList *list = createLinkedList();
	printLinkedList(list);
	printf("list size: %ld\n", linkedListSize(list));

	// add 4 nodes to the list
	printf("\nAdding 4 values to list\n");
	addLastLinkedListVal(list, "A");
	addLastLinkedListVal(list, "B");
	addLastLinkedListVal(list, "C");
	addLastLinkedListVal(list, "D");
	addLastLinkedListVal(list, "E");
	printLinkedList(list);

	printf("list size: %ld\n", linkedListSize(list));

	printf("\nTraversing list forward with iterator\n");
	LinkedListIterator *itr = createLinkedListIterator(list);
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));
	while (hasNextLinkedListIteratorVal(itr)) {
		const char *val;
		if (getNextLinkedListIteratorVal(itr, &val)) {
			printf("iterator next: \"%s\"\n", val);
		} else {
			printf("iterator next: unavailable\n");
		}
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nMoving back one from end with iterator\n");
	printf("iterator has prev: %s\n", hasPrevLinkedListIteratorVal(itr) ? "true" : "false");
	const char *val;
	if (getPrevLinkedListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nMoving forward one to end with iterator\n");
	if (getNextLinkedListIteratorVal(itr, &val)) {
		printf("iterator next: \"%s\"\n", val);
	} else {
		printf("iterator next: unavailable\n");
	}
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nResetting iterator\n");
	resetLinkedListIterator(itr);
	printf("iterator has next: %s\n", hasNextLinkedListIteratorVal(itr) ? "true" : "false");
	printf("iterator count: %ld\n", getLinkedListIteratorCount(itr));
	printf("iterator avail: %ld\n", getLinkedListIteratorAvailable(itr));

	printf("\nTrying to move back one from beginning with iterator\n");
	printf("iterator has prev: %s\n", hasPrevLinkedListIteratorVal(itr) ? "true" : "false");
	if (getPrevLinkedListIteratorVal(itr, &val)) {
		printf("iterator prev: \"%s\"\n", val);
	} else {
		printf("iterator prev: unavailable\n");
	}

	return EXIT_SUCCESS;
}

