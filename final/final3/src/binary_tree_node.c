/*
 * binary_tree_node.c
 *
 *  @since 2017-02-17
 *  @author Philip Gust
 */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binary_tree_node.h"

/**
 * Compare the data for two binary tree nodes.
 *
 * @param data1 the first node data
 * @param data2 the second node data
 * @return <0 if data1<data2, =0 if data1=data2, >0 if data1>data2
 */
int compareBinaryTreeNodeData(BinaryTreeNodeData* data1, BinaryTreeNodeData* data2) {
	return strcmp(data1->strval, data2->strval);
}

/**
 * Initialize a BinaryTreeNode data and linkTo fields with NULL.
 *
 * @param node the binary tree node to initialize
 * @param data the value of the data field
 * @return a new BinaryTreeNode
 */
void initBinaryTreeNode(BinaryTreeNode* node, BinaryTreeNodeData* data) {
	node->data = data;
	node->linkTo[leftLink] = (BinaryTreeNode*) NULL;
	node->linkTo[rightLink] = (BinaryTreeNode*) NULL;
	node->linkTo[parentLink] = (BinaryTreeNode*) NULL;
}

/**
 * Create a new BinaryTreeNode with specified data or NULL.
 *
 * @param data the value of the data field (node owns this data)
 * @return a new BinaryTreeNode
 */
BinaryTreeNode* newBinaryTreeNode(BinaryTreeNodeData* data) {
	BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	initBinaryTreeNode(node, data);
	return node;
}

/**
 * Delete a BinaryTreeNode. Data must be freed by caller.
 *
 * @param node the node to free
 */
void deleteBinaryTreeNode(BinaryTreeNode* node) {
	if (node != (BinaryTreeNode*)NULL) {
		initBinaryTreeNode(node, (BinaryTreeNodeData*)NULL);
		free(node);
	}
}

/**
 * Determines the cardinality of a tree node.
 *
 * @param node a node in the tree
 * @return return 0 if a leaf, 2 if both links present, 1 if one link present
 */
int binaryTreeNodeCardinality(BinaryTreeNode* node) {
	return    (node->linkTo[leftLink] != (BinaryTreeNode*)NULL)
			+ (node->linkTo[rightLink] != (BinaryTreeNode*)NULL);
}

/**
 * Determines whether tree node is a leaf.
 *
 * @param node a node in the tree
 * @return true if the node is a leaf and false otherwise
 */
bool isBinaryTreeNodeLeaf(BinaryTreeNode* node) {
	return binaryTreeNodeCardinality(node) == 0;
}

/**
 * Determines whether tree node is a root.
 *
 * @param node a node in the tree
 * @return true if the node is a root and false otherwise
 */
bool isBinaryTreeNodeRoot(BinaryTreeNode* node) {
	return (node->linkTo[parentLink] == (BinaryTreeNode*)NULL);
}

/**
 * Returns the BinaryTreeNodeLink enumeration for the "other" child.
 *
 * @param childLink the child link enumeration (leftNode or rightNode)
 * @return the enumeration for the "other" child link (rightNode or leftNode),
 *   or the original enumeration if the childLink is not leftNode or rightNode
 */
BinaryTreeNodeLink otherBinaryTreeNodeChildLink(BinaryTreeNodeLink childLink) {
	switch (childLink) {
		case leftLink: return rightLink;
		case rightLink: return leftLink;
		default: return childLink;  // should not happen
	}
}
