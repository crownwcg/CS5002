/*
 * tree.h
 *
 *  @since 2017-02-17
 *  @author Philip Gust
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <stdbool.h>
#include "binary_tree_node.h"

/**
 * States for depth-first traversal
 */
typedef enum {
	fromLeft,
	fromRight,
	fromParent,
} DepthFirstTraversalState;

/**
 * Definition covers void* depth-first traversal data
 */
typedef void* DepthFirstTraversalData;

/**
 * Definition of depth-first traversal callback
 */
typedef bool (*DepthFirstTraversalCallback)
	(BinaryTreeNode*, DepthFirstTraversalState, DepthFirstTraversalData);

/**
 * Traverses the tree depth-first. Callback is called
 * during traversal when traversal enters from parent,
 * when traversal returns from the left child, and when
 * traversal returns from right child.
 *
 * @param node the root node in the tree
 * @param callback the depth first traversal callback
 * @param callbackData the traversal callback data
 * @param returns true if traversal completed, false if
 *   traversal terminated before traversal completed
 */
bool binaryTreeTraverseDepthFirst(
		BinaryTreeNode* node,
		DepthFirstTraversalCallback callback,
		DepthFirstTraversalData callbackData);

/**
 * Definition covers void* bredth-first traversal data
 */
typedef void* BreadthFirstTraversalData;

/**
 * Definition of breadth-first traversal callback
 */
typedef bool (*BreadthFirstTraversalCallback)
	(BinaryTreeNode*, BreadthFirstTraversalData);

/**
 * Traverse a binary tree breadth-first. Callback is called
 * during traversal when visits a node during bredth-first
 * traversal.
 *
 * @param node the root node in the tree
 * @param callback the depth first traversal callback
 * @param callbackData the traversal callback data
 * @param returns true if traversal completed, false if
 *   traversal terminated before traversal completed
 */
bool binaryTreeTraverseBreadthFirst(
		BinaryTreeNode* node,
		BreadthFirstTraversalCallback callback,
		BreadthFirstTraversalData callbackData);

/**
 * Adds a BinaryTreeNode as a child of the parent node.
 *
 * @param childNode the child node o add
 * @param parentNode the parent of the child
 * @param whichChild one of {leftNode, rightNode}
 * @return false if node has a child in the position, true otherwise
 */
bool addBinaryTreeNodeAfter(
		BinaryTreeNode* childNode,
		BinaryTreeNode* parentNode,
		BinaryTreeNodeLink whichChild) ;

/**
 * Free the node storage for the binary tree specified by root.
 * Data must be freed by caller.
 *
 * @param root the root of a binary tree
 */
void deleteBinaryTree(BinaryTreeNode* root);

/**
 * Return the BinaryTreeNodeLink for a child of a parent node.
 * The childNode must be a child of the parent node.
 *
 * @param parentNode the parentNode
 * @param childNode the child node
 * @return leftLink if the child is a left child, rightLink if
 *  parentNode is a right child, or parentLink if childNode or
 *  parentNode if childNode is not a child of the parentNode.
 */
BinaryTreeNodeLink linkOfParentBinaryTreeNodeChild(
		BinaryTreeNode* parentNode, BinaryTreeNode* childNode);

/**
 * Return the BinaryTreeNodeLink for a child of a parent node.
 *
 * @param childNode the child node
 * @return leftLink if the child is a left child, or rightLink if
 *   the child is a rightLink; or parentLink if child is a root.
 */
BinaryTreeNodeLink linkOfBinaryTreeNodeChild(BinaryTreeNode* childNode);

/**
 * Find the root of a binary tree from a node.
 * @param node the node
 * @return the root node
 */
BinaryTreeNode* findBinaryTreeNodeRoot(BinaryTreeNode* node);

/**
 * Returns depth of a binary tree node to its root node. The depth of a node
 * is the number of edges from the node to the tree's root node. A root node
 * will have a depth of 0.
 *
 * @param node a node in the tree
 * @return the depth of the node to the tree root
 */
int binaryTreeNodeDepth(BinaryTreeNode* node);

/**
 * Returns height of a binary tree from the root node. The height of a node
 * is the number of edges on the longest path from the node to a leaf. A leaf
 * node will have a height of 0. A NULL node will have a height of -1.
 *
 * @param node a node in the tree
 * @return the height of the node to the tree root
 */
int binaryTreeHeight(BinaryTreeNode* node);

/**
 * Returns number of nodes in a binary tree from the root node.
 *
 * @param node the root node in the tree
 * @return the number of nodes in the tree
 */
int binaryTreeSize(BinaryTreeNode* node);


#endif /* BINARY_TREE_H_ */
