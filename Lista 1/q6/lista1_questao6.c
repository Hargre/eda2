#include <stdio.h>
#include <stdlib.h>

int interpolation_search (int * vector, int vector_size, int searched_number) {
  int middle;
  int inferior, superior;

  inferior = 0;
  superior = vector_size - 1;

  while(superior != inferior && vector[superior] != vector[inferior]){
    middle = inferior - ((inferior - superior)/(vector[superior] - vector[inferior])) * (searched_number - vector[inferior]);

    if(searched_number == vector[middle])
      return 1;
    else if(searched_number > vector[middle])
      inferior = middle;
    else if(vector[middle] > searched_number)
      superior = searched_number;
  }


  return 0;
}

void populate_vector(int * vector, int vector_size){
  int counter;

  for(counter = 0; counter < vector_size; counter++){
    vector[counter] = counter + 1;
  }
}

int main () {
  int * vector;

  printf("Digite o tamanho do seu vetor de números:");
  int vector_size;
  scanf("%d", &vector_size);

  vector = (int *) malloc(vector_size * sizeof(int));
  populate_vector(vector, vector_size);

  printf("Digite o número que deseja encontrar:");
  int searched_number;
  scanf("%d", &searched_number);

  int is_there;
  is_there = interpolation_search(vector, vector_size, searched_number);

  if(is_there)
    printf("O número procurado se encontra no vetor\n");
  else
    printf("O número procurado não se encontra no vetor\n");

  return 0;
}
