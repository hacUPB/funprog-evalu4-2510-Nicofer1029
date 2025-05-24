#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que reemplaza todas las apariciones de una palabra por otra
char* reemplazar_palabra(const char* texto, const char* palabraOriginal, const char* palabraNueva) {
    int i, contador = 0;
    int largoOriginal = strlen(palabraOriginal);
    int largoNuevo = strlen(palabraNueva);

    // Contar cuántas veces aparece la palabra original en el texto
    for (i = 0; texto[i] != '\0'; i++) {
        if (strstr(&texto[i], palabraOriginal) == &texto[i]) {
            contador++;
            i += largoOriginal - 1;
        }
    }

    // Calcular el nuevo tamaño del texto modificado
    int nuevoTamanio = strlen(texto) + contador * (largoNuevo - largoOriginal) + 1;
    char* nuevoTexto = (char*)malloc(nuevoTamanio);
    if (!nuevoTexto) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    i = 0;
    while (*texto) {
        if (strstr(texto, palabraOriginal) == texto) {
            strcpy(&nuevoTexto[i], palabraNueva);
            i += largoNuevo;
            texto += largoOriginal;
        } else {
            nuevoTexto[i++] = *texto++;
        }
    }

    nuevoTexto[i] = '\0';
    return nuevoTexto;
}

int main() {
    char nombreArchivo[100];
    char palabraBuscar[100];
    char palabraReemplazo[100];

    // Solicitar al usuario el nombre del archivo
    printf("Ingrese el nombre del archivo de texto (ejemplo: archivo.txt): ");
    scanf("%99s", nombreArchivo);

    // Abrir el archivo
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo '%s'.\n", nombreArchivo);
        return 1;
    }

    // Obtener el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    long tamanio = ftell(archivo);
    rewind(archivo);

    // Reservar memoria para el contenido del archivo
    char* texto = (char*)malloc(tamanio + 1);
    if (!texto) {
        printf("Error al asignar memoria para el texto.\n");
        fclose(archivo);
        return 1;
    }

    fread(texto, 1, tamanio, archivo);
    texto[tamanio] = '\0';
    fclose(archivo);

    // Solicitar palabras al usuario
    printf("Ingrese la palabra que desea buscar: ");
    scanf("%99s", palabraBuscar);

    printf("Ingrese la palabra con la que desea reemplazarla: ");
    scanf("%99s", palabraReemplazo);

    // Reemplazar palabras en el texto
    char* textoModificado = reemplazar_palabra(texto, palabraBuscar, palabraReemplazo);

    // Mostrar el texto modificado
    printf("\nTexto modificado:\n%s\n", textoModificado);

    // Liberar memoria usada
    free(texto);
    free(textoModificado);

    return 0;
}
