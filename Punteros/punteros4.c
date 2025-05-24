#include <stdio.h>
#include <math.h>


void promedio(float, float, float, float *);

int main(int argc, char const *argv[])
{
    float num_1, num_2, num_3, prom;

    printf("Ingrese el numero 1 \n");
    scanf("%f", &num_1);
    printf("Ingrese el numero 2 \n");
    scanf("%f", &num_2);
    printf("Ingrese el numero 3 \n");
    scanf("%f", &num_3);

    promedio(num_1, num_2, num_3, &prom);

    printf("El promedio es = %.2f\n", prom );

return 0;
}

// Definición de la función
void promedio(float dato1, float dato2, float dato3, float *prom)
{
    (*prom) = (dato1 + dato2 + dato3)/3;
    
}