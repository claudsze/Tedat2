#include <stdio.h>
#include <string.h>
#include <time.h>

#include "bt.h"

#define DEPTH 4
#define N_ELEMENTS 31

/* Output for a correct implementation (these tests are not exhaustive):

$ ./test_prune
Original tree:   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31
Pruned tree:   4   8  12  16  20  24  28
*/

void int_print(const void *e) { fprintf(stdout, "%3d ", *((int *)e)); }

int main(int argc, char *argv[]) {
  int i = 0;
  int numbers[N_ELEMENTS], *numbers_p[N_ELEMENTS];
  BT *bt = NULL;

  for (i = 0; i < N_ELEMENTS; i++) {
    numbers[i] = i + 1;
    numbers_p[i] = numbers + i;
  }

  bt = bt_build_complete(DEPTH, (void **)numbers_p);
  if (bt == NULL) {
    return EXIT_FAILURE;
  }

  printf("Original tree: ");
  bt_inorder(bt, int_print);
  printf("\n");

  if (bt_prune(bt, DEPTH - 2) == ERROR) {
    bt_free(bt);
    return EXIT_FAILURE;
  }

  printf("Pruned tree: ");
  bt_inorder(bt, int_print);
  printf("\n");

  bt_free(bt);

  return EXIT_SUCCESS;
}
