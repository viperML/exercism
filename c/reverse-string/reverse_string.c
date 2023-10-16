#include "reverse_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value) {
  if (!value) {
    return NULL;
  }

  size_t elems = strlen(value);

  char *s = calloc(elems + 1, sizeof(char));
  s[elems] = '\0';

  if (elems == 0) {
    return s;
  }

  for (size_t i = 0; i < elems; i++) {
    s[i] = value[i];
    size_t j = elems - i - 1;

    s[i] = value[j];
  }

  return s;
}
