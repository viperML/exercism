#include "list_ops.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

list_t *new_list(const size_t length, const list_element_t *elements) {
  if (length != 0 && !elements) {
    return NULL;
  }

  list_t *res = malloc(sizeof(list_t));

  if (length == 0) {
    res->_capacity = 10;
  } else {
    res->_capacity = length;
  }

  res->length = length;
  res->elements = malloc(sizeof(list_element_t) * res->_capacity);

  if (length != 0 && elements) {
    memcpy(res->elements, elements, length * sizeof(list_element_t));
  }

  return res;
}

list_t *append_list(list_t *list1, list_t *list2) {
  if (!list1) {
    return list2;
  }
  if (!list2) {
    return list1;
  }
  if (!list1 && !list2) {
    return NULL;
  }

  size_t length = list1->length + list2->length;

  list_element_t *elements = malloc(length * sizeof(list_element_t));

  memcpy(elements, list1->elements, sizeof(list_element_t) * list1->length);
  memcpy(elements + list1->length, list2->elements,
         sizeof(list_element_t) * list2->length);

  list_t *res = new_list(length, elements);

  return res;
}

void add_to_list(list_t *list, list_element_t element) {
  if (list->_capacity == list->length) {
    list->_capacity = list->_capacity * 2;

    list_element_t *new_elements =
        malloc(sizeof(list_element_t) * list->_capacity);

    list->elements = new_elements;
  }

  list->elements[list->length] = element;

  list->length++;
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  if (!list || !filter) {
    return NULL;
  }

  list_t *res = new_list(0, NULL);

  for (size_t i = 0; i < list->length; i++) {
    if (filter(list->elements[i])) {
      add_to_list(res, list->elements[i]);
    }
  }

  return res;
}

size_t length_list(list_t *list) { return list->length; }

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
  if (!list || !map) {
    return NULL;
  }

  list_t *res = new_list(0, NULL);

  for (size_t i = 0; i < list->length; i++) {
    list_element_t elem_res = map(list->elements[i]);
    add_to_list(res, elem_res);
  }

  return res;
}

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
  if (!list || !foldl) {
    return 0;
  }

  list_element_t acc = initial;

  for (size_t i = 0; i != list->length; i++) {
    acc = foldl(acc, list->elements[i]);
  }

  return acc;
}

list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
  if (!list || !foldr) {
    return 0;
  }

  list_element_t acc = initial;

  for (size_t i = list->length; i != 0; i--) {
    acc = foldr(list->elements[i - 1], acc);
  }

  return acc;
}

list_t *reverse_list(list_t *list) {
  if (!list) {
    return NULL;
  }

  list_t *res = new_list(0, NULL);

  for (size_t i = list->length; i != 0; i--) {
    add_to_list(res, list->elements[i - 1]);
  }

  return res;
}

void delete_list(list_t *list) {
  free(list->elements);
  free(list);
}
