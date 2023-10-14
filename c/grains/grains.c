#include "grains.h"
#include <stdint.h>

uint64_t square(uint8_t index) {
  if (index < 1) {
    return 0;
  }

  uint64_t result = 1;

  for (uint64_t i = 1; i < index; i++) {
    result = result * 2;
  }

  return result;
}

uint64_t total(void) {
  uint64_t total = 0;
  for (int i = 1; i <= 64; i++) {
    total = total + square(i);
  }

  return total;
}
