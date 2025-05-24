#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
int main(void)
{
    srand(time(NULL)); // Generamos una semilla
    int temp[24];      /* Con esto ya tenemos declaradas las 24 variables */
    float media = 0;
    int i, hora, mayor = 0, menor = temp[0];
 
    hora = rand();
    printf("%d\n", hora);

    /* Ahora tenemos que dar el valor de cada una */

    for (hora = 0; hora < 24; hora++)
    {

        temp[hora] = rand() % ((35-14)+1)+14;
        media += temp[hora];
        printf("%d ", temp[hora]);
    }

    media = media / 24;
    printf("\nLa temperatura media es %f\n", media);

    for (i = 0; i < 24; i++){

        if (temp[i] > mayor){

            mayor = temp[i];
        }
        
        if (temp[i] < menor){

            menor = temp[i];
        }
    }

    printf("Mayor = %d \n", mayor);
    printf("Menor = %d \n", menor);

    return 0;
    
}