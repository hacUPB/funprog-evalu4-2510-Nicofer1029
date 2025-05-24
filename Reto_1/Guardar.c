#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Función para contar caracteres, palabras, espacios y líneas
void calcular_estadisticas(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas) {
    *caracteres = 0;
    *palabras = 0;
    *espacios = 0;
    *lineas = 1; // asumiendo que hay al menos una línea

    int en_palabra = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') (*caracteres)++;

        if (isspace(c)) {
            if (c == ' ') (*espacios)++;
            if (en_palabra) {
                (*palabras)++;
                en_palabra = 0;
            }
            if (c == '\n') (*lineas)++;
        } else {
            en_palabra = 1;
        }
    }
    // Contar la última palabra si el texto no termina en espacio
    if (en_palabra) (*palabras)++;
}

// Función para contar frecuencia de vocales (a,e,i,o,u) sin importar mayúsculas/minúsculas
void frecuencia_vocales(const char* texto, int* fa, int* fe, int* fi, int* fo, int* fu) {
    *fa = *fe = *fi = *fo = *fu = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        switch (c) {
            case 'a': (*fa)++; break;
            case 'e': (*fe)++; break;
            case 'i': (*fi)++; break;
            case 'o': (*fo)++; break;
            case 'u': (*fu)++; break;
        }
    }
}

int main() {
    // Simulación: supongamos que ya tenemos texto modificado
    // En tu caso, ya tienes este texto luego de la parte 4
    char* textoModificado = "Este es un texto de prueba para el programa.";

    int caracteres, palabras, espacios, lineas;
    calcular_estadisticas(textoModificado, &caracteres, &palabras, &espacios, &lineas);

    int fa, fe, fi, fo, fu;
    frecuencia_vocales(textoModificado, &fa, &fe, &fi, &fo, &fu);

    // Pedir nombre archivo de salida
    char archivoSalida[100];
    printf("Ingrese el nombre del archivo donde se guardarán los resultados: ");
    scanf("%99s", archivoSalida);

    FILE* fSalida = fopen(archivoSalida, "w");
    if (!fSalida) {
        printf("No se pudo crear el archivo %s\n", archivoSalida);
        return 1;
    }

    // Guardar estadísticas
    fprintf(fSalida, "Estadísticas del texto:\n");
    fprintf(fSalida, "Caracteres (sin contar saltos de línea): %d\n", caracteres);
    fprintf(fSalida, "Palabras: %d\n", palabras);
    fprintf(fSalida, "Espacios en blanco: %d\n", espacios);
    fprintf(fSalida, "Líneas: %d\n\n", lineas);

    // Guardar frecuencia vocales
    fprintf(fSalida, "Frecuencia de vocales:\n");
    fprintf(fSalida, "a: %d\n", fa);
    fprintf(fSalida, "e: %d\n", fe);
    fprintf(fSalida, "i: %d\n", fi);
    fprintf(fSalida, "o: %d\n", fo);
    fprintf(fSalida, "u: %d\n\n", fu);

    // Guardar texto modificado
    fprintf(fSalida, "Texto modificado:\n%s\n", textoModificado);

    fclose(fSalida);

    printf("Resultados guardados en '%s'\n", archivoSalida);
    return 0;
}
