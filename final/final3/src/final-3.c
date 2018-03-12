/*
 * final-3.c
 *
 * This problem tests your understanding of binary search trees (BST)
 * by asking you write two iterative functions that locate particular
 * elements in the tree. Do not use recursion for this problem.
 *
 * a) Write function getMinBinarySearchTreeNode() that returns the
 * BinaryTreeNode in the tree with the smallest BinaryTreeNodeData
 * value in a binary search tree (BST). If the tree is empty, the
 * function returns NULL.
 *
 * b) Write function getMaxBinaryTreeNode() that returns the
 * BinaryTreeNode in the tree with the largest BinaryTreeNodeData
 * value in a binary search tree. If the tree is empty, the function
 * returns NULL.
 *
 *  CS 5002 Fall 2017 Silicon Valley
 *  Final Problem 3
 */
#include <stdlib.h>
#include <stdio.h>
#include "binary_tree_node.h"

/**
 * Gets the BinaryTreeNode in a binary search tree (BST) that has the
 * smallest BinaryTreeNodeData value.
 *
 * @param rootNode the root BinaryTreeNode
 * @return the BinaryTreeNode with the smallest BinaryTreeNodeData value
 */
BinaryTreeNode* getMinBinaryTreeNode(BinaryTreeNode* rootNode) {
	if (rootNode != NULL) {
		// iterate to find the left leaf node, which is the minimum
		BinaryTreeNode* curr = rootNode;
		while (curr != NULL && curr->linkTo[leftLink] != (BinaryTreeNode*) NULL)
			curr = curr->linkTo[leftLink];
		return curr;
	}
	return (BinaryTreeNode*) NULL;
}

/**
 * Gets the BinaryTreeNode in a binary search tree (BST) that has the
 * largest BinaryTreeNodeData value.
 *
 * @param rootNode the root BinaryTreeNode
 * @return the BinaryTreeNode with the largest BinaryTreeNodeData value
 */
BinaryTreeNode* getMaxBinaryTreeNode(BinaryTreeNode* rootNode) {
	if (rootNode != NULL) {
		// iterate to find the right leaf node, which is the maximum
		BinaryTreeNode* curr = rootNode;
		while (curr != NULL && curr->linkTo[rightLink] != (BinaryTreeNode*) NULL)
			curr = curr->linkTo[rightLink];
		return curr;
	}
	return (BinaryTreeNode*) NULL;
}

/**
 *  Initialize links BinaryTreeNode links
 *  @param node the node
 *  @param left the left node
 *  @param right the right node
 *  @param parent the partent node
 */
void initLinks(BinaryTreeNode* node,
		       BinaryTreeNode* left, BinaryTreeNode* right, BinaryTreeNode* parent) {
	node->linkTo[leftLink] = left;
	node->linkTo[rightLink] = right;
	node->linkTo[parentLink] = parent;
}

/**
 * This function tests the two new binary search tree functions.
 */
int main(void) {
	printf("*** Start problem #3\n\n");

	//                       node0(50)
	//                           |
	//             .-------------'-------------.
	//         node1(20)                   node2(80)
	//             |                           |
	//        .----'----.                 .----'----.
	//    node3(10) node4(30)         node5(60) node6(90)
	//       |                                       |
	//       '----.                                  '----.
	//        node7(15)                               node8(95)
	//
	BinaryTreeNode node0  = {&(BinaryTreeNodeData) {"50"}};

	BinaryTreeNode node1 = {&(BinaryTreeNodeData) {"20"}};
	BinaryTreeNode node3 = {&(BinaryTreeNodeData) {"10"}};
	BinaryTreeNode node4 = {&(BinaryTreeNodeData) {"30"}};
	BinaryTreeNode node7 = {&(BinaryTreeNodeData) {"15"}};

	BinaryTreeNode node2 = {&(BinaryTreeNodeData) {"80"}};
	BinaryTreeNode node5 = {&(BinaryTreeNodeData) {"60"}};
	BinaryTreeNode node6 = {&(BinaryTreeNodeData) {"90"}};
	BinaryTreeNode node8 = {&(BinaryTreeNodeData) {"95"}};

	// children: nodeL11, nodeR11; parent: NULL
	initLinks(&node0, &node1, &node2, NULL);

	// children: nodeL21, nodeL22; parent: node0
	initLinks(&node1, &node3, &node4, &node0);
	initLinks(&node3, NULL, &node7, &node1);
	initLinks(&node4, NULL, NULL, &node1);
	initLinks(&node7, NULL, NULL, &node3);

	// children: nodeR21, nodeR22; parent: node0
	initLinks(&node2, &node5, &node6, &node0);
	initLinks(&node5, NULL, NULL, &node2);
	initLinks(&node6, NULL, &node8, &node2);
	initLinks(&node8, NULL, NULL, &node6);

	printf("*Getting min binary search tree node\n");
	BinaryTreeNode* minTreeNode = getMinBinaryTreeNode(&node0);
	if (minTreeNode == NULL) {
		printf("found no node, expected \"10\"\n");
	} else {
		printf("found node with \"%s\", expected \"10\"\n", minTreeNode->data->strval);
	}

	printf("\n*Getting min binary search tree node\n");
	BinaryTreeNode* maxTreeNode = getMaxBinaryTreeNode(&node0);
	if (maxTreeNode == NULL) {
		printf("found no node, expected \"95\"\n");
	} else {
		printf("found node with \"%s\", expected \"95\"\n", maxTreeNode->data->strval);
	}

	printf("\n*** End problem #3\n");
	return EXIT_SUCCESS;
}

