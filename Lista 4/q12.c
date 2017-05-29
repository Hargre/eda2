/*  Matheus Joranhezon 15/0018428
*   Felipe Hargreaves - 15/0009313
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
  printf("Digite a quantidade de streams: ");
  int streams_quantity = 0;
  scanf ("%d", &streams_quantity);

  printf("Digite a largura de banda: ");
  int band_width = 0;
  scanf("%d", &band_width);

  int max_bits = 0, max_time = 0;
  for (int counter = 0; counter < streams_quantity; counter++) {
    printf("Stream %2d\n", counter + 1);

    printf("Digite a quantidade de bits do stream: ");
    int amount_bits = 0;
    scanf("%d", &amount_bits);
    max_bits += amount_bits;

    printf("Digite o periodo de tempo do stream: ");
    int time_stream = 0;
    scanf("%d", &time_stream);
    max_time += time_stream;;
  }

  if (max_bits <= (band_width * max_time)) {
    printf("O schedule foi feito com sucesso\n");
  }
  else{
    printf("Houve falha no schedule\n");
  }

  return 0;
}
