/*
 * messagepriorityqueue.h
 *
 * This file declares the MessagePriorityQueue and its functions.
 *
 *  Created on: Feb 1, 2017
 *  Author: philip gust
 */

#ifndef MESSAGEPRIORITYQUEUE_H_
#define MESSAGEPRIORITYQUEUE_H_

#include <stdbool.h>
#include "array_deque.h"

/**
 * The priorities for the MessagePriorityQueue
 */
typedef enum {
	highest,
	high,
	low,
	lowest
} Priority;

/**
 * The MessagePriorityQueue is an array of ArrayDeque pointers
 * for each Priority
 */
typedef struct {
	ArrayDeque** msgQueues;
} MessagePriorityQueue;

/**
 * Create new message priority queue
 *
 * @return a new MessagePriorityQueue
 */
MessagePriorityQueue* createMPQ();

/**
 * Deallocate memory for message priority queue.
 *
 * @param queue the MessagePriorityQueue
 */
void deleteMPQ(MessagePriorityQueue* queue);

/**
 * Enque a message with given priority.
 *
 * @paam queue the message priority queue
 * @param message the message to enqueue
 * @param priority the message priority
 */
void enqueueMessageMPQ(MessagePriorityQueue* queue, const char* message, Priority priority);

/**
 * Dequeue highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @return the message or NULL if none available
 */
const char* dequeueMessageMPQ(MessagePriorityQueue* queue);

/**
 * Peek highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @return the message or NULL if none available
 */
const char* peekMessageMPQ(MessagePriorityQueue* queue);

/**
 * Get number of messages with a given priority in the queue.
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
size_t messageCountForPriorityMPQ(MessagePriorityQueue* queue, Priority priority);

/**
 * Determines whether queue for given priority is empty
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
bool isEmptyForPriorityMPQ(MessagePriorityQueue* queue, Priority priority);

/**
 * Get total number of messages in the priority queue
 *
 * @param queue the MessagePriorityQueue
 * @return total number of messages
 */
size_t messageCountMPQ(MessagePriorityQueue* queue);

/**
 * Determines whether queue is empty
 *
 * @param queue the MessagePriorityQueue
 * @return number of messages for given priority
 */
bool isEmptyMPQ(MessagePriorityQueue* queue);

#endif /* MESSAGEPRIORITYQUEUE_H_ */
