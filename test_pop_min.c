#include <stdio.h>
#include <string.h>
#include <time.h>

#include "list.h"

/* Output for a correct implementation (these tests are not exhaustive):

$ ./test_pop_min
Original list:   9   3  -6 200   7  42  -5  19
Extracting  -6 =>   9   3 200   7  42  -5  19
Extracting  -5 =>   9   3 200   7  42  19
Extracting   3 =>   9 200   7  42  19
Extracting   7 =>   9 200  42  19
Extracting   9 => 200  42  19
Extracting  19 => 200  42
Extracting  42 => 200
Extracting 200 =>

Original list: hhh ggg fff eee aaa ddd ccc bbb
Extracting aaa => hhh ggg fff eee ddd ccc bbb
Extracting bbb => hhh ggg fff eee ddd ccc
Extracting ccc => hhh ggg fff eee ddd
Extracting ddd => hhh ggg fff eee
Extracting eee => hhh ggg fff
Extracting fff => hhh ggg
Extracting ggg => hhh
Extracting hhh =>
*/

int int_print(FILE *f, const void *e) { return fprintf(f, "%3d ", *((int *)e)); }

int int_cmp(const void *e1, const void *e2) { return *((int *)e1) - *((int *)e2); }

int string_print(FILE *f, const void *e) { return fprintf(f, "%s ", (char *)e); }

int string_cmp(const void *e1, const void *e2) { return strcmp((char *)e1, (char *)e2); }

int main(int argc, char *argv[]) {
  int i = 0, n_elements;
  int numbers[8] = {19, -5, 42, 7, 200, -6, 3, 9}, *number = NULL;
  char *strings[8] = {"bbb", "ccc", "ddd", "aaa", "eee", "fff", "ggg", "hhh"}, *string = NULL;
  List *list = NULL;

  list = list_new();
  if (list == NULL) {
    return EXIT_FAILURE;
  }

  n_elements = sizeof(numbers) / sizeof(int);
  for (i = 0; i < n_elements; i++) {
    if (list_push_front(list, numbers + i) == ERROR) {
      list_free(list);
      return EXIT_FAILURE;
    }
  }

  printf("Original list: ");
  list_print(stdout, list, int_print);

  for (i = 0; i < n_elements; i++) {
    number = (int *)list_pop_min(list, int_cmp);
    if (number != NULL) {
      printf("\nExtracting %3d => ", *number);
      list_print(stdout, list, int_print);
    }
  }

  while (list_is_empty(list) == FALSE) {
    list_pop_front(list);
  }

  n_elements = sizeof(strings) / sizeof(char *);
  for (i = 0; i < n_elements; i++) {
    if (list_push_front(list, strings[i]) == ERROR) {
      list_free(list);
      return EXIT_FAILURE;
    }
  }

  printf("\n\nOriginal list: ");
  list_print(stdout, list, string_print);

  for (i = 0; i < n_elements; i++) {
    string = (char *)list_pop_min(list, string_cmp);
    if (string != NULL) {
      printf("\nExtracting %s => ", string);
      list_print(stdout, list, string_print);
    }
  }
  printf("\n");

  list_free(list);

  return EXIT_SUCCESS;
}
