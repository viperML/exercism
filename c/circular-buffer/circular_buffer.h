#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdlib.h>

typedef int buffer_value_t;

typedef struct {
    size_t capacity;
    buffer_value_t* mem;
    size_t items;
    size_t end;
} circular_buffer_t;

size_t buffer_start(const circular_buffer_t *buffer);
void print_buffer(const circular_buffer_t *buffer);

circular_buffer_t* new_circular_buffer(const size_t capacity);
void delete_buffer(circular_buffer_t* buffer);
int16_t read(circular_buffer_t* buffer, buffer_value_t* value);
void clear_buffer(circular_buffer_t* buffer);
int16_t write(circular_buffer_t* buffer, buffer_value_t value);
int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value);

#endif
