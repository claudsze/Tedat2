/**
 * @file count.c
 * @brief Implementation of stack count utilities.
 *
 */
#include "count.h"

#include "stack.h"
#include "types.h"

/* ALL THE CODE must between written between the <START_CODE> and <END_CODE>
tags. Auxiliary functions can also be defined between those lines.
*/

#define COUNT_ERROR -1

/*<START_CODE>*/

int stack_count_if(Stack *stack, Boolean (*ele_check)(void *)) {
  Stack *tmp=NULL;
  int count=0;
  void *element=NULL;

  if (!stack||!ele_check){
    return -1;
  }

  tmp = stack_new();

  /*Sacamos los elementos de stack y los copiamos en un stack temporal*/
  while(!stack_is_empty(stack)){
    element = stack_pop(stack);
    stack_push(tmp, element);

    /*Miramos si ese elemento cumple la condidion*/
    if(ele_check(element)){
      count++;
    }
  }

  /*Copiamos de nuevo los elementos a la pila original*/
  while(!stack_is_empty(tmp)){
    element = stack_pop(tmp);
    stack_push(stack, element);
  }

  stack_free(tmp);

  return count;
}

/*<END_CODE>*/