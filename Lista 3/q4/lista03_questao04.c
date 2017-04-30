/*
 * Radix + Counting sort - MSD
 * Felipe Hargreaves - 15/0009313
 * Matheus Joranhezon - 15/0018428
 */

#include <stdio.h>
#include <stdlib.h>

#define DIGITS 10
#define LENGTH 120

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

void print_array(int *array, int length) {
  printf("[");
  for(int i = 0; i < length; i++) {
    printf(" %d ", array[i]);
  }
  printf("]\n");
}
/* ------------------------ */

/* Sorting functions */
int get_digit(int number, int digit_pos) {
  int digit;
  for (int i = 0; i < digit_pos; i++) {
    digit = number % 10;
    number /= 10;
  }
  return digit;
}

int get_MSD(int length) {
  int highest_value = length - 1;
  int digit = 0;

  while (highest_value > 0) {
    highest_value /= 10;
    digit++;
  }
  return digit;
}

int *counting_sort(int *array, int array_size, int current_digit) {

  int position_array[DIGITS] = { 0 };
  int result_array[array_size];

  for (int i = 0; i < array_size; i++) {
    int value = get_digit(array[i], current_digit);
    position_array[value]++;
  }

  for (int i = 1; i < DIGITS; i++) {
    position_array[i] += position_array[i - 1];
  }

  for (int i = (array_size - 1); i >= 0; i--) {
    int array_index = get_digit(array[i], current_digit);
    int position_index = --position_array[array_index];

    result_array[position_index] = array[i];
  }

  for (int i = 0; i < array_size; i++) {
    array[i] = result_array[i];
  }
}

void radix_MSD(int *array, int array_size, int current_digit) {
  if (current_digit && array_size > 1) {
    int buckets[DIGITS] = { 0 };
    int *bucket_array;
    int buckets_sum = 0;

    counting_sort(array, array_size, current_digit);

    for (int i = 0; i < array_size; i++) {
      int bucket_index = get_digit(array[i], current_digit);
      buckets[bucket_index]++;
    }

    for (int i = 0; i < DIGITS; i++) {
      bucket_array = array + buckets_sum;
      radix_MSD(bucket_array, buckets[i], current_digit - 1);

      buckets_sum += buckets[i];
    }
  }
}
/* --------------------------- */

int main() {
  int *array = create_array(LENGTH);
  int msd = get_MSD(LENGTH);

  printf("Unsorted:\n");
  print_array(array, LENGTH);

  radix_MSD(array, LENGTH, msd);

  printf("Sorted:\n");
  print_array(array, LENGTH);

  return 0;
}
