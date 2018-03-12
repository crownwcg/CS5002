#ifndef BINARY_TREE_NODE_QUEUE_H_
#define BINARY_TREE_NODE_QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>
#include "binary_tree_node.h"

/** Default maximum capacity for array is unlimited */
const size_t DEFAULT_MAX_CAPACITY;

/** Default capacity for array */
const size_t DEFAULT_CAPACITY;

/**
 * A struct representing a BinaryTreeNodeQueue.
 */
typedef struct {
    BinaryTreeNode** nodes;	// array of node pointers
    size_t size;    			// number of elements in the queue
    size_t capacity;			// length of allocated array
    size_t maxCapacity;		// maximum length of allocated array
} BinaryTreeNodeQueue;

/**
 * Add a number to the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 * @param node the BinaryTreeNode to enqueue
 * @return true if node was enqueued, false otherwise
 */
bool enqueueBinaryTreeNodeQueueVal(BinaryTreeNodeQueue* queue, BinaryTreeNode* node);

/**
 * Remove and return the first element in the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 * @param nodeRef pointer to return location of dequeued node
 * @return true if node was dequeued, false otherwise
 */
bool dequeueBinaryTreeNodeQueueVal(BinaryTreeNodeQueue* queue, BinaryTreeNode** nodeRef);

/**
 * Create a new BinaryTreeNode queue
 *
 * @param initialCapacity initial capacity of the BinaryTreeNodeQueue.
 *     Use DEFAULT_CAPACITY for default
 * @param maxCapacity maximum capacity of the BinaryTreeNodeQueue.
 *     Use DEFAULT_MAX_CAPACITY for default
 * @return a new BinaryTreeNode
 */
BinaryTreeNodeQueue *createBinaryTreeNodeQueue(size_t initialCapacity, size_t maxCapacity);

/**
 * Deallocate the memory for the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 */
void deleteBinaryTreeNodeQueue(BinaryTreeNodeQueue* queue);

/**
 * Get the current number of elements in the queue.
 *
 * @param queue the BinaryTreeNodeQueue
 */
int binaryTreeNodeQueueSize(BinaryTreeNodeQueue* queue);

/**
 * Determines whether queue is empty
 *
 * @param queue the BinaryTreeNodeQueue
 * @return true if the queue is empty
 */
bool isBinaryTreeNodeQueueEmpty(BinaryTreeNodeQueue* queue);

#endif /* BINARY_TREE_NODE_QUEUE_H_ */
