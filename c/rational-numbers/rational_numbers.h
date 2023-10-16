#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
  int32_t numerator;
  int32_t denominator;
} rational_t;

rational_t add(rational_t a, rational_t b);
rational_t subtract(rational_t a, rational_t b);
rational_t multiply(rational_t a, rational_t b);
rational_t divide(rational_t a, rational_t b);
rational_t absolute(rational_t a);
rational_t exp_rational(rational_t base, int16_t power);
float exp_real(int16_t base, rational_t power);
rational_t reduce(rational_t a);

int32_t gcd(int32_t a, int32_t b);
int32_t int_pow(int32_t base, int32_t power);

#endif
