/**
 * @file bt.h
 * @brief Public interface for BT implementation.
 *
 * The BT admits arbitrary elements, received as pointers to void.
 *
 */

#ifndef BT_H
#define BT_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

typedef struct _BT BT;

BT *bt_new();

Boolean bt_is_empty(const BT *pt);

void bt_free(BT *pt);

void bt_inorder(BT *pt, void (*ele_visit)(const void *));

BT *bt_build_complete(int depth, void **elements);

/**
 * @brief Prune the Tree to the specified depth.
 *
 * @param pt Tree.
 * @param max_depth Maximum depth.
 * @return Status, OK or ERROR depending on whether the prune was successful.
 */
Status bt_prune(BT *pt, int max_depth);

#endif