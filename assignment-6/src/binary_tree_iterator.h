/*
 * binary_tree_iterator.h
 *
 * This file provides the structure and function definitions for an
 * iterator of a binary tree.
 *
 * @since 2017-02-15
 * @author philip gust
 */

#ifndef BINARY_TREE_ITERATOR_H_
#define BINARY_TREE_ITERATOR_H_

#include <stdbool.h>
#include "binary_tree.h"

/**
 * enum of three types of traversal order, inorder, preorder, and postorder
 */
typedef enum {inorder, preorder, postorder} TraversalOrder;

/**
 * An iterator for a binary tree
 */
typedef struct {
  BinaryTreeNode* theTree;
  BinaryTreeNode* curNode;
  BinaryTreeNodeLink prevLink;
  size_t count;  // the number of nodes returned by iterator
  size_t size;  // the size of the tree
  TraversalOrder traversalOrder;
} BinaryTreeIterator;

/**
 * Value returned by getLinkedListIteratorAvailable if count unavailable
 */
extern const size_t UNAVAILABLE;

/**
 * Create and initialize a new BinaryTreeIterator
 *
 * @param theTree binary tree
 * @return an iterator for the specified binary tree
 */
BinaryTreeIterator* createBinaryTreeIterator(BinaryTreeNode* theTree, TraversalOrder traversalOrder);

/**
 * Freeing iterator storage.
 *
 * @param itr the BinaryTreeIterator to delete
 */
void deleteBinaryTreeIterator(BinaryTreeIterator* itr);

/**
 * Gets next link node in the binary tree
 *
 * @param itr the BinaryTreeIterator
 * @param nodeRef address where returned node will be returned
 * @return true if there is a next nodde, false otherwise
 */
bool getNextBinaryTreeNode(BinaryTreeIterator* itr, BinaryTreeNode **nodeRef);

/**
 * Determines whether there is another node in the binary tree.
 *
 * @param itr the BinaryTreeIterator
 * @return true if there is another node, false otherwise
 */
bool hasNextBinaryTreeNode(BinaryTreeIterator* itr);

/**
 * Gets previous node in the binary tree.
 *
 * @param itr the BinaryTreeIterator
 * @return the previous node or NULL if iterator is at end of list
 */
BinaryTreeNode* getPrevBinaryTreeNode(BinaryTreeIterator* itr);

/**
 * Determines whether there is a previous node in the binary tree.
 *
 * @param itr the BinaryTreeIterator
 * @return true if there is a previous node, false otherwise
 */
bool hasPrevBinaryTreeNode(BinaryTreeIterator* itr);

/**
 * Resets the binary tree iterator to the root of the tree.
 *
 * @param itr the BinaryTreeIterator
 * @return true if successful, false if not supported
 */
bool resetBinaryTreeIterator(BinaryTreeIterator* itr);

/**
 * Returns the number of nodes returned so far.
 *
 * @param itr the BinaryTreeIterator
 */
int getBinaryTreeIteratorCount(BinaryTreeIterator* itr);

/**
 * Returns the number of nodes available.
 *
 * @param itr the BinaryTreeIterator
 * @return available number of node or UNAVAILABLE if cannot perform operation.
 */
int getBinaryTreeIteratorAvailable(BinaryTreeIterator* itr);

#endif /* BINARY_TREE_ITERATOR_H_ */
