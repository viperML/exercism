#include "phone_number.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim_digits(const char *input) {
  if (!input) {
    return NULL;
  }

  size_t input_chars = strlen(input);
  char *res = calloc(input_chars + 1, sizeof(char));

  size_t cursor = 0;
  for (size_t i = 0; i < input_chars; i++) {
    char c = input[i];

    if (isdigit(c)) {
      // Skip the first digit, which may be only 1
      if (cursor == 0 && c == '1') {
        continue;
      }

      res[cursor] = c;
      cursor++;
    }
  }

  res[cursor] = '\0';

  return res;
}

char *phone_number_clean(const char *input) {
  char *BAD = calloc(11, sizeof(char));
  strcpy(BAD, "0000000000");

  if (!input) {
    return BAD;
  }

  char *trimmed = trim_digits(input);

  printf("input:\t%s\n", input);
  printf("trimmed:\t%s\n", trimmed);

  if (strlen(trimmed) != 10) {
    return BAD;
  }

  int x[2] = {0, 3};
  for (int i = 0; i < 2; i++) {
    char _case = trimmed[x[i]];
    if (_case < '2' || _case > '9') {
      printf("Character %c at position %d is not in range\n", _case, i);
      return BAD;
    }
  }

  int y[8] = {1, 2, 4, 5, 6, 7, 8, 9};
  for (int i = 0; i < 8; i++) {
    char _case = trimmed[y[i]];
    if (_case < '0' || _case > '9') {
      printf("Character %c at position %d is not in range\n", _case, i);
      return BAD;
    }
  }

  return trimmed;
}
