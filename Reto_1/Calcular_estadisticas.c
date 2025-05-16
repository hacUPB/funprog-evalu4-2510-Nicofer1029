/*
2. Calcular estadísticas del texto:
    - Total de caracteres (excluyendo \n si se desea).
    - Total de palabras (definidas como secuencias separadas por espacios).
    - Total de espacios en blanco.
    - Total de líneas.
*/

#include <stdio.h>
#include <string.h>

void menu();

int main(int argc, char const *argv[]) {
    int opcion;
    char nombreArchivo[100], caracter;
    long totalCaracteres = 0;
    int totalPalabras = 0;
    int totalEspacios = 0;
    int totalLineas = 0;
    FILE *archivo;

    menu();
    printf("Para contar caracteres, ¿desea incluir los saltos de linea? \n Ingrese 1 para si, 2 para no: ");
    scanf("%d", &opcion);

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        if (opcion == 1) {
            totalCaracteres++;
        } else if (caracter != '\n') {
            totalCaracteres++;
        }

        if (caracter == ' ' || caracter == '\t' || caracter == '\n') {
            totalEspacios++;
            totalPalabras++;
        }

        if (caracter == '\n') {
            totalLineas++;
        }
    }

    fclose(archivo);

    printf("\nEstadisticas del archivo '%s':\n", nombreArchivo);
    printf("Total de caracteres (excluyendo \\n si se eligio): %ld\n", totalCaracteres);
    printf("Total de palabras: %d\n", totalPalabras);
    printf("Total de espacios en blanco (incluyendo tabulaciones y saltos de linea): %d\n", totalEspacios);
    printf("Total de lineas: %d\n", totalLineas);

    return 0;
}

void menu() {
    printf("A continuacion, se mostraran las siguientes estadisticas del texto:\n");
    printf(" - Total de caracteres\n");
    printf(" - Total de palabras\n");
    printf(" - Total de espacios en blanco\n");
    printf(" - Total de lineas\n\n");
}