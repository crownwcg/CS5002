/*
 * linked_list_crawler.c
 *
 * This file includes implementation of the ArrayListCrawler functions.
 *
 *  Created on: Nov 1, 2017
 *  Author: philip gust
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist_crawler.h"

/**
 * Create and initialize new crawler with the given callback.
 *
 * @param list the ArrayList to crawl
 * @param cb the callback for this crawler
 * @return an crawler for the list
 */
ArrayListCrawler* createArrayListCrawler(ArrayList* theList, ArrayListCrawlerCallback cb) {
	ArrayListCrawler *crawler = malloc(sizeof(ArrayListCrawler));

	crawler->callback = cb;
	crawler->itr = createArrayListIterator(theList);
	crawler->callbackData = NULL;
	return crawler;
}

/**
 * Delete the crawler by freeing its storage.
 *
 * @param crawler the ArrayListCrawler to delete
 */
void deleteArrayListCrawler(ArrayListCrawler* crawler) {
		deleteArrayListIterator(crawler->itr);
		crawler->itr = NULL;
		crawler->callback = NULL;
		crawler->callbackData = NULL;

		free(crawler);
}

/**
 * Start crawling the ArrayList with the specified data
 *
 * @param crawler the ArrayListCrawler to start
 * @param the data for the callback function
 * @return true if crawler ran to completion, false if stopped early
 */
bool startArrayListCrawler(ArrayListCrawler *crawler, void *data) {
	// initialize the callback data
	crawler->callbackData = data;

	// loop until iterator has completed
	const char *val;
	while (getNextArrayListIteratorVal(crawler->itr, &val)) {
        // call callback to perform function
		if (!crawler->callback(crawler)) {
			return false;	// function signals early completion
		}
	}
	return true;
}

/**
 * Determines whether this is the first call from the crawler since last reset.
 *
 * @param crawler the ArrayListCrawler
 * @return true if successful, false if not supported
 */
bool isFirstArrayListCrawlerVal(ArrayListCrawler *crawler) {
	return (getArrayListCrawlerCount(crawler) == 1);
}

/**
 * Determines whether there will be another call from the crawler
 *
 * @param itr the ArrayListIterator
 * @return true if there is another value, false otherwise
 */
bool hasNextArrayListCrawlerVal(ArrayListCrawler *crawler) {
	return hasNextArrayListIteratorVal(crawler->itr);
}

/**
 * Returns the number of values returned so far.
 *
 * @param itr the ArrayListIterator
 * @return the number of values returned so far
 */
size_t getArrayListCrawlerCount(ArrayListCrawler *crawler) {
	return getArrayListIteratorCount(crawler->itr);
}

/**
 * Returns the number of values available.
 *
 * @param itr the ArrayListIterator
 * @return available number of values or UNAVAILABLE if cannot perform operation.
 */
size_t getArrayListCrawlerAvailable(ArrayListCrawler *crawler) {
	return getArrayListIteratorAvailable(crawler->itr);
}

/**
 * Resets the linked list crawler to the head of the list.
 * Allows the crawler to be restarted within the callback
 * or restarted outside the callback.
 *
 * @param crawler the ArrayListCrawler
 * @return true if successful, false if not supported
 */
bool resetArrayListCrawler(ArrayListCrawler *crawler) {
	return resetArrayListIterator(crawler->itr);
}

/**
 * Gets the crawler callback data. Enables callback function
 * to get shared data across multiple callbacks. Also enables
 * final data to be recovered after crawling has completed.
 *
 * @param crawler the ArrayListCrawler
 * @return the crawler data
 */
void *getArrayListCrawlerCallbackData(ArrayListCrawler *crawler) {
	return crawler->callbackData;
}

/**
 * Sets the crawler callback data. Enables callback function
 * to update shared data across multiple callbacks.
 *
 * @param crawler the ArrayListCrawler
 * @param data the ArrayListCrawler data
 * @return the crawler data
 */
void setArrayListCrawlerCallbackData(ArrayListCrawler *crawler, void *data) {
	crawler->callbackData = data;
}

/**
 * Gets current link value in the linked list.
 *
 * @param itr the ArrayListIterator
 * @param val result parameter is pointer to result value location;  cannot be null
 * @return the current linked list value
 */
bool getArrayListCrawlerVal(ArrayListCrawler* crawler, const char **val) {
	if (getArrayListValAt(crawler->itr->theList, crawler->itr->curNode - 1, val))   // need iterator function?
		return true;
	return false;
}
 /**
* Gets value in the linked list at the index.
*
* @param itr the ArrayListIterator
* @param index the index
* @param val result parameter is pointer to result value location;
*   cannot be null
* @return true if previous value returned, false if iterator is at end of list
*/
bool getArrayListCrawlerValAt(ArrayListCrawler* crawler, size_t index, const char **val) {
 return getArrayListValAt(crawler->itr->theList, index, val);
}

/**
* Sets the current linked list value
*
* @param crawler the ArrayListCrawler
* @param val result parameter is pointer to result value location;
*   cannot be null
* @return true if current value was set, false otherwise
*/
bool setArrayListCrawlerVal(ArrayListCrawler* crawler, const char *val) {
	if (val != NULL)  {    // need iterator function?
	    if (setArrayListValAt(crawler->itr->theList, crawler->itr->curNode - 1, val))
	    		return true;
	}
	return false;
}

/**
* Sets the linked list value at the index
*
* @param crawler the ArrayListCrawler
* @param index the index
* @param val result parameter is pointer to result value location;
*   cannot be null
* @return true if current value was set, false otherwise
*/
bool setArrayListCrawlerValAt(ArrayListCrawler* crawler, size_t index, const char *val) {
   return setArrayListValAt(crawler->itr->theList, index, val);
}

