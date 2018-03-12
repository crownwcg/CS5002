/*
 * linked_Queue.h
 *
 *  Created on: Dec 5, 2017
 *  Author: philip gust
 */

#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * Singly linked list node for generic data
 * Note peculiar way the "C" requires node next field to be declared
 */
typedef struct _LinkedListNode {
	void* data;
	struct _LinkedListNode* next;
} LinkedListNode;

/** linked queue data structure using a circular list*/
typedef struct {
	LinkedListNode *last;	// pointer to last node in list
	size_t size;
} LinkedQueue;

/**
 * Create an linked queue with an initial capacity and max capacity.
 *
 * @return the allocated linked queue
 */
LinkedQueue *createLinkedQueue(void);

/**
 * Delete the linked queue by first clearing it, then
 * freeing its storae.
 *
 * @param queue the linked queue
 */
void deleteLinkedQueue(LinkedQueue *queue);

/**
 * Clear linked queue values.
 * @param list the array list
 */
void clearLinkedQueue(LinkedQueue *queue);

/**
 * Add value to th queue. Cannot add NULL string to the queue.
 * @param queue the LinkedQueue
 * @param val the value to insert; value will be copied to store,
 *     and cannot be null
 * @return false if exceeds max capacity
 */
bool enqueueLinkedQueueVal(LinkedQueue *queue, void *val);

/**
 * Get the top Queue value without removing it.
 * @param queue the LinkedQueue
 * @param val result parameter is pointer to result value location
 * @return false if queue is empty
 */
bool peekLinkedQueueVal(LinkedQueue *queue, void **val);

/**
 * Set the queue top to a new value.
 * @param queue the LinkedQueue
 * @param val the value to set
 * @return false if the queue is empty
 */
bool pokeLinkedQueueVal(LinkedQueue *queue, void *val);

/**
 * Delete the linked queue value at the specified index.
 * @param queue the linked queue
 * @param val result parameter is pointer to result value location;
 *   cannot be null
 * @return false if Queue is empty
 */
bool dequeueLinkedQueueVal(LinkedQueue *queue, void **val);

/**
 * Returns number of items in the linked queue.
 * @param queue the linked queue
 * @return the number of items in the linked queue.
 */
size_t linkedQueueSize(LinkedQueue *queue);

/**
 * Determines whether linked queue is empty.
 * @param queue the linked queue
 * @return true if linked queue is empty, false otherwise
 */
bool isLinkedQueueEmpty(LinkedQueue *queue);

#endif /* LINKED_QUEUE_H_ */
