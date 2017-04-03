//Matheus Joranhezon 150018428
//Felipe Hargreaves 15009313
#include <stdio.h>
#include <stdlib.h>


//Populate the vector with sequential numbers
void populate_vector(int * vector, int vector_size){
  int counter;

  for(counter = 0; counter <= vector_size; counter++){
    vector[counter] = counter;
  }
}

//Populate the index vector with numbers that represent
void populate_index(int ** index, int index_size, int vector_size, int * vector){
  int counter, second_counter;

  second_counter = 0;
  //Go through the vector with index size spacing
  for(counter = 0; counter < vector_size; counter += index_size){
    //Populate the index vector starting by an index size spacing minus one
    index[second_counter++] = &vector[counter + index_size - 1];
  }
}

//Use index sequential search method
int search_number(int * vector, int ** index, int vector_size, int index_size){
  int number, counter, second_counter, aux;

  printf("Type the number you wish to search for:");
  scanf("%d", &number);

  //Set the firt value of the original as start point of the intersection
  aux = vector[0];

  //Goes through the vector using the gap between indexes as spacing
  for(counter = 0; counter < (vector_size/index_size); counter++){
    //Check if the number searched is smaller than the end point of the intersection
    if(number <= *index[counter]){
      //Goes through the intersection, starting by it's end
      for(second_counter = *index[counter]; second_counter >= aux; second_counter--){
        //Checks if the number searched is equal to the number seacherd
        //If it is, it returns 1 so that the main knows that the number is in the vector
        if(vector[second_counter] == number)
          return 1;
      }
    }
    //Set the end point of the intersection as the initial point of the next intersection
    aux = *index[counter];
  }

  return 0;
}


int main() {
  int * vector, ** index, vector_size, index_size;

  scanf("%d", &vector_size);

  //Alloc the vector with the size given by the user
  vector = (int *) malloc(vector_size * sizeof(int));

  //Check which size is the best to make a vector
  if(vector_size % 7 == 0)
    index_size = 7;
  else if(vector_size % 5 == 0)
    index_size = 5;
  else if(vector_size % 3 == 0)
    index_size = 3;
  else
    index_size = 2;

  //Alloc the vector with a size index_size smaller than the size given by the user
  index = (int **) malloc((vector_size/index_size) * sizeof(int));

  populate_vector(vector, vector_size);
  populate_index(index, index_size, vector_size, vector);

  //Use an int to receive the value passed from the search_number function
  int is_there;
  is_there = search_number(vector, index, vector_size, index_size);

  //Use the received value to determine if the number is in the vector or not
  if(is_there == 1)
    printf("The number you searched for is in the vector.\n");
  else
    printf("The number you searched for is not in the vector.\n");

  return 0;
}
