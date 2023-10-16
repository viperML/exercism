#include "rational_numbers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int32_t gcd(int32_t a, int32_t b) {
  if (a == 0 && b == 0) {
    return 1;
  }
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  int32_t result;
  int32_t _a = abs(a);
  int32_t _b = abs(b);

  if (_a > _b) {
    result = _b;
  } else {
    result = _a;
  }

  for (;;) {
    int32_t mod_a = _a % result;
    int32_t mod_b = _b % result;

    if (mod_a == 0 && mod_b == 0) {
      return result;
    } else {
      result--;
    }
  }
}

rational_t add(rational_t a, rational_t b) {
  rational_t result;
  result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
  result.denominator = a.denominator * b.denominator;
  return reduce(result);
}

rational_t subtract(rational_t a, rational_t b) {
  rational_t result;
  result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
  result.denominator = a.denominator * b.denominator;
  return reduce(result);
}

rational_t multiply(rational_t a, rational_t b) {
  rational_t result;
  result.numerator = a.numerator * b.numerator;
  result.denominator = a.denominator * b.denominator;
  return reduce(result);
}

rational_t divide(rational_t a, rational_t b) {
  rational_t result;
  result.numerator = a.numerator * b.denominator;
  result.denominator = a.denominator * b.numerator;
  return reduce(result);
}

rational_t absolute(rational_t a) {
  rational_t result;

  if (a.numerator < 0) {
    result.numerator = -a.numerator;
  } else {
    result.numerator = a.numerator;
  }

  if (a.denominator < 0) {
    result.denominator = -a.denominator;
  } else {
    result.denominator = a.denominator;
  }

  return reduce(result);
}

int32_t int_pow(int32_t base, int32_t power) {
  int32_t res = 1;

  for (int32_t i = 0; i < power; i++) {
    res = res * base;
  }

  return res;
}

rational_t exp_rational(rational_t base, int16_t power) {
  rational_t result;

  if (power > 0) {
    result.numerator = int_pow(base.numerator, power);
    result.denominator = int_pow(base.denominator, power);
  } else {
    result.denominator = int_pow(base.numerator, -power);
    result.numerator = int_pow(base.denominator, -power);
  }

  return reduce(result);
}

float exp_real(int16_t base, rational_t power) {
  float powerf = (float)power.numerator / (float)power.denominator;
  return pow(base, powerf);
}

rational_t reduce(rational_t a) {
  rational_t res = a;

  int32_t _gcd;

  for (int i = 0; i < 5; i++) {
    // printf("{ %d, %d }\n", res.numerator, res.denominator);
    _gcd = gcd(res.numerator, res.denominator);
    // printf("reducing by %d\n", _gcd);

    if (_gcd == 1) {
      break;
    }

    res.numerator = res.numerator / _gcd;
    res.denominator = res.denominator / _gcd;
  }

  if (res.denominator < 0) {
    res.denominator = -res.denominator;
    res.numerator = -res.numerator;
  }

  return res;
}
