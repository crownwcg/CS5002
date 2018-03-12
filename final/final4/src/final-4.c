/*
 * final-4.c
 *
 * This problem tests your understanding queues by asking you
 * to implement a queue using a circular linked list as a backing
 * store. With a circular linked list, the last node points back
 * to the first node.
 *
 * The LinkedQueue struct has a pointer to the tail of the list.
 * The tail node's next link points to the list head. This will
 * eliminate the need to store both a list head for dequeueing
 * a node and the list tail for enqueueing it.
 *
 *                        last
 * [LinkedQueue]------------------------------.
 *                                            v
 *      [LinkedListNode]-->[LinkedListNode]-->[LinkedListNode]--.
 *      ^                                                       |
 *      |_______________________________________________________|
 *                        next
 *
 *  Implement the LinkedQueue functions in linked_queue.c.
 *
 *  CS 5002 Fall 2017 Silicon Valley
 *  Final Problem 4
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_queue.h"

/**
 * Print the queue nodes values
 *
 * @param queue the linked queue to print.
 */
void printLinkedQueue(LinkedQueue *queue) {
	if (queue->last != NULL) {
		LinkedListNode *nextNode = queue->last->next;  // first node
		LinkedListNode *node;
		do {
			node = nextNode;
			nextNode = node->next;
			printf("%s ", (char*)node->data);
		} while (node != queue->last);
		printf("\n");
	}
}

/**
 * Test functions.
 */
int main(void) {
	printf("***Starting problem #4\n");

	LinkedQueue *queue = createLinkedQueue();
	bool empty = isLinkedQueueEmpty(queue);
	printf("queue empty? %s\n", empty ? "true" : "false");
	size_t size = linkedQueueSize(queue);
	printf("queue size: %ld\n", size);

	printf("\nadding 5 values\n");
	enqueueLinkedQueueVal(queue, "A");
	enqueueLinkedQueueVal(queue, "B");
	enqueueLinkedQueueVal(queue, "C");
	enqueueLinkedQueueVal(queue, "D");
	enqueueLinkedQueueVal(queue, "E");
	empty = isLinkedQueueEmpty(queue);
	printf("queue empty? %s\n", empty ? "true" : "false");
	size = linkedQueueSize(queue);
	printf("queue size: %ld\n", size);
	printLinkedQueue(queue);

	void *val;
	bool status = peekLinkedQueueVal(queue, &val);
	if (status) {
		printf("\npeek value: %s\n", (char*)val);
	} else {
		printf("\ncannot peek at top\n");
	}

	status = pokeLinkedQueueVal(queue, "Z");
	if (status) {
		printf("\npoked top: Z\n");
		printLinkedQueue(queue);
	} else {
		printf("\ncannot poke top\n");
	}

	status = dequeueLinkedQueueVal(queue, &val);
	if (status) {
		printf("\ndropped top\n");
		printLinkedQueue(queue);
	} else {
		printf("\ncannot drop top\n");
	}

	empty = isLinkedQueueEmpty(queue);
	printf("\nqueue empty? %s\n", empty ? "true" : "false");
	size = linkedQueueSize(queue);
	printf("queue size: %ld\n", size);

	printf("\ndropping all linked queue values\n");
	clearLinkedQueue(queue);
	empty = isLinkedQueueEmpty(queue);
	printf("queue empty? %s\n", empty ? "true" : "false");
	size = linkedQueueSize(queue);
	printf("queue size: %ld\n", size);
	printLinkedQueue(queue);

	printf("\ndeleting linked queue\n");
	deleteLinkedQueue(queue);

	printf("\n***Ending problem #4\n");

	return EXIT_SUCCESS;
}
