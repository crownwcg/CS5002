/*
 * linked_list_crawler_main.c
 *
 * This file exercises the singly linked list and singly linked list
 * crawler functions.
 *
 * @since 2017-02-14
 * @author philip gust
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "arraylist_crawler.h"

/**
 * Print "visited" for each value in the list
 * @param crawler the crawler
 * @return true to continue crawling
 */
bool visitedCallback(ArrayListCrawler *crawler) {
	printf("visited\n");
	return true;
}

/**
 * Print the list values as a comma-separated list in parens.
 * @param crawler the crawler
 * @return true to continue crawling
 */
bool printListCallback(ArrayListCrawler *crawler) {
	// print start of list
	if (isFirstArrayListCrawlerVal(crawler)) {
		printf("( ");
	}
	// print current value
	const char* val;
	getArrayListCrawlerVal(crawler, &val);
	printf("\"%s\"", val);

	// print list item separator or end of list
	if (hasNextArrayListCrawlerVal(crawler)) {
		printf(", ");
	} else {
		printf(" )\n");
	}
	return true;
}

/**
 * Finds the largest string in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool getMaxValCallback(ArrayListCrawler *crawler) {
	const char *maxVal = getArrayListCrawlerCallbackData(crawler);
	const char *curVal;
	getArrayListCrawlerVal(crawler, &curVal);
	// first value or larger value
	if (maxVal == NULL || strcmp(curVal, maxVal) > 0) {
		setArrayListCrawlerCallbackData(crawler, (void*)curVal);
	}
	return true;
}

/**
 * Computes the aggregate length of the strings in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool getStrLenCallback(ArrayListCrawler *crawler) {
	size_t *len = getArrayListCrawlerCallbackData(crawler);
	const char *curVal;
	getArrayListCrawlerVal(crawler, &curVal);
	*len += strlen(curVal);
	return true;
}

/**
 * Finds the a string in the list
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool findStrCallback(ArrayListCrawler *crawler) {
	char *targetVal = getArrayListCrawlerCallbackData(crawler);
	const char *curVal;
	getArrayListCrawlerVal(crawler, &curVal);
	return (strcmp(targetVal, curVal) != 0);
}

/**
 * Transliterates characters in list strings
 * @param crawler the crawler
 * @param true to continue crawling
 */
bool translitCallback(ArrayListCrawler *crawler) {
	const char **xlit = getArrayListCrawlerCallbackData(crawler);
	const char *curVal;
	getArrayListCrawlerVal(crawler, &curVal);

	// transliterate curVal chars found in xlit[0] to ones in xlit[1]
	size_t len = strlen(curVal);
	char lcstr[len+1];
	for (int i = 0; i < len; i++) {
		const char *p = strchr(xlit[0], curVal[i]);
		lcstr[i] = (p == NULL) ? curVal[i] : xlit[1][p-xlit[0]];
	}
	lcstr[len] = '\0';
	setArrayListCrawlerVal(crawler, lcstr);
	return true;
}

/**
 * This function exercises some of the linked list operations.
 */
int main(void) {
	printf("Initial list\n");
	ArrayList *list = createArrayList(4, 8);
	printArrayList(list);
	printf("list size: %lu\n", arrayListSize(list));

	// add 5 nodes to the list
	printf("\nAdding 5 values to list\n");
	addLastArrayListVal(list, "A");
	addLastArrayListVal(list, "B");
	addLastArrayListVal(list, "C");
	addLastArrayListVal(list, "B");
	addLastArrayListVal(list, "A");
	printArrayList(list);

	printf("list size: %lu\n", arrayListSize(list));

	printf("\ncrawler with visitedCallback\n");
	ArrayListCrawler *crawler = createArrayListCrawler(list, visitedCallback);
	printf("iterator count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("iterator avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	bool result = startArrayListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	deleteArrayListCrawler(crawler);

	// use callback to print list of strings in list
	printf("\ncrawler with printListCallback\n");
	crawler = createArrayListCrawler(list, printListCallback);
	result = startArrayListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	deleteArrayListCrawler(crawler);

	// use callback to get the maximum string in list
	printf("\ncrawler with getMaxValCallback\n");
	crawler = createArrayListCrawler(list, getMaxValCallback);
	result = startArrayListCrawler(crawler, NULL);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("callback found max value \"%s\"\n", getArrayListCrawlerCallbackData(crawler));
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	deleteArrayListCrawler(crawler);

	// use callback to get the aggregate length of strings in list
	printf("\ncrawler with getStrLenCallback\n");
	crawler = createArrayListCrawler(list, getStrLenCallback);
	size_t count = 0;
	result = startArrayListCrawler(crawler, &count);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printf("length of list strings: %lu\n", count);
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	deleteArrayListCrawler(crawler);

	// use callback to find string in list
	printf("\ncrawler with findStrCallback\n");
	crawler = createArrayListCrawler(list, findStrCallback);
	size_t found = 0;
	const char *lookingFor = "B";
	for ( ; startArrayListCrawler(crawler, (void*)lookingFor) == false; found++) {
		size_t foundAt = getArrayListCrawlerCount(crawler)-1;
		printf("index of \"%s\" is: %lu\n", lookingFor, foundAt);
	}
	printf("found %lu occurrences of \"%s\"\n", found, lookingFor);
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));
	deleteArrayListCrawler(crawler);

	// use callback to transliterate characters in list strings
	printf("\ncrawler with translitCallback\n");
	crawler = createArrayListCrawler(list, translitCallback);
	const char *toLowerCase[2] = {
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
			"abcdefghijklmnopqrstuvwxyz"
	};
	result = startArrayListCrawler(crawler, toLowerCase);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printArrayList(list);
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));

	printf("\ncrawler with translitCallback\n");
	const char *toUpperCase[2] = {
			"abcdefghijklmnopqrstuvwxyz",
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	};
	// must reset crawler to start at beginning of list
	resetArrayListCrawler(crawler);
	result = startArrayListCrawler(crawler, toUpperCase);
	printf("crawler returned: %s\n", result ? "true" : "false");
	printArrayList(list);
	printf("crawler count: %lu\n", getArrayListCrawlerCount(crawler));
	printf("crawler avail: %lu\n", getArrayListCrawlerAvailable(crawler));

	deleteArrayListCrawler(crawler);

	return EXIT_SUCCESS;
}

