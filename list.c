/**
 * @file list.c
 * @brief List implementation with (void *).
 *
 */
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

struct _Node {
  void *info;
  struct _Node *next;
};

typedef struct _Node Node;

struct _List {
  Node *first;
};

Node *node_new() {
  Node *pn = NULL;

  pn = (Node *)malloc(sizeof(Node));
  if (pn == NULL) {
    return NULL;
  }

  pn->info = NULL;
  pn->next = NULL;

  return pn;
}

List *list_new() {
  List *pl = NULL;

  pl = (List *)malloc(sizeof(List));
  if (pl == NULL) {
    return NULL;
  }

  pl->first = NULL;

  return pl;
}

Boolean list_is_empty(const List *pl) {
  if (pl == NULL) {
    return TRUE;
  }

  if (pl->first == NULL) {
    return TRUE;
  }

  return FALSE;
}

Status list_push_front(List *pl, const void *e) {
  Node *pn = NULL;

  if ((pl == NULL) || (e == NULL)) {
    return ERROR;
  }

  pn = node_new();
  if (pn == NULL) {
    return ERROR;
  }

  pn->info = (void *)e;

  pn->next = pl->first;
  pl->first = pn;

  return OK;
}

Status list_push_back(List *pl, const void *e) {
  Node *pn = NULL, *pn_last = NULL;

  if ((pl == NULL) || (e == NULL)) {
    return ERROR;
  }

  pn = node_new();
  if (pn == NULL) {
    return ERROR;
  }

  pn->info = (void *)e;

  if (list_is_empty(pl) == TRUE) {
    pl->first = pn;
    return OK;
  }

  pn_last = pl->first;
  while (pn_last->next != NULL) {
    pn_last = pn_last->next;
  }
  pn_last->next = pn;

  return OK;
}

void *list_pop_front(List *pl) {
  void *e = NULL;
  Node *pn = NULL;

  if ((pl == NULL) || (list_is_empty(pl) == TRUE)) {
    return NULL;
  }

  pn = pl->first;
  e = pn->info;
  pl->first = pn->next;

  free((void *)pn);

  return e;
}

void *list_pop_back(List *pl) {
  void *e = NULL;
  Node *pn = NULL;

  if ((pl == NULL) || (list_is_empty(pl) == TRUE)) {
    return NULL;
  }

  if (pl->first->next == NULL) {
    e = pl->first->info;
    free((void *)pl->first);
    pl->first = NULL;

    return e;
  }

  pn = pl->first;
  while (pn->next->next != NULL) {
    pn = pn->next;
  }

  e = pn->next->info;
  free((void *)pn->next);
  pn->next = NULL;

  return e;
}

/*<START_CODE>*/

void *list_pop_min(List *pl, int (*ele_cmp)(const void *, const void *)) {
  Node *aux = NULL, *prev_aux = NULL;
  Node *min = NULL, *min_prev = NULL;
  void *elem = NULL;

  if(!pl || !ele_cmp){
    return NULL;
  }

  if(list_is_empty(pl) == TRUE){
    return NULL;
  }

  min = pl->first;
  aux = pl->first;

  /*Buscamos el minimo de la lista*/
  while (aux != NULL){
    if(ele_cmp(aux->info, min->info) < 0){
      min = aux;
      min_prev = prev_aux;
    }
    prev_aux = aux;
    aux = aux->next;
  }

  /*Borramos el minimo de la lista*/
  if(min_prev == NULL){
    pl->first = min->next;
  } else {
    min_prev->next = min->next;
  }

  /*Copiamos la informacion y liberamos el nodo*/
  elem = min->info;
  free(min);
  return elem;
}

/*<END_CODE>*/

void list_free(List *pl) {
  if (pl == NULL) {
    return;
  }

  while (list_is_empty(pl) == FALSE) {
    list_pop_front(pl);
  }

  free((void *)pl);
}

int list_print(FILE *fp, const List *pl, int (*ele_print)(FILE *, const void *)) {
  int return_value = 0;
  int val = 0;
  Node *pn = NULL;

  if ((pl == NULL) || (fp == NULL) || (ele_print == NULL)) {
    return -1;
  }

  pn = pl->first;
  while (pn != NULL) {
    val = (*(ele_print))(fp, pn->info);
    if (val < 0) {
      return val;
    }
    return_value += val;
    pn = pn->next;
  }

  return return_value;
}