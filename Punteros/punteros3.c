#include <stdio.h>
#include <math.h>

// Función que recibe dos punteros y realiza operaciones
void operacion_punteros(float *, double *);

int main(int argc, char const *argv[])
{
    float cubo;
    double coseno;
    operacion_punteros(&cubo, &coseno);
    printf("Cubo = %f\n", cubo);
    printf("Factorial = %d\n", coseno);
return 0;
}

// Definición de la función
void operacion_punteros(float *var1, double *var2)
{
    // En la variable a la que apunta var1 voy a guardar el cubo de un número
    // que ingresa el usuario y en la variable a la que apunta var2 el factorial
    float dato;
    printf("Ingresa un dato: \n");
    scanf("%d", &dato);

    (*var1) = pow(dato, 3); //Guarda en la variable cubo = dato ^3
    (*var2) = cos(dato);    //Guarda en la variable factorial = dato     
}