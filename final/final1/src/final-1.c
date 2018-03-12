/*
 * final-1.c
 *
 * This problem tests your understanding of iterators by asking you
 * to implement a reversible iterator for a 2D array that can iterate
 * in either row major or column major order
 *
 * Fill in the fields in the Array2DIterator in array2d_iterator.h,
 * and implement the functions in array2d_i
 * terator.c.
 *
 *  CS 5002 Fall 2017 Silicon Valley
 *  Final Problem 1
 */
#include <stdio.h>
#include <limits.h>

#include "array2d_iterator.h"

/**
 * Test a Array2DIterator.
 * Returns number of errors reported
 */
size_t testArray2DIterator(Array2DIterator *itr, size_t size, int *results, const char *order) {
	size_t errors = 0;

	// ensure iterator has not expired
	if (!hasNextArray2DIteratorElement(itr)) {
		printf("%s Array2DIterator count: %d: hasNext returned false, expected true\n", order, 0);
		return ++errors;
	}

	// verify iterator count
	size_t itrCount = getArray2DIteratorCount(itr);
	if (0 != itrCount) {
		printf("%s Array2DIterator count: %d: getCount returned count: %lu\n", order, 0, itrCount);
		return ++errors;
	}

	// verify iterator available
	size_t itrAvail = getArray2DIteratorAvailable(itr);
	if (size != itrAvail) {
		printf("%s Array2DIterator count: %d: getAvail returned available: %lu\n, expected %lu\n", order, 0, itrAvail, size);
		return ++errors;
	}

	for (int count = 1; count <= size; count++) {
		// ensure there is a next element
		if (!hasNextArray2DIteratorElement(itr)) {
			printf("%s Array2DIterator count: %d: hasNext returned false, expected true\n", order, count);
			++errors;
			break;
		}
		// get next element
		int val = INT_MAX;
		if (!nextArray2DIteratorElement(itr, &val)) {
			printf("%s Array2DIterator count: %d: next returned false, expected true\n", order, count);
			++errors;
			break;
		}

		// verify iterator count
		itrCount = getArray2DIteratorCount(itr);
		if (count != itrCount) {
			printf("%s Array2DIterator count: %d: getCount returned count: %lu\n", order, count, itrCount);
			++errors;
		}

		// verify iterator available
		itrAvail = getArray2DIteratorAvailable(itr);
		if (size-count != itrAvail) {
			printf("%s Array2DIterator count: %d: getAvail returned available: %lu\n, expected %lu\n", order, count, itrAvail, size-count);
			++errors;
		}

		// ensure value
		if (val != results[count-1]) {
			printf("%s Array2DIterator count: %d: value: %d, expected %d\n", order, count, val, results[count]);
			++errors;
		}
	}
	// ensure iterator has expired
	if (hasNextArray2DIteratorElement(itr)) {
		printf("%s Array2DIterator count: %lu: hasNext returned true, expected false\n", order, size);
		++errors;
	}
	// verify iterator count
	itrCount = getArray2DIteratorCount(itr);
	if (size != itrCount) {
		printf("%s Array2DIterator count: %lu: getCount returned count: %lu\n", order, size, itrCount);
		return ++errors;
	}

	// verify iterator available
	itrAvail = getArray2DIteratorAvailable(itr);
	if (0 != itrAvail) {
		printf("%s Array2DIterator count: %d: getAvail returned available: %lu\n, expected %d\n", order, 0, itrAvail, 0);
		return ++errors;
	}

	// iterate backwards
	for (int count = size-1; count >= 0; count--) {
		// ensure there is a next element
		if (!hasPrevArray2DIteratorElement(itr)) {
			printf("%s Array2DIterator count: %d: hasPrev returned false, expected true\n", order, count);
			++errors;
			break;
		}
		// get prev element
		int val = INT_MAX;
		if (!prevArray2DIteratorElement(itr, &val)) {
			printf("%s Array2DIterator count: %d: prev returned false, expected true\n", order, count);
			++errors;
			break;
		}

		// verify iterator count
		itrCount = getArray2DIteratorCount(itr);
		if (count != itrCount) {
			printf("%s Array2DIterator count: %d: getCount returned count: %lu\n", order, count, itrCount);
			++errors;
		}

		// verify iterator available
		itrAvail = getArray2DIteratorAvailable(itr);
		if (size-count != itrAvail) {
			printf("%s Array2DIterator count: %d: getAvail returned available: %lu\n, expected %lu\n", order, count, itrAvail, size-count);
			++errors;
		}

		// ensure value
		if (val != results[count]) {
			printf("%s Array2DIterator count: %d: value: %d, expected %d\n", order, count, val, results[count]);
			++errors;
		}
	}

	// ensure reverse iterator expired
	if (hasPrevArray2DIteratorElement(itr)) {
		printf("%s Array2DIterator count: %lu: hasPrev returned true, expected false\n", order, size);
		++errors;
	}
	// verify iterator count
	itrCount = getArray2DIteratorCount(itr);
	if (0 != itrCount) {
		printf("%s Array2DIterator count: %d: getCount returned count: %lu\n", order, 0, itrCount);
		++errors;
	}

	// verify iterator available
	itrAvail = getArray2DIteratorAvailable(itr);
	if (size != itrAvail) {
		printf("%s Array2DIterator count: %d: getAvail returned available: %lu\n, expected %lu\n", order, 0, itrAvail, size);
		++errors;
	}

	return errors;
}

/**
 * Test functions.
 */
int main(void) {
	size_t rows = 2;
	size_t cols = 3;
	int testArray[2][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};

	int rowMajorResults[] = { 1, 2, 3, 4, 5, 6 };
	int colMajorResults[] = { 1, 4, 2, 5, 3, 6 };

	printf("*** Start problem 1\n\n");
	Array2DIterator *rowMajorItr =
		createArray2DIterator((int *)testArray, cols, rows, rowMajor);
	size_t errors = testArray2DIterator(rowMajorItr, rows*cols, (int*)rowMajorResults, "rowMajor");
	printf("test rowMajor: %lu error(s)\n", errors);
	deleteArray2DIterator(rowMajorItr);

	Array2DIterator *colMajorItr =
		createArray2DIterator((int *)testArray, cols, rows, columnMajor);
	errors = testArray2DIterator(colMajorItr, rows*cols, (int*)colMajorResults, "columnMajor");
	printf("test colMajor: %lu error(s)\n", errors);
	deleteArray2DIterator(colMajorItr);

	printf("\n*** End problem 1");

	return EXIT_SUCCESS;
}
