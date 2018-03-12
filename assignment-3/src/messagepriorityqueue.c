/*
 * messagepriorityqueue.c
 *
 * This file implements the MessagePriorityQueue functions.
 *
 *  Created on: Feb 1, 2017
 *  Author: philip gust
 */
#include <stdlib.h>
#include "messagepriorityqueue.h"

/**
 * Create new message priority queue
 *
 * @return a new MessagePriorityQueue
 */
MessagePriorityQueue* createMPQ() {
	// your code here
	return NULL; // temporary
}

/**
 * Deallocate memory for message priority queue.
 *
 * @param queue the MessagePriorityQueue
 */
void deleteMPQ(MessagePriorityQueue* queue) {
	// your code here
}

/**
 * Enque a message with given priority.
 *
 * @paam queue the message priority queue
 * @param message the message to enqueue
 * @param priority the message priority
 */
void enqueueMessageMPQ(MessagePriorityQueue* queue, const char* message, Priority priority) {
	// your code here
}

/**
 * Dequeue highest priority message from the queue.
 *
 * @paam queue the message priority queue
 * @return the message or NULL if none available
 */
const char* dequeueMessageMPQ(MessagePriorityQueue* queue) {
	// your code here
	return NULL; // temporary
}

/**
 * Peek highest priority message from the queue.
 *
 * @param queue the message priority queue
 * @return the message or NULL if none available
 */
const char* peekMessageMPQ(MessagePriorityQueue* queue) {
	// your code here
	return NULL; // temporary
}

/**
 * Get number of messages with a given priority in the queue.
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
size_t messageCountForPriorityMPQ(MessagePriorityQueue* queue, Priority priority) {
	// your code here
	return 0; // temporary
}

/**
 * Determines whether queue for given priority is empty
 *
 * @param queue the MessagePriorityQueue
 * @param priority the message priority
 * @return number of messages for given priority
 */
bool isEmptyForPriorityMPQ(MessagePriorityQueue* queue, Priority priority) {
	// your code here
	return 0; // temporary
}

/**
 * Get total number of messages in the priority queue
 *
 * @param queue the MessagePriorityQueue
 * @return total number of messages
 */
size_t messageCountMPQ(MessagePriorityQueue* queue) {
	// your code here
	return 0; // temporary
}

/**
 * Determines whether queue is empty
 *
 * @param queue the MessagePriorityQueue
 * @return number of messages for given priority
 */
bool isEmptyMPQ(MessagePriorityQueue* queue) {
	// your code here
	return 0; // temporary
}

