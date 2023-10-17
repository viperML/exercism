#include "allergies.h"

bool is_allergic_to(allergen_t allergen, uint16_t score) {
  uint16_t _allergen_mask = 2 << allergen;
  uint16_t res = (score << 1) & _allergen_mask;

  if (res > 0) {
    return true;
  } else {
    return false;
  }
}

allergen_list_t get_allergens(int score) {
  allergen_list_t res = {0};

  for (uint16_t i = 0; i < ALLERGEN_COUNT; i++) {
    if (is_allergic_to(i, score)) {
      res.allergens[i] = true;
      res.count++;
    }
  }

  return res;
}
