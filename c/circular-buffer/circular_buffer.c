#include "circular_buffer.h"
#include <errno.h>
#include <stdio.h>

size_t buffer_start(const circular_buffer_t *buffer) {
  if (buffer->items <= 1) {
    return buffer->end;
  }

  if (buffer->items <= buffer->end + 1) {
    printf(":: NON WRAPPING");
    return buffer->end - buffer->items + 1;
  } else {
    printf(":: WRAPPING");
    return buffer->capacity + 1 + buffer->end - buffer->items;
  }
}

void print_buffer(const circular_buffer_t *buffer) {
  size_t start = buffer_start(buffer);
  printf(":: Buffer\n");
  printf("::   start: %zu\n", start);
  printf("::   end: %zu\n", buffer->end);
  printf("::   capacity: %zu\n", buffer->capacity);
  printf("::   items: %zu\n", buffer->items);

  if (buffer->items == 0) {
    return;
  }

  printf("::   {");
  if (buffer->items == 1) {
    printf(" %d }\n", buffer->mem[buffer->end]);
    return;
  }

  size_t i = start;
  for (;;) {
    printf(" %d", buffer->mem[i]);

    if (i == buffer->end) {
      break;
    }

    i++;
    if (i == buffer->capacity) {
      i = 0;
    }
  }

  printf(" }\n");
}

circular_buffer_t *new_circular_buffer(const size_t capacity) {
  if (capacity < 1) {
    return 0;
  }

  circular_buffer_t *result = malloc(sizeof(circular_buffer_t));

  result->mem = malloc(sizeof(circular_buffer_t) * capacity);
  result->capacity = capacity;
  result->items = 0;
  result->end = 0;

  return result;
}

void delete_buffer(circular_buffer_t *buffer) {
  if (!buffer) {
    errno = 69;
    return;
  }

  free(buffer->mem);
  free(buffer);
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *value) {
  if (!buffer) {
    return 1;
  }

  if (buffer->items == 0) {
    errno = ENODATA;
    return 1;
  }

  size_t start = buffer_start(buffer);

  *value = buffer->mem[start];

  buffer->items = buffer->items - 1;

  print_buffer(buffer);

  return 0;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {
  if (!buffer) {
    return 1;
  }

  if (buffer->items == buffer->capacity) {
    errno = ENOBUFS;
    return 1;
  }

  if (buffer->items != 0) {
    buffer->end++;
  }

  buffer->items++;

  if (buffer->end == buffer->capacity) {
    buffer->end = 0;
  }

  buffer->mem[buffer->end] = value;

  print_buffer(buffer);

  return 0;
}

void clear_buffer(circular_buffer_t *buffer) {
  buffer->end = 0;
  buffer->items = 0;
  free(buffer->mem);
  buffer->mem = malloc(sizeof(circular_buffer_t) * buffer->capacity);
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  if (!buffer) {
    return 1;
  }

  if (buffer->items == buffer->capacity) {
    buffer_value_t v;
    read(buffer, &v);
  }

  return write(buffer, value);
}
