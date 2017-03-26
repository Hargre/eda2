#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND (-1)

/* Assumes the given array is sorted */
int binary_search(int *array, int key, int left_bound, int right_bound) {
  int middle = (left_bound + right_bound) / 2;

  /* Base case: number found */
  if (array[middle] == key) {
    return middle;
  }

  /* All positions have been checked; number not found */
  if (left_bound >= right_bound) {
    return NOT_FOUND;
  }

  /* Search only in lower half */
  if (key < array[middle]) {
    return binary_search(array, key, left_bound, (middle - 1));
  }

  /* Search only in upper half */
  if (key > array[middle]) {
    return binary_search(array, key, (middle + 1), right_bound);
  }
}

/* Assumes the given array is sorted, but dislocated */
int circular_search(int *circular_array, int key, int left_bound, int right_bound) {
  int middle = (left_bound + right_bound) / 2;

  /* Base case: number found */
  if (circular_array[middle] == key) {
    return middle;
  }

  /* All positions have been checked; number not found */
  if (left_bound >= right_bound) {
    return NOT_FOUND;
  }

  /*
   * As the list is circular, we don't know its starting point. 
   * However, taking the middle position as a pivot, there are 
   * two sublists: at least one of those is sorted.
   */

  /* Checks if lower half is sorted */
  if (circular_array[0] < circular_array[middle]) {
    /* If the key is in the sorted half range, apply binary search to that half */
    if (key < circular_array[middle] && key >= circular_array[left_bound]) {
      return binary_search(circular_array, key, left_bound, (middle - 1));
    }

    /* If not, search again in the unsorted half */
    return circular_search(circular_array, key, (middle + 1), right_bound);
  } 

  /* Checks if upper half is sorted */
  else if (circular_array[middle] < circular_array[right_bound]) {
    /* If the key is in the sorted half range, apply binary search to that half */
    if (key > circular_array[middle] && key <= circular_array[right_bound]) {
      return binary_search(circular_array, key, (middle + 1), right_bound);
    }

    /* If not, search again in the unsorted half */
    return circular_search(circular_array, key, left_bound, (middle - 1));
  }
}


int main() {
  int circular_array[10] = { 8, 9, 0, 1, 2, 3, 4, 5, 6, 7 };
  int key, result;

  /* Search for all the elements in the array, plus an inexistent one */
  for (key = 0; key <= 10; key++) {
    result = circular_search(circular_array, key, 0, 9);

    if (result >= 0) {
      printf("Number %d found at position %d\n", key, result);
    } 
    else {
      printf("Number %d not found!\n", key);
    }
  }

  return 0;
}