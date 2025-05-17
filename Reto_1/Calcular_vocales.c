/*
3. **Calcular la frecuencia de aparición de las vocales (a, e, i, o, u)**
    - Mostrar cuántas veces aparece cada vocal (mayúsculas y minúsculas combinadas).
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char nombreArchivo[100], caracter;
    int total_A = 0;
    int total_E = 0;
    int total_I = 0;
    int total_O = 0;
    int total_U = 0;
    FILE *archivo;

    printf("Calcular frecuencia de aparicion de vocales \n");

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {

        if (caracter == 'a' || caracter == 'A') {
        total_A ++;
        }

        if (caracter == 'e' || caracter == 'E') {
        total_E ++;
        }

        if (caracter == 'i' || caracter == 'I') {
        total_I ++;
        }
        
        if (caracter == 'o' || caracter == 'O') {
        total_O ++;
        }

        if (caracter == 'u' || caracter == 'U') {
        total_U ++;
        }
    }

    fclose(archivo);
    printf("Calcular frecuencia de aparicion de vocales en el archivo '%s':\n", nombreArchivo);
    printf("Total de 'A': %d\n", total_A);
    printf("Total de 'E': %d\n", total_E);
    printf("Total de 'I': %d\n", total_I);
    printf("Total de 'O': %d\n", total_O);
    printf("Total de 'U': %d\n", total_U);

    return 0;
}