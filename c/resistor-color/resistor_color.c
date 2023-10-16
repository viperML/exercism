#include "resistor_color.h"
#include <stdlib.h>

resistor_band_t *colors() {
  resistor_band_t *res = calloc(WHITE + 1, sizeof(resistor_band_t));

  for (int i = 0; i <= WHITE; i++) {
    res[i] = i;
  }

  return res;
}

int color_code(resistor_band_t color) { return color; }
