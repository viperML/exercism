#include "saddle_points.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_saddle_points(saddle_points_t *saddle_points) {
  if (!saddle_points) {
    return;
  }

  if (saddle_points->points) {
    free(saddle_points->points);
  }

  free(saddle_points);
}

void *push_point(saddle_points_t *saddle_points, size_t row, size_t column) {
  saddle_points->count++;

  if (!saddle_points->points) {
    saddle_points->capacity = 1;
    printf(":: Allocating mem\n");
    saddle_points->points =
        calloc(saddle_points->capacity, sizeof(saddle_point_t));
  }

  if (saddle_points->capacity < saddle_points->count) {
    saddle_points->capacity *= 2;

    saddle_point_t *new_points =
        calloc(saddle_points->capacity, sizeof(saddle_point_t));
    memcpy(new_points, saddle_points->points,
           (saddle_points->count - 1) * sizeof(saddle_point_t));
    free(saddle_points->points);
    saddle_points->points = new_points;
  }

  saddle_point_t new_point = {row, column};
  saddle_points->points[saddle_points->count - 1] = new_point;

  return saddle_points;
}

saddle_points_t *saddle_points(size_t n, size_t m, uint8_t matrix[n][m]) {
  printf(":: Checking saddle points\n");
  saddle_points_t *res = malloc(sizeof(saddle_points_t));
  res->points = NULL;
  res->count = 0;

  for (size_t i = 0; i != n; i++) {
    for (size_t j = 0; j != m; j++) {
      uint8_t position = matrix[i][j];

      bool smallest_column = true;
      for (size_t ii = 0; ii != n; ii++) {
        if (ii == i) {
          continue;
        }

        uint8_t compare = matrix[ii][j];

        if (position > compare) {
          smallest_column = false;
        }
      }

      bool biggest_row = true;
      for (size_t jj = 0; jj != m; jj++) {
        if (jj == j) {
          continue;
        }

        uint8_t compare = matrix[i][jj];

        if (position < compare) {
          biggest_row = false;
        }
      }

      if (!biggest_row || !smallest_column) {
        continue;
      }

      push_point(res, i + 1, j + 1);
      printf("Found saddle @ %zu %zu with value %d \n", i + 1, j + 1,
             matrix[i][j]);
    }
  }

  return res;
}
