/**
 * @file list.h
 * @brief Public interface for List implementation.
 *
 * The List admits arbitrary elements, received as pointers to void.
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

typedef struct _List List;

List *list_new();

Boolean list_is_empty(const List *pl);

Status list_push_front(List *pl, const void *e);

Status list_push_back(List *pl, const void *e);

void *list_pop_front(List *pl);

void *list_pop_back(List *pl);

/**
 * @brief Extract the minimum element of the List.
 *
 * @param pl List.
 * @param ele_cmp Function to compare elements.
 * @return Extracted element, NULL if the List is empty or NULL.
 */
void *list_pop_min(List *pl, int (*ele_cmp)(const void *, const void *));

void list_free(List *pl);

int list_print(FILE *fp, const List *pl, int (*ele_print)(FILE *, const void *));

#endif
