//Matheus Joranhezon 150018428
//Felipe Hargreaves 15009313
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define DIGIT 8
#define SMALLEST 0
#define LARGEST 9


int* populate_aux(int *vector, int *vector_aux, int divisor){
  int counter;
  int index;
  for(counter = 0; counter < SIZE; counter++){
    index = ((vector[counter] / divisor) % 10) - SMALLEST;
    vector_aux[index]++;
  }
  return vector_aux;
}


int* restruct_aux(int *vector_aux, int aux_size){
  int counter;
  for(counter = 1; counter < aux_size; counter++){
    vector_aux[counter] += vector_aux [counter - 1];
  }
  return vector_aux;
}


int* build_aux(int aux_size){
  int *aux_vector;

  aux_vector =(int *) calloc(aux_size,sizeof(int));
  return aux_vector;
}

int* sorting(int *vector, int *vector_aux, int divisor){
  int *sorted_vector;
  int i;
  int index;
  sorted_vector =(int *) calloc(SIZE,sizeof(int));

  for(i = SIZE-1; i >= 0; i--){
    index = ((vector[i] / divisor) % 10) - SMALLEST;
    sorted_vector[vector_aux[index]-1] = vector[i];
    vector_aux[index]--;
  }
  return sorted_vector;
}

int* counting_sort(int *vector, int divisor){
  int *vector_aux;

    int aux_size = LARGEST - SMALLEST + 1;
    vector_aux = build_aux(aux_size);
    vector_aux = populate_aux(vector, vector_aux, divisor);
    vector_aux = restruct_aux(vector_aux, aux_size);

    vector = sorting(vector, vector_aux, divisor);

    return vector;
}

int * radix_sort(int * vector) {
  int counter, aux = 1;
  for(counter = 0; counter < DIGIT; counter++){
    vector = counting_sort(vector, aux);
    aux *= 10;
  }

  return vector;
}

void print_vector(int * vector) {
  int counter;
  printf("\nAfter sorting: ");
  for(counter = 0; counter < SIZE; counter++){
    printf("%d ", vector[counter]);
  }
  printf("\n");
}

int * create_vector(int * vector) {
  int counter;

  vector =(int *) malloc(sizeof(int)*SIZE);
  srand(time(NULL));
  printf("Vetor inicial: ");
  for(counter = 0; counter < SIZE; counter++){
    vector[counter] = rand() % 100000000;
    printf("%d ",vector[counter]) ;
  }

  return vector;
}

int main() {
  int * vector;

  vector = create_vector(vector);
  vector = radix_sort(vector);
  print_vector(vector);

  return 0;
}
