#include "sieve.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  size_t n_candidates = limit + 1;

  bool candidates[n_candidates];

  for (size_t i = 0; i < n_candidates; i++) {
    candidates[i] = true;
  }

  candidates[0] = false;
  candidates[1] = false;

  for (size_t candidate = 2; candidate < n_candidates; candidate++) {
    for (size_t by = 2;; by++) {
      size_t target = candidate * by;
      if (target >= n_candidates) {
        break;
      }
      candidates[target] = false;
    }
  }

  uint32_t res = 0;
  size_t i = 0;

  for (size_t candidate = 0; candidate < n_candidates; candidate++) {
    printf("%zu: %d\n", candidate, candidates[candidate]);
    if (candidates[candidate] && i < max_primes) {
      res++;
      primes[i] = candidate;
      i++;
    }
  }

  return res;
}
