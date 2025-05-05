/**
 * @file bt.c
 * @brief BT implementation with (void *).
 *
 */
#include "bt.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

#define info(pn) ((pn)->info)
#define left(pn) ((pn)->left)
#define right(pn) ((pn)->right)

#define root(pt) ((pt)->root)

struct _Node {
  void *info;
  struct _Node *left;
  struct _Node *right;
};

typedef struct _Node Node;

struct _BT {
  Node *root;
};

Node *node_new() {
  Node *pn = NULL;

  pn = (Node *)malloc(sizeof(Node));
  if (pn == NULL) {
    return NULL;
  }

  info(pn) = left(pn) = right(pn) = NULL;

  return pn;
}

BT *bt_new() {
  BT *pt = NULL;

  pt = (BT *)malloc(sizeof(BT));
  if (pt == NULL) {
    return NULL;
  }

  root(pt) = NULL;

  return pt;
}

Boolean bt_is_empty(const BT *pt) {
  if (pt == NULL) {
    return TRUE;
  }

  if (root(pt) == NULL) {
    return TRUE;
  }

  return FALSE;
}

void _bt_free_rec(Node *pn);

void bt_free(BT *pt) {
  if (pt == NULL) {
    return;
  }

  _bt_free_rec(root(pt));

  free((void *)pt);
}

void _bt_free_rec(Node *pn) {
  if (pn == NULL) {
    return;
  }

  _bt_free_rec(left(pn));
  _bt_free_rec(right(pn));
  free((void *)pn);
}

void _bt_inorder_rec(Node *pn, void (*ele_visit)(const void *));

void bt_inorder(BT *pt, void (*ele_visit)(const void *)) {
  if ((pt == NULL) || (ele_visit == NULL)) {
    return;
  }

  _bt_inorder_rec(root(pt), ele_visit);
}

void _bt_inorder_rec(Node *pn, void (*ele_visit)(const void *)) {
  if (pn == NULL) {
    return;
  }

  _bt_inorder_rec(left(pn), ele_visit);
  ele_visit(info(pn));
  _bt_inorder_rec(right(pn), ele_visit);
}

Node *_bt_build_complete_rec(int depth, void **elements, int *counter);

BT *bt_build_complete(int depth, void **elements) {
  int counter = 0;
  BT *pt = NULL;

  if (elements == NULL) {
    return NULL;
  }

  if ((pt = bt_new()) == NULL) {
    return NULL;
  }

  root(pt) = _bt_build_complete_rec(depth, elements, &counter);

  return pt;
}

Node *_bt_build_complete_rec(int depth, void **elements, int *counter) {
  Node *pn = NULL;

  if ((depth < 0) || (counter == NULL) || (elements == NULL)) {
    return NULL;
  }

  pn = node_new();
  if (pn == NULL) {
    return NULL;
  }

  left(pn) = _bt_build_complete_rec(depth - 1, elements, counter);

  info(pn) = elements[*counter];
  (*counter)++;

  right(pn) = _bt_build_complete_rec(depth - 1, elements, counter);

  return pn;
}

/*<START_CODE>*/

Status bt_prune(BT *pt, int max_depth) {
  return ERROR; /* Substitute this line by the function implementation. */
}

/*<END_CODE>*/