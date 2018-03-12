/*
 * traversal_callbacks.h
 *
 * This file delares a collection of binary tree walker callbacks.
 *
 */

#ifndef TRAVERSAL_CALLBACKS_H_
#define TRAVERSAL_CALLBACKS_H_

/**
 * Postfix depth-first tree walker callback
 *
 * @param node the root node
 * @param tState the traversal state
 * @param tData the traversal data
 * @return true to continue crawling
 */
bool toPostfix(
		BinaryTreeNode* node,
		DepthFirstTraversalState tState,
		DepthFirstTraversalData tData);

/**
 * Prefix depth-first tree walker callback
 *
 * @param node the root node
 * @param tState the traversal state
 * @param tData the traversal data
 * @return true to continue crawling
 */
bool toPrefix(
		BinaryTreeNode* node,
		DepthFirstTraversalState tState,
		DepthFirstTraversalData tData);

/**
 * Infix depth-first tree walker callback
 *
 * @param node the root node
 * @param tState the traversal state
 * @param tData the traversal data
 * @return true to continue crawling
 */
bool toInfix(
		BinaryTreeNode* node,
		DepthFirstTraversalState tState,
		DepthFirstTraversalData tData);

/**
 * Enqueues just the leaf nodes in the tree in a
 * BinaryTreeNodeQueue using breadth-first traversal.
 *
 * @param node the visited tree node
 * @param tData the traversal data -- must be a BinaryTreeNodeQueue*
 */
bool getLeafNodes(
	BinaryTreeNode* node,
	BreadthFirstTraversalData tData);

#endif /* TRAVERSAL_CALLBACKS_H_ */
