/*
 * Array2DIterator.c
 *
 * Definitions for types and function for an Array2DIterator
 * that can iterate over a 2D array of Array2DElementType.
 */

#include "array2d_iterator.h"

/**
 * Create an Array2DIterator for the array
 * @param array2D pointer to the 2D array of Array2DElementType
 * @param width the array width
 * @param height the array height
 * @param order the order of iteration
 * @return the Array2DIterator
 */
Array2DIterator* createArray2DIterator(
	Array2DElementType *array2D, size_t width, size_t height, IteratorOrder order) {
	// allocate memory for iterator and initiate its fields
	Array2DIterator *itr = (Array2DIterator *) malloc(sizeof(Array2DIterator));
	itr->array = array2D;
	itr->row = 0;
	itr->col = 0;
	itr->height = height;
	itr->width = width;
	itr->order = order;
	itr->count = 0;
	return itr;
}

/**
 * Delete the Array2DIterator by freeing its resources
 */
void deleteArray2DIterator(Array2DIterator *itr) {
	if (itr != NULL) {
		itr->array = NULL;
		itr->row = 0;
		itr->col = 0;
		itr->width = 0;
		itr->height = 0;
		itr->order = rowMajor;
		free(itr);
	}
}

/**
 * Determine whether there is a next array element.
 *
 * @param itr the Array2DIterator
 * @return true if there is a next element, false otherwise
 */
bool hasNextArray2DIteratorElement(Array2DIterator *itr) {
	return itr == NULL ? false : itr->count < itr->height * itr->width;
}

/**
 * Returns next array element.
 *
 * @param itr the Array2DIterator
 * @param elementPtr pointer to location to return next element
 * @return true next element returned through elementPtr, false otherwise
 */
bool nextArray2DIteratorElement(Array2DIterator *itr, Array2DElementType *elementPtr) {
	if (!hasNextArray2DIteratorElement(itr)) {
		return false;
	}
	if (itr->order == rowMajor) {
		if (elementPtr != NULL) *elementPtr = itr->array[itr->count++];
		itr->row = itr->count / itr->width;
		itr->col = itr->count % itr->height;
	} else {
		if (elementPtr != NULL) {
			*elementPtr = itr->array[itr->row * itr->width + itr->col];
			itr->count++;
		}
		if (itr->row < itr->height - 1) {
			itr->row++;
		} else {
			itr->col++;
			itr->row = 0;
		}
	}
	return true;
}

/**
 * Determine whether there is a next array element.
 *
 * @param itr the Array2DIterator
 * @return true if there is a next element, false otherwise
 */
bool hasPrevArray2DIteratorElement(Array2DIterator *itr) {
	return itr == NULL ? false : itr->count > 0;
}

/**
 * Returns previous array element.
 *
 * @param itr the Array2DIterator
 * @param elementPtr pointer to location to return previous element
 * @return true previous element returned through elementPtr, false otherwise
 */
bool prevArray2DIteratorElement(Array2DIterator *itr, Array2DElementType *elementPtr) {
	if (!hasPrevArray2DIteratorElement(itr)) return false;
	if (itr->order == rowMajor) {
		if (elementPtr != NULL) *elementPtr = itr->array[--itr->count];
		itr->row = itr->count / itr->width;
		itr->col = itr->count % itr->height;
	} else {
		if (itr->row > 0) {
			itr->row--;
		} else {
			itr->col--;
			itr->row = itr->height - 1;
		}
		if (elementPtr != NULL) {
			*elementPtr = itr->array[itr->row * itr->width + itr->col];
			itr->count--;
		}
	}
	return true;
}

/**
 * Reset the iterator to the beginning of the 2D array.
 *
 * @param itr the Array2DIterator
 */
void resetArray2DIterator(Array2DIterator *itr) {
	itr->count = 0;
	itr->row   = 0;
	itr->col   = 0;
}

/**
 * Return the number of elements already returned.
 * The sum of count and available is the array size,
 *
 * @param the Array2DIterator
 * @param the position of the iterator in the array
 */
size_t getArray2DIteratorCount(Array2DIterator *itr) {
	return itr == NULL ? 0 : itr->count;
}

/**
 * Return the number of elements available.
 * The sum of count and available is the array size.
 *
 * @param itr the Array2DIterator
 * @return the number of elements available
 */
size_t getArray2DIteratorAvailable(Array2DIterator *itr) {
	return itr == NULL ? 0 : itr->width * itr->height - itr->count;
}
