#include <stdio.h>

int main(int agrc, char const *argv[])
{
   int arreglo[5]= {0};
   for(int i = 0; i < 15; i++){
    arreglo[0]++;
    arreglo[1]+=2;
    arreglo[2]+=3;
    arreglo[3]+=4;
    arreglo[4]+=5;
}
// imprimo los datos de ese arreglo
for (int i = 0; i < 5; i++)
{
    printf("%d \n", arreglo[i]);
}
  return 0;
}