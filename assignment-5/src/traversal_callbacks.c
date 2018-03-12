/*
 * traversal_callbacks.c
 *
 *  This file is a collection of binary tree walker callbacks.
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree_node_queue.h"
#include "binary_tree.h"

/**
 * Check the node holds an operator that only has one number to operate.
 *
 * @param node the tree node
 * @returns true if the operator only has one parameter, and false otherwise.
 */
static bool isOneParameterOperater(BinaryTreeNode* node) {
	return node->linkTo[leftLink] == NULL && node->linkTo[rightLink] != NULL;
}

/**
 * Write prefix order expression string to traversal data string buffer.
 *
 * @param node the visited tree node
 * @param tState the state of the traversal
 * @param tData the traversal data -- must be a string buffer
 * @returns true to continue
 */
bool toPostfix(
	BinaryTreeNode* node,
	DepthFirstTraversalState tState,
	DepthFirstTraversalData tData) {
	size_t len = strlen(tData);
	tData = (char *) tData;
	if (tState == fromParent) {
		if (isBinaryTreeNodeLeaf(node)) {
			if (len != 0 && *(char *) (tData + len - 1) != ' ')
				strcat(tData, " ");
			strcat(tData, node->data->strval);
		}
	} else if (tState == fromRight) {
		if (!isBinaryTreeNodeLeaf(node)) {
			if (len != 0 && *(char *) (tData + len - 1) != ' ')
				strcat(tData, " ");
			strcat(tData, node->data->strval);
		}
	}
	return true;
}

/**
 * Write prefix order expression string to traversal data string buffer.
 *
 * @param node the visited tree node
 * @param tState the state of the traversal
 * @param tData the traversal data -- must be a string buffer
 * @returns true to continue
 */
bool toPrefix(
	BinaryTreeNode* node,
	DepthFirstTraversalState tState,
	DepthFirstTraversalData tData) {
	if (tState == fromParent) {
		if (isBinaryTreeNodeLeaf(node)) {
			strcat(tData, node->data->strval);
		} else {
			strcat(tData, "( ");
			strcat(tData, node->data->strval);
			strcat(tData, " ");
		}
	} else if (tState == fromLeft) {
		if (!isBinaryTreeNodeLeaf(node) && !isOneParameterOperater(node))
			strcat(tData, " ");
	} else {
		strcat(tData, " )");
	}
	return true;
}

/**
 * Write infix order expression string to traversal data string buffer.
 *
 * @param node the visited tree node
 * @param tState the state of the traversal
 * @param tData the traversal data -- must be a string buffer
 * @returns true to continue
 */
bool toInfix(
	BinaryTreeNode* node,
	DepthFirstTraversalState tState,
	DepthFirstTraversalData tData) {
	if (tState == fromParent) {
		if (node->linkTo[leftLink] != NULL)
			strcat(tData, "( ");
		if (!isBinaryTreeNodeLeaf(node) && isOneParameterOperater(node))
			strcat(tData, "(");
		if (isBinaryTreeNodeLeaf(node))
			strcat(tData, node->data->strval);
	} else if (tState == fromLeft) {
		strcat(tData, " ");
		strcat(tData, node->data->strval);
		strcat(tData, " ");
	} else {
		strcat(tData, " )");
	}
	return true;
}

/**
 * Enqueues just the leaf nodes in the tree in a BinaryTreeNodeQueue
 * using in the queue breadth-first traversal.
 *
 * @param node the visited tree node
 * @param tData the traversal data -- must be a BinaryTreeNodeQueue*
 */
bool getLeafNodes(
	BinaryTreeNode* node,
	BreadthFirstTraversalData tData) {
	if (isBinaryTreeNodeLeaf(node))
		enqueueBinaryTreeNodeQueueVal((BinaryTreeNodeQueue *)tData, node);
	return true;
}
