#include <stdio.h>

int main(int argc, char const *argv[])
{
   int Datos[5]= {45, 32, 89, 11,9};

   printf("%d\n", Datos[2]); // Indice 2 corresponde al 89

   // Imprimo los datos del arreglo   
   for (int i = 0; i < 5; i++)
  {
    printf("%d,- %p\n" ,Datos[i], &Datos[i]);
  }

    return 0;
}