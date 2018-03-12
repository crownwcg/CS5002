/*
 * map_entry.c
 *
 *
 * This file contains implementations of comparison and hashing
 * functions for a Map.
 * *
 * @since 2017-03-22
 * @author philip gust
 */

#include <stdio.h>
#include <string.h>
#include "map_entry.h"

/**
 * Compares two MapEntry objects.
 *
 * @param entry1 the first MapEntry
 * @param entry2 the second MapEntry
 * @return < 0 if entry1 < entry2, =0 if entry1 == entry2, >0 if entry1 > entry2
 */
int compareMapEntry(MapEntry* entry1, MapEntry* entry2) {
	return strcmp(entry1->key, entry2->key);
}

/**
 * Compares two MapKey objects.
 *
 * @param key1 the first Mapkey
 * @param key2 the second MapKey
 * @return < 0 if key1 < key2, =0 if key1 == key2, >0 if key1 > key2
 */
int compareMapKey(MapKey key1, MapKey key2) {
	return strcmp((const char*)key1, (const char*)key2);
}

/**
 * Compares two MapValue objects.
 *
 * @param val1 the first MapValue
 * @param val2 the second MapValue
 * @return < 0 if val1 < val2, =0 if val1 == val2, >0 if val1 > val2
 */
int compareMapValue(MapValue* val1, MapValue* val2) {
	return strcmp(val1->valuestr, val2->valuestr);
}

/**
 * Compute the hash code for the map entry key.
 *
 * @param key the key
 */
int getMapEntryKeyHashCode(MapKey key) {
	 // Compute the hash code for the map entry key character string.
	 // The hash code for a string is:
	 //
	 // s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
	 //
	 // using integer arithmetic, where s[i] is the i-th character of the
	 // string, n is the length of the string, and '^' is exponentiation.
	 // The hash value of the empty string is zero.
	int hashCode = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		// special handling of char required because a char
		// may be signed or unsigned in different compilers;
		// cast "reinterprets" bits of char as unsigned to
		// avoid sign-extension when adding it as an int.
		hashCode = 31 * hashCode + *(unsigned char*)&key[i];
	}
	return hashCode;
}

