/*
 * Recursive Mergesort
 * Felipe Hargreaves - 15/0009313
 * Matheus Joranhezon - 15/0018428
 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

/* Array manipulation functions */
void shuffle_array(int *array, int length) {
  for (int i = length - 1; i > 0; i--) {
    int random_index = rand() % i;

    int aux = array[i];
    array[i] = array[random_index];
    array[random_index] = aux;
  }
}

int *create_array(int length) {
  int *array = malloc(length * sizeof(int));

  for (int i = 0; i < length; i++) {
    array[i] = i;
  }

  shuffle_array(array, length);

  return array;
}

void destroy_array(int *array) {
  free(array);
}
/* ---------------------------- */

/* Merge and Mergesort functions */
void merge(int *array, int left, int middle, int right) {
  int size_left = (middle - left) + 1;
  int size_right = (right - middle);

  int aux_left[size_left];
  int aux_right[size_right];

  for (int i = 0; i < size_left; i++) {
    aux_left[i] = array[left + i];
  }

  for (int i = 0; i < size_right; i++) {
    aux_right[i] = array[middle + 1 + i];
  }

  int left_iterator = 0;
  int right_iterator = 0;
  int merge_iterator = left;

  while (left_iterator < size_left && right_iterator < size_right) {
    if (aux_left[left_iterator] <= aux_right[right_iterator]) {
      array[merge_iterator] = aux_left[left_iterator];
      left_iterator++;
    } else {
      array[merge_iterator] = aux_right[right_iterator];
      right_iterator++;
    }
    merge_iterator++;
  }

  while (left_iterator < size_left) {
    array[merge_iterator] = aux_left[left_iterator];
    left_iterator++;
    merge_iterator++;
  }

  while (right_iterator < size_right) {
    array[merge_iterator] = aux_right[right_iterator];
    right_iterator++;
    merge_iterator++;
  }
}

void merge_sort(int *array, int left, int right) {
  int middle = (left + right) / 2;

  if (left < right) {
    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);

    merge(array, left, middle, right);
  }
}
/* ------------------- */

void print_array(int *array, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf(" %d ", array[i]);
  }
  printf("]\n");
}

void print_unsorted(int *array, int size) {
  printf("Unsorted data:\n");
  print_array(array, size);
}

void print_sorted(int *array, int size) {
  printf("Sorted data:\n");
  print_array(array, size);
}

int main() {
  int *array = create_array(LENGTH);
  int left = 0;
  int right = LENGTH - 1;

  print_unsorted(array, LENGTH);
  merge_sort(array, left, right);
  print_sorted(array, LENGTH);

  destroy_array(array);
  return 0;
}
