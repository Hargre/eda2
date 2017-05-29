/*  Matheus Joranhezon 15/0018428
*   Felipe Hargreaves - 15/0009313
*/
#include <stdio.h>
#include <stdlib.h>
#define quantity 10

typedef struct job{
  int id;
  int timepc;
  int timesuperpc;
  int finish_time;
}job;

int main() {
  job examples[quantity];

  for(int counter = 0; counter < quantity; counter++) {
    examples[counter].id = counter + counter * 2;
    examples[counter].timepc = counter + 1;
    examples[counter].timesuperpc = counter +2;
  }

  printf("\nA ordem dos examples a ser executada deve ser:  ");
  int superpc_time = 0;
  int longest = 0;
  for(int i = quantity - 1; i >= 0; i--){
    printf("%d   ",examples[i].id);
    superpc_time += examples[i].timesuperpc;
    examples[i].finish_time = superpc_time + examples[i].timepc;
    if(examples[i].finish_time > longest){
      longest = examples[i].finish_time;
    }
  }
  printf("\nTempo de conclusao: %d\n\n",longest);
  return 0;
}
