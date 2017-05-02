//Matheus Joranhezon 150018428
//Felipe Hargreaves 15009313
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 100

int * populate_vector(int * vector) {
  int counter;

  vector =(int *) malloc(sizeof(int)*SIZE);
  vector[0] = SIZE-1;

  srand(time(NULL));
  for(counter = 1; counter < SIZE; counter++){
    vector[counter] = rand() % 100;
  }

  return vector;
}

void print_vector(int * vector) {
  int counter;

  for(counter = 1; counter < SIZE; counter++){
    printf("%d ", vector[counter]);
  }

  printf("\n");
}

int left_index(int index){
  return 2 * index;
}

int right_index(int index){
  return (2 * index) + 1;
}

int parent_index(int index){
  return (index/2);
}


int* heapify(int *vector, int current_index){
  int left, right;

  left = left_index(current_index);
  right = right_index(current_index);

  int largest;
  if(left <= vector[0] && vector[left] > vector[current_index])
    largest = left;
  else
    largest = current_index;

  if(right <= vector[0] && vector[right] > vector[largest])
    largest = right;

  if(largest != current_index){
    int swap = vector[current_index];
    vector[current_index] = vector[largest];
    vector[largest] = swap;
    heapify(vector, largest);
  }
  return vector;
}


int* build_heap(int *vector, int size){
  int counter;

  for(counter = size/2; counter > 0; counter--)
    vector = heapify(vector, counter);

  return vector;
}

int * heap_sort(int *vector, int size){
  int counter;

  vector = build_heap(vector, size);

  for(counter = size; counter > 1; counter--){
    int swap = vector[1];
    vector[1] = vector[counter];
    vector[counter] = swap;
    vector [0]--;
    heapify(vector, 1);
  }
  return vector;
}


int main() {
  int * vector;

  vector = populate_vector(vector);
  print_vector(vector);
  vector = heap_sort(vector, vector[0]);
  print_vector(vector);
  return 0;
}
