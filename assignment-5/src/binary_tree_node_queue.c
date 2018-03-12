/*
 * messagequeue.c
 *
 * The functions in this file implement a MessageQueue that enables instances
 * of Message to be enqueued and dequeued on a first-in first-out (FIFO) order.
 * The MessageQueue can grow to accommodate any number of messages.
 *
 * @since Feb 1, 2017
 * @author phil
 */
#include "binary_tree_node_queue.h"

#include <stdlib.h>
#include <assert.h>

/** Default maximum capacity for queue is unlimited */
const size_t DEFAULT_MAX_CAPACITY = SIZE_MAX;

/** Default capacity for queue */
const size_t DEFAULT_CAPACITY = 4;


/**
 * Add a number to the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 * @param node the BinaryTreeNode to enqueue
 * @return true if node was enqueued, false otherwise
 */
bool enqueueBinaryTreeNodeQueueVal(BinaryTreeNodeQueue* queue, BinaryTreeNode* node) {
	if (queue == NULL || node == NULL) return false;
	// resize the queue if capacity is less than required
	if (queue->capacity < queue->size + 1) {
		// if capacity exceeds the maximum capacity, return false
		if (queue->capacity * 2 > queue->maxCapacity) return false;
		// resize queue
		queue->capacity *= 2;
		queue->nodes = (BinaryTreeNode **) realloc(queue->nodes, sizeof(BinaryTreeNode *) * queue->capacity);
	}
	// enqueue
	queue->nodes[queue->size++] = node;
	return true;
}

/**
 * Remove and return the first element in the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 * @param nodeRef pointer to return location of dequeued node
 * @return true if node was dequeued, false otherwise
 */
bool dequeueBinaryTreeNodeQueueVal(BinaryTreeNodeQueue* queue, BinaryTreeNode** nodeRef) {
	if (queue == NULL || nodeRef == NULL || isBinaryTreeNodeQueueEmpty(queue)) return false;
	*nodeRef = queue->nodes[0];
	for (int i = 0; i < queue->size - 1; i++) {
		queue->nodes[i] = queue->nodes[i+1];
	}
	queue->nodes[queue->size - 1] = NULL;
	queue->size--;
	// resize queue
	if (queue->capacity > 2 * queue->size) {
		queue->capacity /= 2;
		queue->nodes = (BinaryTreeNode **) realloc(queue->nodes, sizeof(BinaryTreeNode *) * queue->capacity);
	}
	return true;
}

/**
 * Create a new BinaryTreeNode queue
 *
 * @param initialCapacity initial capacity of the BinaryTreeNodeQueue.
 *     Use DEFAULT_CAPACITY for default
 * @param maxCapacity maximum capacity of the BinaryTreeNodeQueue.
 *     Use DEFAULT_MAX_CAPACITY for default
 * @return a new BinaryTreeNode
 */
BinaryTreeNodeQueue *createBinaryTreeNodeQueue(size_t initialCapacity, size_t maxCapacity) {
	// allocate memory
	BinaryTreeNodeQueue *btq = (BinaryTreeNodeQueue *) malloc(sizeof(BinaryTreeNodeQueue));
	// initiate every area of the data structure
	btq->maxCapacity = maxCapacity;
	btq->capacity = initialCapacity;
	btq->nodes = (BinaryTreeNode **) malloc(sizeof(BinaryTreeNode *) * btq->capacity);
	btq->size = 0;
	return btq;
}


/**
 * Deallocate the memory for the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 */
void deleteBinaryTreeNodeQueue(BinaryTreeNodeQueue* queue) {
	if (queue == NULL) return;
	free(queue->nodes);
	queue->nodes = NULL;
	queue->maxCapacity = DEFAULT_MAX_CAPACITY;
	queue->capacity = DEFAULT_CAPACITY;
	queue->size = 0;
	free(queue);
}

/**
 * Get the current number of elements in the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 */
int binaryTreeNodeQueueSize(BinaryTreeNodeQueue* queue) {
	return queue == NULL ? 0 : queue->size;
}

/**
 * Determines whether queue is empty
 *
 * @param queue the BinaryTreeNodeQueue
 * @return true if the queue is empty
 */
bool isBinaryTreeNodeQueueEmpty(BinaryTreeNodeQueue* queue) {
	return queue == NULL ? true : queue->size == 0;
}
