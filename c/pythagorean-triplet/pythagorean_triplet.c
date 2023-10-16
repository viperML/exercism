#include "pythagorean_triplet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_triplets(triplets_t *triplets) {
  if (!triplets) {
    return;
  }
  free(triplets->triplets);
  free(triplets);
}

void push_triplet(triplets_t *triplets, triplet_t triplet) {
  if (triplets->capacity == 0) {
    triplets->capacity = 1;
    triplets->count = 1;
    triplets->triplets = calloc(1, sizeof(triplet_t));
    triplets->triplets[0] = triplet;
    return;
  }

  if (triplets->capacity == triplets->count) {
    triplets->capacity = triplets->capacity * 2;
    triplet_t *new_triplets = calloc(triplets->capacity, sizeof(triplet_t));
    memcpy(new_triplets, triplets->triplets,
           triplets->count * sizeof(triplet_t));
    free(triplets->triplets);
    triplets->triplets = new_triplets;
  }

  triplets->triplets[triplets->count] = triplet;
  triplets->count++;
}

triplets_t *triplets_with_sum(uint16_t sum) {
  triplets_t *res = malloc(sizeof(triplets_t));
  res->count = 0;
  res->capacity = 0;
  res->triplets = NULL;

  for (uint16_t k = 1; k <= sum; k++) {
    for (uint16_t j = 1; j <= k; j++) {
      for (uint16_t i = 1; i < j; i++) {
        if ((i + j + k - sum) == 0 && (i * i + j * j - k * k) == 0) {
          printf("Found sum %d %d %d > %d\n", i, j, k, sum);
          triplet_t t;
          t.a = i;
          t.b = j;
          t.c = k;
          push_triplet(res, t);
        }
      }
    }
  }

  for (size_t i = 0; i < res->count; i++) {
    printf("< %d %d %d >\n", res->triplets[i].a, res->triplets[i].b,
           res->triplets[i].c);
  }

  return res;
}
