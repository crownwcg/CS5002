/*
 * binary_tree_node_main.c
 *
 *  Created on: Nov 13, 2017
 *  Author: philip gust
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "binary_tree.h"
#include "binary_tree_node_queue.h"
#include "traversal_callbacks.h"

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

/*
 * Creates the following height 0 expression tree:
 *
 *                   5
 */
BinaryTreeNode* makeExprTree0() {
	// root node
	BinaryTreeNodeData* rootData = createBinaryTreeNodeData("5");
	BinaryTreeNode* root = createBinaryTreeNode(rootData);

	return root;
}

/*
 * Creates the following height 1 balanced expression tree:
 *
 *                   -
 *        .----------'----------.
 *        9                     4
 */
BinaryTreeNode* makeExprTree1() {
	// root node
	BinaryTreeNodeData* rootData = createBinaryTreeNodeData("-");
	BinaryTreeNode* root = createBinaryTreeNode(rootData);

	// left level 1
	BinaryTreeNodeData* node10Data = createBinaryTreeNodeData("9");
	BinaryTreeNode* node10 = createBinaryTreeNode(node10Data);

	// right level 1
	BinaryTreeNodeData* node11Data = createBinaryTreeNodeData("4");
	BinaryTreeNode* node11 = createBinaryTreeNode(node11Data);


	// root to left level 1
	addBinaryTreeNodeAfter(node10, root, leftLink);

	// root to right level 1
	addBinaryTreeNodeAfter(node11, root, rightLink);

	return root;
}

/*
 * Creates the following height 1 right-heavy expression tree:
 *
 *                  sqr
 *        .----------'----------.
 *                              2
 */
BinaryTreeNode* makeExprTree12() {
	// root node
	BinaryTreeNodeData* rootData = createBinaryTreeNodeData("sqr");
	BinaryTreeNode* root = createBinaryTreeNode(rootData);

	// right level 1
	BinaryTreeNodeData* node11Data = createBinaryTreeNodeData("2");
	BinaryTreeNode* node11 = createBinaryTreeNode(node11Data);


	// root to right level 1
	addBinaryTreeNodeAfter(node11, root, rightLink);

	return root;
}

/*
 * Creates the following height 2 right-heavy expression tree:
 *
 *                   -
 *        .----------'----------.
 *        9                    sqr
 *                         .----'----.
 *                                   2
 */
BinaryTreeNode* makeExprTree22() {
	// root node
	BinaryTreeNodeData* rootData = createBinaryTreeNodeData("-");
	BinaryTreeNode* root = createBinaryTreeNode(rootData);

	// left level 1
	BinaryTreeNodeData* node10Data = createBinaryTreeNodeData("9");
	BinaryTreeNode* node10 = createBinaryTreeNode(node10Data);

	// right level 1
	BinaryTreeNodeData* node11Data = createBinaryTreeNodeData("sqr");
	BinaryTreeNode* node11 = createBinaryTreeNode(node11Data);

	// right right level 2
	BinaryTreeNodeData* node23Data = createBinaryTreeNodeData("2");
	BinaryTreeNode* node23 = createBinaryTreeNode(node23Data);

	// root to left level 1
	addBinaryTreeNodeAfter(node10, root, leftLink);

	// root to right level 1
	addBinaryTreeNodeAfter(node11, root, rightLink);

	// level2 right right to level 1 right
	addBinaryTreeNodeAfter(node23, node11, rightLink);

	return root;
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
 * Traversal callback counts nodes in pre-order.
 * @param node the BinaryTreeNode
 * @param state the traversal state
 * @param data pointer to the int count
 * @return true to continue crawling, false to terminate crawling
 */
bool countNodesInBinaryTree(BinaryTreeNode *node,
							DepthFirstTraversalState state,
							DepthFirstTraversalData data) {
	// count node on entry from parent (pre-order)
	if (state == fromParent) {
		int *countp = data;
		(*countp)++;
	}
	return true;
}


/**
 * Test of toInfix() callback to depth-first binary tree walker
 */
static void test_toInfix_Callback(void) {
	BinaryTreeNode* exprTree;
	char strbuf[128];

	exprTree = makeExprTree0();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toInfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "5");

	exprTree = makeExprTree1();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toInfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( 9 - 4 )");

	exprTree = makeExprTree12();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toInfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( sqr 2 )");

	exprTree = makeExprTree22();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toInfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( 9 - ( sqr 2 ) )");

	exprTree = makeExprTree3();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toInfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( ( 9 - ( sqr 2 ) ) + ( ( 8 / 4 ) * 7 ) )");
}

/**
 * Test of toPrefix() depth-first binary tree walker.
 */
static void test_toPrefix_Callback(void) {
	BinaryTreeNode* exprTree;
	char strbuf[128];

	exprTree = makeExprTree0();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPrefix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "5");

	exprTree = makeExprTree1();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPrefix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( - 9 4 )");

	exprTree = makeExprTree12();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPrefix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( sqr 2 )");

	exprTree = makeExprTree22();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPrefix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( - 9 ( sqr 2 ) )");

	exprTree = makeExprTree3();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPrefix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "( + ( - 9 ( sqr 2 ) ) ( * ( / 8 4 ) 7 ) )");
}

/**
 * Test of toPostfix() depth-first binary tree walker.
 */
static void test_toPostfix_Callback(void) {
	BinaryTreeNode* exprTree;
	char strbuf[128];

	exprTree = makeExprTree0();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPostfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "5");

	exprTree = makeExprTree1();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPostfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "9 4 -");

	exprTree = makeExprTree12();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPostfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "2 sqr");

	exprTree = makeExprTree22();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPostfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "9 2 sqr -");

	exprTree = makeExprTree3();
	strcpy(strbuf,"");
	binaryTreeTraverseDepthFirst(exprTree, toPostfix, strbuf);
	CU_ASSERT_STRING_EQUAL(strbuf, "9 2 sqr - 8 4 / 7 * +");
}

/**
 * Test of getLeafNodes() breadth-first binary tree walker.
 */
static void test_getLeafNodes_Callback(void) {
	BinaryTreeNode* exprTree;

	exprTree = makeExprTree0();
	BinaryTreeNodeQueue* queue0 = createBinaryTreeNodeQueue(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);
	binaryTreeTraverseBreadthFirst(exprTree, getLeafNodes, queue0);
	int q0count = binaryTreeNodeQueueSize(queue0);
	CU_ASSERT_EQUAL(q0count, 1);
	if (q0count == 1) {
		BinaryTreeNode *node;
		dequeueBinaryTreeNodeQueueVal(queue0, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "5");
	}

	exprTree = makeExprTree1();
	BinaryTreeNodeQueue* queue1 = createBinaryTreeNodeQueue(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);
	binaryTreeTraverseBreadthFirst(exprTree, getLeafNodes, queue1);
	int q1count = binaryTreeNodeQueueSize(queue1);
	CU_ASSERT_EQUAL(q1count, 2);
	if (q1count == 2) {
		BinaryTreeNode *node;
		dequeueBinaryTreeNodeQueueVal(queue1, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "9");
		dequeueBinaryTreeNodeQueueVal(queue1, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "4");
	}

	exprTree = makeExprTree12();
	BinaryTreeNodeQueue* queue12 = createBinaryTreeNodeQueue(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);
	binaryTreeTraverseBreadthFirst(exprTree, getLeafNodes, queue12);
	int q12count = binaryTreeNodeQueueSize(queue12);
	CU_ASSERT_EQUAL(q12count, 1);
	if (q12count == 1) {
		BinaryTreeNode *node;
		dequeueBinaryTreeNodeQueueVal(queue12, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "2");
	}

	exprTree = makeExprTree22();
	BinaryTreeNodeQueue* queue22 = createBinaryTreeNodeQueue(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);
	binaryTreeTraverseBreadthFirst(exprTree, getLeafNodes, queue22);
	int q22count = binaryTreeNodeQueueSize(queue22);
	CU_ASSERT_EQUAL(q22count, 2);
	if (q22count == 2) {
		BinaryTreeNode *node;
		dequeueBinaryTreeNodeQueueVal(queue22 ,&node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "9");
		dequeueBinaryTreeNodeQueueVal(queue22, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "2");
	}

	exprTree = makeExprTree3();
	BinaryTreeNodeQueue* queue3 = createBinaryTreeNodeQueue(DEFAULT_CAPACITY, DEFAULT_MAX_CAPACITY);;
	binaryTreeTraverseBreadthFirst(exprTree, getLeafNodes, queue3);
	int q3count = binaryTreeNodeQueueSize(queue3);
	CU_ASSERT_EQUAL(q3count, 5);
	if (q3count == 5) {
		BinaryTreeNode *node;
		dequeueBinaryTreeNodeQueueVal(queue3, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "9");
		dequeueBinaryTreeNodeQueueVal(queue3, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "7");
		dequeueBinaryTreeNodeQueueVal(queue3, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "2");
		dequeueBinaryTreeNodeQueueVal(queue3, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "8");
		dequeueBinaryTreeNodeQueueVal(queue3, &node);
		CU_ASSERT_STRING_EQUAL(node->data->strval, "4");
	}
}

/**
 * Test all the functions for this application.
 *
 * @return test error code
 */
static int test_all(void) {
	// initialize the CUnit test registry -- only once per application
	CU_initialize_registry();

	// add a suite to the registry with no init or cleanup
	CU_pSuite pSuite = CU_add_suite("function_tests", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "test_toInfix", test_toInfix_Callback);
	CU_add_test(pSuite, "test_toPrefix", test_toPrefix_Callback);
	CU_add_test(pSuite, "test_toPostFix", test_toPostfix_Callback);
	CU_add_test(pSuite, "test_getLeafNodes", test_getLeafNodes_Callback);

	// run all test suites using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	// display information on failures that occurred
	CU_basic_show_failures(CU_get_failure_list());

	// Clean up registry and return status
	CU_cleanup_registry();
	return CU_get_error();
}

/**
 * Main program to invoke test functions
 *
 * @return the exit status of the program
 */
int main(void) {

	// test all the functions
	CU_ErrorCode code = test_all();

	return (code == CUE_SUCCESS) ? EXIT_SUCCESS : EXIT_FAILURE;
}
