#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de función que devuelve el texto modificado
char* reemplazarPalabra(const char* texto, const char* palabraOriginal, const char* palabraNueva);

void menu();

int main(void)
{
    int opcion;
    char nombreArchivo[100];

    do {
        menu();
        scanf("%d", &opcion);
        getchar(); // Para limpiar el buffer después de scanf

        switch (opcion) {
            case 1:
                printf("Calcular estadisticas del texto \n");
                // Aquí podrías llamar a tu función para estadísticas
                break;

            case 2:
                printf("Calcular frecuencia de aparicion de vocales \n");
                // Aquí podrías llamar a tu función para contar vocales
                break;

            case 3:
            {
                printf("Cambiar una palabra de texto por otra \n");

                // Pedir archivo
                printf("Ingrese el nombre del archivo de texto (ejemplo: archivo.txt): ");
                scanf("%99s", nombreArchivo);
                getchar();

                // Abrir archivo
                FILE* archivo = fopen(nombreArchivo, "r");
                if (!archivo) {
                    printf("No se pudo abrir el archivo '%s'.\n", nombreArchivo);
                    break;
                }

                // Obtener tamaño del archivo
                fseek(archivo, 0, SEEK_END);
                long tamanio = ftell(archivo);
                rewind(archivo);

                // Leer contenido
                char* texto = (char*)malloc(tamanio + 1);
                if (!texto) {
                    printf("Error al asignar memoria para el texto.\n");
                    fclose(archivo);
                    break;
                }
                fread(texto, 1, tamanio, archivo);
                texto[tamanio] = '\0';
                fclose(archivo);

                // Pedir palabras a buscar y reemplazar
                char palabraBuscar[100];
                char palabraReemplazo[100];
                printf("Ingrese la palabra que desea buscar: ");
                scanf("%99s", palabraBuscar);
                getchar();
                printf("Ingrese la palabra con la que desea reemplazarla: ");
                scanf("%99s", palabraReemplazo);
                getchar();

                // Reemplazar palabras
                char* textoModificado = reemplazarPalabra(texto, palabraBuscar, palabraReemplazo);

                // Mostrar resultado
                printf("\nTexto modificado:\n%s\n", textoModificado);

                // Liberar memoria
                free(texto);
                free(textoModificado);

                break;
            }
            case 4:
                printf("Guardar los resultados en un nuevo archivo \n");
                // Aquí podrías implementar la opción 4
                break;

            case 5:
                printf("Usted ha salido correctamente \n");
                break;

            default:
                printf("Opción no válida \n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

void menu() {
    printf("\nA continuación se mostrarán las diferentes opciones para analizar su archivo.\n");
    printf("Ingrese el número de la opción que desea realizar.\n");
    printf("1. Calcular estadísticas del texto\n");
    printf("2. Calcular frecuencia de aparición de vocales\n");
    printf("3. Cambiar una palabra de texto por otra\n");
    printf("4. Guardar los resultados en un nuevo archivo\n");
    printf("5. Salir\n");
}

// Función que reemplaza todas las apariciones de una palabra por otra
char* reemplazarPalabra(const char* texto, const char* palabraOriginal, const char* palabraNueva) {
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
