/**
 * @file duplicate.h
 * @brief Interface for a utility to check repeated numbers in a sorted array.
 *
 */
#ifndef DUPLICATE_H
#define	DUPLICATE_H

#include "types.h"

/**
 * @brief Check efficiently if a number is duplicate in a sorted array.
 *
 * @param e Number.
 * @param t Sorted array, in ascending order.
 * @param size Size of the array.
 * @return Boolean value TRUE if the number is repeated in the array, Boolean value FALSE
 * otherwise (or in case of error).
 */
Boolean is_duplicate(int e, int *t, int size);

#endif