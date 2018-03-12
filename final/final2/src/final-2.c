/*
 * final-2.c
 *
 * This problem tests your understanding of recursion by
 * asking you to write several recursive functions that
 * implement specified operations on a binary tree. The
 * stubs for the three functions are above the main()
 * function in this file.
 *
 * NOTE: Do not take up precious test time trying to make
 * the your spacing match the expected output. A few extra
 * spaces here or there are alright.
 *
 *  CS 5002 Fall 2017 Silicon Valley
 *  Final Problem 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "binary_tree_node.h"

/**
 * Utility function to create and initiaize a TreeNodeData instance.
 *
 * @param val the value for the data
 * @return the new BinaryTreeNodeData
 */
BinaryTreeNodeData *createBinaryTreeNodeData(const char* val) {
	BinaryTreeNodeData* data = malloc(sizeof(BinaryTreeNodeData));
	data->strval = val;
	return data;
}

/**
 * Creates the following height 3 expression tree:
 *                    +
 *         .----------'----------.
 *         -                     *
 *    .----'----.           .----'----.
 *    9        sqr          /         7
 *           .--'--.     .--'--.
 *                 2     8     4
 */
BinaryTreeNode* makeExprTree3() {
	// root node
	BinaryTreeNodeData* rootData = createBinaryTreeNodeData("+");
	BinaryTreeNode* root = createBinaryTreeNode(rootData);

	// left level 1
	BinaryTreeNodeData* node10Data = createBinaryTreeNodeData("-");
	BinaryTreeNode* node10 = createBinaryTreeNode(node10Data);

	// right level 1
	BinaryTreeNodeData* node11Data = createBinaryTreeNodeData("*");
	BinaryTreeNode* node11 = createBinaryTreeNode(node11Data);

	// left left level 2
	BinaryTreeNodeData* node20Data = createBinaryTreeNodeData("9");
	BinaryTreeNode* node20 = createBinaryTreeNode(node20Data);

	// right left level 2
	BinaryTreeNodeData* node21Data = createBinaryTreeNodeData("sqr");
	BinaryTreeNode* node21 = createBinaryTreeNode(node21Data);

	// left right level 22
	BinaryTreeNodeData* node22Data = createBinaryTreeNodeData("/");
	BinaryTreeNode* node22 = createBinaryTreeNode(node22Data);

	// right right level 2
	BinaryTreeNodeData* node23Data = createBinaryTreeNodeData("7");
	BinaryTreeNode* node23 = createBinaryTreeNode(node23Data);


	// right left level 3
	BinaryTreeNodeData* node30Data = createBinaryTreeNodeData("2");
	node30Data->strval = "2";
	BinaryTreeNode* node30 = createBinaryTreeNode(node30Data);

	// left right level 3
	BinaryTreeNodeData* node31Data = createBinaryTreeNodeData("8");
	BinaryTreeNode* node31 = createBinaryTreeNode(node31Data);

	// right right level 3
	BinaryTreeNodeData* node32Data = createBinaryTreeNodeData("4");
	BinaryTreeNode* node32 = createBinaryTreeNode(node32Data);

	// root to left level 1
	addBinaryTreeNodeAfter(node10, root, leftLink);

	// root to right level 1
	addBinaryTreeNodeAfter(node11, root, rightLink);

	// level2 left left to level 1 left
	addBinaryTreeNodeAfter(node20, node10, leftLink);

	// level2 right left to level 1 left
	addBinaryTreeNodeAfter(node21, node10, rightLink);

	// level2 left right to level 1 right
	addBinaryTreeNodeAfter(node22, node11, leftLink);

	// level2 right right to level 1 right
	addBinaryTreeNodeAfter(node23, node11, rightLink);

	// level3 left left right
	// use right for to make operator prefix for single parameter
	addBinaryTreeNodeAfter(node30, node21, rightLink);

	// level3 left left right
	addBinaryTreeNodeAfter(node31, node22, leftLink);

	// level2 right right to level 1 right
	addBinaryTreeNodeAfter(node32, node22, rightLink);

	return root;
}

/**
 * Print the binary expression tree in infix order
 *
 * @param node the root tree node.
 */
void printBinaryTreeInfixOrder(BinaryTreeNode *node) {
	if (node == NULL) return;
	// order recursion in left, parent, right
	if (!isBinaryTreeNodeLeaf(node)) printf("( ");
	printBinaryTreeInfixOrder(node->linkTo[leftLink]);
	if (!isBinaryTreeNodeLeaf(node)) printf(" ");
	printf("%s", node->data->strval);
	if (!isBinaryTreeNodeLeaf(node)) printf(" ");
	printBinaryTreeInfixOrder(node->linkTo[rightLink]);
	if (!isBinaryTreeNodeLeaf(node)) printf(" )");
}

/**
 * Print the binary expression tree in prefix order.
 *
 * @param node the root tree node.
 */
void printBinaryTreePrefixOrder(BinaryTreeNode *node) {
	if (node == NULL) return;
	// order recursion in parent, left, right
	printf("%s ", node->data->strval);
	printBinaryTreePrefixOrder(node->linkTo[leftLink]);
	printBinaryTreePrefixOrder(node->linkTo[rightLink]);
}

/**
 * Print the binary expression tree in infix order
 *
 * @param node the root tree node.
 */
void printBinaryTreePostfixOrder(BinaryTreeNode *node) {
	if (node == NULL) return;
	// order recursion in left, right, parent
	printBinaryTreePostfixOrder(node->linkTo[leftLink]);
	printBinaryTreePostfixOrder(node->linkTo[rightLink]);
	printf("%s ", node->data->strval);
}

/**
 * Main program tests tree printing functions.
 */
int main(void) {
	printf("*** Start problem 2\n");

	BinaryTreeNode *root = makeExprTree3();
	printf("\ninfix:    ");
	printBinaryTreeInfixOrder(root);
	printf("\nexpected: ( ( 9 - (  sqr 2 ) ) + ( ( 8 / 4 ) * 7 ) )\n");
	printf("\nprefix:   ");
	printBinaryTreePrefixOrder(root);
	printf("\nexpected: + - 9 sqr 2 * / 8 4 7 \n");
	printf("\npostfix:  ");
	printBinaryTreePostfixOrder(root);
	printf("\nexpected: 9 2 sqr - 8 4 / 7 * + \n");

	printf("\n*** End problem 2\n");

	return EXIT_SUCCESS;
}
