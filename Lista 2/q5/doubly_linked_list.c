#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "doubly_linked_list.h"

#define RANGE 1000

t_list *create_list() {
  t_list *list = (t_list *)malloc(sizeof(t_list));

  list->first = NULL;
  list->last = NULL;

  return list;
}

t_node *create_node() {
  t_node *node = (t_node *)malloc(sizeof(t_node));

  node->previous = NULL;
  node->next = NULL;

  return node;
}

void insert_at_head(int value, t_list *list) {
  t_node *node = create_node();

  node->value = value;

  if (list->first == NULL) {
    list->first = node;
    list->last = node;
  } else {
    node->previous = NULL;
    node->next = list->first;
    list->first->previous = node;
  }
  list->first = node;
}

void insert_before_pivot(t_node *node, t_node *pivot, t_list *list) {
  t_node *next_node = node->next;
  t_node *previous_node = node->previous;
  t_node *pivot_previous = pivot->previous;

  if (next_node != NULL) {
    next_node->previous = node->previous;
  } else {
    list->last = previous_node;
  }
  previous_node->next = next_node;

  if (pivot_previous != NULL) {
    pivot_previous->next = node;
  } else {
    list->first = node;
  }

  node->previous = pivot_previous;
  node->next = pivot;
  pivot->previous = node;
}

void populate_list(int length, t_list *list) {
  srand( (unsigned)time(NULL) );

  for (int iterator = 0; iterator < length; iterator++) {
    int number = rand() % (RANGE);
    insert_at_head(number, list);
  }
}

void free_list(t_list *list) {
  t_node *iterator = list->first;

  while (iterator) {
    list->first = iterator->next;
    free(iterator);
    iterator = list->first;
  }

  free(list);
}

void print(t_list *list) {
  t_node *iterator = list->first;

  if (iterator == NULL) {
    return;
  }

  printf("\nList:\n");
  while (iterator) {
    printf("%d -> ", iterator->value);
    iterator = iterator->next;
  }
  printf("end\n");
}
