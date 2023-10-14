#include "isogram.h"
#include "stdlib.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool is_isogram(const char phrase[]) {
  if (phrase == NULL) {
    return false;
  }
  // printf(":: %s\n", phrase);

  size_t stack_size = 64;
  size_t stack_elems = 0;

  char *stack = malloc(stack_size * sizeof(char));

  for (int phrase_n = 0; phrase_n <= 20; phrase_n++) {
    char phrase_elem = phrase[phrase_n];
    phrase_elem = tolower(phrase_elem);
    if (phrase_elem == '\0') {
      break;
    }
    if (!isalpha(phrase_elem)) {
      continue;
    }
    // printf(":: phrase_elem %c, %x\n", phrase_elem, phrase_elem);

    for (size_t stack_n = 0; stack_n < stack_elems; stack_n++) {
      char stack_elem = stack[stack_n];
      // printf(":::: stack_elem %c, %x\n", stack_elem, stack_elem);

      if (phrase_elem == stack_elem) {
        return false;
      }
    }

    stack[stack_elems] = phrase_elem;
    stack_elems = stack_elems + 1;
  }

  return true;
}
