#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
  int distance = 0;

  size_t llen = strlen(lhs);
  size_t rlen = strlen(rhs);

  if (llen != rlen) {
    return -1;
  }

  for (size_t i = 0; i < llen; i++) {
    char r = lhs[i];
    char l = rhs[i];

    if (r != l) {
      distance++;
    }
  }

  return distance;
}
