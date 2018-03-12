/*
 * linked_queue.c
 *
 * This file implements a generic linked queue.
 *
 *  Created on: Dec 5, 2017
 *  Author: philip gust
 */
#include <stdbool.h>
#include <stdlib.h>
#include "linked_queue.h"

/**
 * Create an linked list node with a specific value.
 *
 * @return the allocated linked list node
 */
static LinkedListNode *createNode(void *val) {
	// allocate memory and initiate the filed
	LinkedListNode *node = (LinkedListNode *) malloc(sizeof(LinkedListNode));
	node->data = val;
	node->next = node;
	return node;
}

/**
 * Delete the linked list node.
 *
 * @param node node to delete
 */
static void deleteNode(LinkedListNode *node) {
	if (node != NULL) {
		node->data = NULL;
		node->next = NULL;
		free(node);
	}
}

/**
 * Create an linked queue with an initial capacity and max capacity.
 *
 * @return the allocated linked queue
 */
LinkedQueue *createLinkedQueue(void) {
	// allocate memory and initiate the fileds.
	LinkedQueue *q = (LinkedQueue *) malloc(sizeof(LinkedQueue));
	q->last = NULL;
	q->size = 0;
	return q;
}

/**
 * Delete the linked queue by first clearing it, then
 * freeing its storae.
 *
 * @param queue the linked queue
 */
void deleteLinkedQueue(LinkedQueue *queue) {
	clearLinkedQueue(queue);
	queue->last = NULL;
	queue->size = 0;
	free(queue);
}

/**
 * Clear linked queue values.
 * @param list the array list
 */
void clearLinkedQueue(LinkedQueue *queue) {
	if (queue != NULL) {
		// dequeue every element to clear the queue
		void *val;
		while (!isLinkedQueueEmpty(queue)) {
			dequeueLinkedQueueVal(queue, &val);
		}
	}
}

/**
 * Add value to th queue. Cannot add NULL string to the queue.
 * @param queue the LinkedQueue
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueLinkedQueueVal(LinkedQueue *queue, void *val) {
	if (queue == NULL) return false;
	// create node with value
	LinkedListNode *node = createNode(val);
	if (queue->last == NULL) {
		// if the last node is NULL, new node is the last node
		queue->last = node;
	} else {
		// record the first node,
		// update the last node's next ndoe is new node
		// update the new node's next node is the first node.
		// update the queue's last node
		LinkedListNode *first = queue->last->next;
		queue->last->next     = node;
		node->next    = first;
		queue->last   = node;
	}
	queue->size++;
	return true;
}

/**
 * Get the top Queue value without removing it.
 * @param queue the LinkedQueue
 * @param val result parameter is pointer to result value location
 * @return false if queue is empty
 */
bool peekLinkedQueueVal(LinkedQueue *queue, void **val) {
	if (queue == NULL || isLinkedQueueEmpty(queue)) return false;
	if (val != NULL) *val = queue->last->next->data;
	return true;
}

/**
 * Set the queue top to a new value.
 * @param queue the LinkedQueue
 * @param val the value to set
 * @return false if the queue is empty
 */
bool pokeLinkedQueueVal(LinkedQueue *queue, void *val) {
	if (queue == NULL || isLinkedQueueEmpty(queue)) return false;
	if (val != NULL) queue->last->next->data = val;
	return true;
}

/**
 * Delete the linked queue value at the specified index.
 * @param queue the linked queue
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if Queue is empty
 */
bool dequeueLinkedQueueVal(LinkedQueue *queue, void **val) {
	if (queue == NULL || isLinkedQueueEmpty(queue)) return false;
	LinkedListNode *first = queue->last->next;
	*val = first->data;
    if (linkedQueueSize(queue) > 1) {
    		// skip the first node
    		queue->last->next = first->next;
    } else {
    		// if there is only one node, set last node to NULL
    		queue->last = NULL;
    }
    // delete node
	deleteNode(first);
	queue->size--;
	return true;
}

/**
 * Returns number of items in the linked queue.
 * @param queue the linked queue
 * @return the number of items in the linked queue.
 */
size_t linkedQueueSize(LinkedQueue *queue) {
	return queue == NULL ? 0 : queue->size;
}

/**
 * Determines whether linked queue is empty.
 * @param queue the linked queue
 * @return true if linked queue is empty, false otherwise
 */
bool isLinkedQueueEmpty(LinkedQueue *queue) {
	return linkedQueueSize(queue) == 0;
}
