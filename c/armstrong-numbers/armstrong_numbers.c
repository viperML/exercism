#include "armstrong_numbers.h"
#include <stdio.h>

int powi(const int base, const int exponent) {
  if (exponent == 0) {
    return 1;
  }

  if (exponent == 1) {
    return base;
  }

  if (exponent < 0) {
    return -1;
  }

  int result = base;
  for (int i = 2; i <= exponent; i++) {
    result = result * base;
  }

  return result;
}

bool is_armstrong_number(const int candidate) {
  int digits = 0;

  int n = candidate;
  while (n > 0) {
    n = n / 10;
    digits = digits + 1;
  }
  printf("digits:%d\n", digits);

  n = candidate;
  int sum = 0;
  while (n > 0) {
    int rem = n % 10;
    n = n / 10;
    sum = sum + powi(rem, digits);
  }

  printf("sum:%d\n", sum);

  return sum == candidate;
}
