#include <stdio.h>
#include <stdlib.h>

#include "duplicate.h"

#define N_NUMBERS 10

/* Output for a correct implementation (these tests are not exhaustive):

$ ./test_duplicate
0 is not duplicate
1 is not duplicate
2 is not duplicate
3 is not duplicate
4 is duplicate
5 is not duplicate
6 is not duplicate
7 is not duplicate
8 is not duplicate
9 is duplicate
*/

int main(int argc, char *argv[]) {
  int i;
  int numbers[] = {1, 2, 3, 4, 4, 9, 9, 9, 10, 50};

  for (i = 0; i < 10; i++) {
    if (is_duplicate(i, numbers, sizeof(numbers) / sizeof(numbers[0]))) {
      printf("%d is duplicate\n", i);
    } else {
      printf("%d is not duplicate\n", i);
    }
  }

  return EXIT_SUCCESS;
}