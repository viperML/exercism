#include "binary_search.h"
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
  if (!length) {
    return NULL;
  }
  if (!arr) {
    return NULL;
  }

  size_t lbound = 0;
  size_t rbound = length - 1;

  for (size_t limit = 0; limit <= 20; limit++) {
    size_t pivot = (lbound + rbound) / 2;

    for (size_t i = 0; i < length; i++) {
      printf(" %02zu", i);
    }
    printf("\n");
    for (size_t i = 0; i < length; i++) {
      printf(" %02d", arr[i]);
    }
    printf("\n");
    for (size_t i = 0; i < length; i++) {
      if (i == pivot) {
        printf("  x");
      } else if (i == lbound) {
        printf("  [");
      } else if (i == rbound) {
        printf("  ]");
      } else {
        printf("   ");
      }
    }
    printf("\n\n");

    const int *result_p = &arr[pivot];
    int result = *result_p;

    if (result > value) {
      rbound = pivot;
    } else if (result < value) {
      lbound = pivot;
    } else {
      return result_p;
    }

    if (rbound - lbound == 1) {
      // Check rbound
      const int *r_result_p = &arr[rbound];
      int r_result = *r_result_p;
      if (r_result == value) {
        return r_result_p;
      }

      // Check lbound
      const int *l_result_p = &arr[lbound];
      int l_result = *l_result_p;
      if (l_result == value) {
        return l_result_p;
      }

      return NULL;
    }

    if (rbound == lbound) {
      return NULL;
    }
  }

  printf("LIMIT\n");
  return NULL;
}
