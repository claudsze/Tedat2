/**
 * @file duplicate.c
 * @brief Implementation of a utility to check repeated numbers in a sorted array.
 *
 */
#include <stdlib.h>

#include "duplicate.h"
#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

/*<START_CODE>*/

Boolean is_duplicate_rec(int e, int *t, int left, int right, int size)
{
  int mid;

  if (left > right) {
    return FALSE;
  }

  mid = left + (right - left) / 2;

  if (t[mid] == e) {
    if ((mid > 0 && t[mid - 1] == e) || (mid < size - 1 && t[mid + 1] == e)) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  } else if (t[mid] < e) {
    return is_duplicate_rec(e, t, mid + 1, right, size);
  } else {
    return is_duplicate_rec(e, t, left, mid - 1, size);
  }
}

Boolean is_duplicate(int e, int *t, int size)
{
  if (t == NULL || size == 0)
  {
    return FALSE;
  }
  return is_duplicate_rec(e, t, 0, size - 1, size);
}

/*<END_CODE>*/