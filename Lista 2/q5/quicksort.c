#include <stdio.h>
#include "doubly_linked_list.h"

#define LENGTH 20

t_node *partition(t_node *left, t_node *right, t_list *list) {
  t_node *pivot = left;
  t_node *iterator = pivot->next;

  while (iterator != right->next && iterator != NULL) {
    if (iterator->value < pivot->value) {
      t_node *iterator_next = iterator->next;

      insert_before_pivot(iterator, pivot, list);

      iterator = iterator_next;
    } else {
      iterator = iterator->next;
    }
  }

  return pivot;
}

void quicksort(t_node *left, t_node *right, t_list *list) {
  if (left != right && left != NULL && right != NULL) {
    t_node *pivot = partition(left, right, list);
    quicksort(list->first, pivot->previous, list);
    quicksort(pivot->next, right, list);
  }
}

int main() {
  t_list *list = create_list();

  populate_list(LENGTH, list);

  print(list);
  quicksort(list->first, list->last, list);
  print(list);

  free_list(list);
}
