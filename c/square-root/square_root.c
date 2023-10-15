#include "square_root.h"
#include <stdint.h>

uint32_t square_root(uint32_t input) {
  uint32_t result = 0;

  while (result * result < input) {
    result++;
  }

  return result;
}
