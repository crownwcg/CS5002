/*
 * Array2DIterator.h
 *
 * Declarations for types and function for an Array2DIterator
 * that can iterate over a 2D array of Array2DElementType.
 */

#ifndef ARRAY2D_ITERATOR_H_
#define ARRAY2D_ITERATOR_H_

#include <stdbool.h>
#include <stdlib.h>

/** Type of 2D array element */
typedef int Array2DElementType;

/** The order of iteration */
typedef enum { rowMajor, columnMajor } IteratorOrder;

/** The iterator state information */
typedef struct {
	Array2DElementType *array;
	IteratorOrder       order;
	int row;
	int col;
	size_t width;
	size_t height;
	size_t count;
} Array2DIterator;

/**
 * Create an Array2DIterator for the array.
 *
 * @param array2D pointer to the 2D array of Array2DElementType
 * @param width the array width
 * @param height the array height
 * @param order the order of iteration
 * @return the Array2DIterator
 */
Array2DIterator* createArray2DIterator(
	Array2DElementType *array2D, size_t width, size_t height, IteratorOrder order);

/**
 * Delete the Array2DIterator by freeing its resources
 */
void deleteArray2DIterator(Array2DIterator *itr);

/**
 * Determine whether there is a next array element.
 *
 * @param itr the Array2DIterator
 * @return true if there is a next element, false otherwise
 */
bool hasNextArray2DIteratorElement(Array2DIterator *itr);

/**
 * Returns next array element.
 *
 * @param itr the Array2DIterator
 * @param elementPtr pointer to location to return next element
 * @return true next element returned through elementPtr, false otherwise
 */
bool nextArray2DIteratorElement(Array2DIterator *itr, Array2DElementType *elementPtr);

/**
 * Determine whether there is a next array element.
 *
 * @param itr the Array2DIterator
 * @return true if there is a next element, false otherwise
 */
bool hasPrevArray2DIteratorElement(Array2DIterator *itr);

/**
 * Returns previous array element.
 *
 * @param itr the Array2DIterator
 * @param elementPtr pointer to location to return previous element
 * @return true previous element returned through elementPtr, false otherwise
 */
bool prevArray2DIteratorElement(Array2DIterator *itr, Array2DElementType *elementPtr);

/**
 * Reset the iterator to the beginning of the 2D array.
 *
 * @param itr the Array2DIterator
 */
void resetArray2DIterator(Array2DIterator *itr);

/**
 * Return the number of elements already returned.
 * The sum of count and available is the array size,
 *
 * @param the Array2DIterator
 * @param the position of the iterator in the array
 */
size_t getArray2DIteratorCount(Array2DIterator *itr);

/**
 * Return the number of elements available.
 * The sum of count and available is the array size.
 *
 * @param itr the Array2DIterator
 * @return the number of elements available
 */
size_t getArray2DIteratorAvailable(Array2DIterator *itr);

#endif /* ARRAY2D_ITERATOR_H_ */
