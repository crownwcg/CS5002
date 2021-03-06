/*
 * binary_tree_main.c
 *
 * This file provides the unit tests for a binary tree iterator.
 *
 * @since 2017-02-15
 * @author philip gust
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "hash_set.h"
#include "hash_set_iterator.h"

HashSet* makeHashSet(char** entries, int nEntries) {
	HashSet* set = createHashSet();

	for (int i = 0; i < nEntries; i++) {
		addHashSetKey(set, entries[i]);
	}

	return set;
}

/**
 * Test of binary tree iterator for empty (NULL) expr tree
 */
static void testHashSet(void) {
	char* entries[] = {
		"key1","key3", "key4", "key2"
	};
	int nEntries = 4;
	HashSet* set = makeHashSet(entries, nEntries);
	CU_ASSERT_EQUAL(getHashSetSize(set), nEntries);

	// test all keys present
	for (int i = 0; i < nEntries; i++) {
		CU_ASSERT_TRUE(containsHashSetKey(set, entries[i]));
	}
	CU_ASSERT_FALSE(containsHashSetKey(set, "unknownKey"));

	// test iterator
	MapKey prevKey = "";
	HashSetIterator* itr = createHashSetIterator(set);
	for (int i = 0;i < nEntries; i++) {
		CU_ASSERT_TRUE(hasNextHashSetKey(itr));
		MapKey* keyptr = getNextHashSetKey(itr);
		CU_ASSERT_PTR_NOT_NULL(keyptr);
		if (keyptr != (MapKey*)NULL) {
			// make sure this key is greater than previous one;
			CU_ASSERT_TRUE(strcmp(prevKey, *keyptr) < 0);
			prevKey = *keyptr;
		}
	}
	CU_ASSERT_EQUAL(getHashSetIteratorCount(itr), nEntries);
	CU_ASSERT_EQUAL(getHashSetIteratorAvailable(itr), 0);
	deleteHashSetIterator(itr);
	CU_ASSERT_PTR_NULL(itr->mapIterator);   // dicey

	// test putAllHashSetEntries() replacing values
	char* entries2[] = {
		"key3","key2", "key4"
	};
	int nEntries2 = 3;
	HashSet* set2 = makeHashSet(entries2, nEntries2);
	CU_ASSERT_EQUAL(getHashSetSize(set2), nEntries2);

	bool changed = addAllHashSetKeys(set, set2);
	CU_ASSERT_FALSE(changed);

	bool containsAll = containsAllHashSetKeys(set, set2);
	CU_ASSERT_TRUE(containsAll);

	bool containsAll2 = containsAllHashSetKeys(set2, set);
	CU_ASSERT_FALSE(containsAll2);

	bool retainAll = retainAllHashSetKeys(set2, set);
	CU_ASSERT_FALSE(retainAll);

	bool retainAll2 = retainAllHashSetKeys(set, set2);
	CU_ASSERT_TRUE(retainAll2);
	CU_ASSERT_EQUAL(getHashSetSize(set), nEntries2);

	bool removeAll = deleteAllHashSetKeys(set, set2);
	CU_ASSERT_TRUE(removeAll);
	CU_ASSERT_EQUAL(getHashSetSize(set), 0);

	bool removeAll2 = deleteAllHashSetKeys(set2, set);
	CU_ASSERT_FALSE(removeAll2);
	CU_ASSERT_EQUAL(getHashSetSize(set2), nEntries2);

	bool retainAll3 = retainAllHashSetKeys(set2, set);
	CU_ASSERT_TRUE(retainAll3);
	CU_ASSERT_EQUAL(getHashSetSize(set2), 0);

	HashSet* set3 = makeHashSet(entries2, nEntries2);
	CU_ASSERT_EQUAL(getHashSetSize(set3), nEntries2);
	clearHashSet(set3);
	CU_ASSERT_EQUAL(getHashSetSize(set3), 0);
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
	CU_pSuite pSuite = CU_add_suite("HashSet Tests", NULL, NULL);

	// add the tests to the suite
	CU_add_test(pSuite, "testHashSet", testHashSet);

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


