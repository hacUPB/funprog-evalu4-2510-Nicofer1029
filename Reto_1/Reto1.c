#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mostrarMenuPrincipal();

char* g_textoModificado = NULL;
long g_tamanoTextoModificado = 0;


void leerYMostrarArchivo() {
    char nombreArchivo[100];
    FILE *archivo;

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    rewind(archivo);

    char *contenido = (char *)malloc((tamano + 1) * sizeof(char));
    if (contenido == NULL) {
        perror("No se pudo asignar memoria");
        fclose(archivo);
        return;
    }

    size_t bytesLeidos = fread(contenido, 1, tamano, archivo);
    contenido[bytesLeidos] = '\0';

    printf("\nContenido del archivo '%s':\n%s\n", nombreArchivo, contenido);

    free(contenido);
    fclose(archivo);
}


void calcularEstadisticasTexto() {
    int opcionSaltoLinea;
    char nombreArchivo[100], caracter;
    long totalCaracteres = 0;
    int totalPalabras = 0;
    int totalEspacios = 0;
    int totalLineas = 0;
    FILE *archivo;

    printf("\n--- Calcular estadisticas del texto ---\n");
    printf("A continuacion, se mostraran las siguientes estadisticas del texto:\n");
    printf(" - Total de caracteres\n");
    printf(" - Total de palabras\n");
    printf(" - Total de espacios en blanco\n");
    printf(" - Total de lineas\n\n");

    printf("Para contar caracteres, ¿desea incluir los saltos de linea? \n Ingrese 1 para si, 2 para no: ");
    scanf("%d", &opcionSaltoLinea);

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    int enPalabra = 0;
    while ((caracter = fgetc(archivo)) != EOF) {
        if (opcionSaltoLinea == 1) {
            totalCaracteres++;
        } else if (caracter != '\n') {
            totalCaracteres++;
        }

        if (caracter == ' ' || caracter == '\t') {
            totalEspacios++;
            if (enPalabra) {
                totalPalabras++;
                enPalabra = 0;
            }
        } else if (caracter == '\n') {
            totalLineas++;
            totalEspacios++;
            if (enPalabra) {
                totalPalabras++;
                enPalabra = 0;
            }
        } else {
            enPalabra = 1;
        }
    }

    if (enPalabra) {
        totalPalabras++;
    }
    if (totalCaracteres > 0 && totalLineas == 0) {
        totalLineas = 1;
    }


    fclose(archivo);

    printf("\nEstadisticas del archivo '%s':\n", nombreArchivo);
    printf("Total de caracteres (excluyendo \\n si se eligio): %ld\n", totalCaracteres);
    printf("Total de palabras: %d\n", totalPalabras);
    printf("Total de espacios en blanco (incluyendo tabulaciones y saltos de linea): %d\n", totalEspacios);
    printf("Total de lineas: %d\n", totalLineas);
}


void calcularFrecuenciaVocales() {
    char nombreArchivo[100], caracter;
    int total_A = 0;
    int total_E = 0;
    int total_I = 0;
    int total_O = 0;
    int total_U = 0;
    FILE *archivo;

    printf("\n--- Calcular frecuencia de aparicion de vocales ---\n");

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    while ((caracter = fgetc(archivo)) != EOF) {
        char c_lower = tolower(caracter);

        if (c_lower == 'a') {
            total_A++;
        } else if (c_lower == 'e') {
            total_E++;
        } else if (c_lower == 'i') {
            total_I++;
        } else if (c_lower == 'o') {
            total_O++;
        } else if (c_lower == 'u') {
            total_U++;
        }
    }

    fclose(archivo);
    printf("Calcular frecuencia de aparicion de vocales en el archivo '%s':\n", nombreArchivo);
    printf("Total de 'A': %d\n", total_A);
    printf("Total de 'E': %d\n", total_E);
    printf("Total de 'I': %d\n", total_I);
    printf("Total de 'O': %d\n", total_O);
    printf("Total de 'U': %d\n", total_U);
}


char* reemplazar_palabra_local(const char* texto, const char* palabraOriginal, const char* palabraNueva) {
    int i, contador = 0;
    int largoOriginal = strlen(palabraOriginal);
    int largoNuevo = strlen(palabraNueva);

    for (i = 0; texto[i] != '\0'; i++) {
        if (strstr(&texto[i], palabraOriginal) == &texto[i]) {
            contador++;
            i += largoOriginal - 1;
        }
    }

    int nuevoTamanio = strlen(texto) + contador * (largoNuevo - largoOriginal) + 1;
    char* nuevoTexto = (char*)malloc(nuevoTamanio);
    if (!nuevoTexto) {
        perror("Error al asignar memoria para el nuevo texto");
        return NULL;
    }

    i = 0;
    const char* p = texto;
    while (*p) {
        if (strstr(p, palabraOriginal) == p) {
            strcpy(&nuevoTexto[i], palabraNueva);
            i += largoNuevo;
            p += largoOriginal;
        } else {
            nuevoTexto[i++] = *p++;
        }
    }
    nuevoTexto[i] = '\0';

    return nuevoTexto;
}

void cambiarPalabraEnTexto() {
    char nombreArchivo[100];
    char palabraBuscar[100];
    char palabraReemplazo[100];
    FILE* archivo;
    char* texto = NULL;

    printf("\n--- Cambiar una palabra de texto por otra ---\n");

    printf("Ingrese el nombre del archivo de texto (ejemplo: archivo.txt): ");
    scanf("%99s", nombreArchivo);

    archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    long tamanio = ftell(archivo);
    rewind(archivo);

    texto = (char*)malloc(tamanio + 1);
    if (!texto) {
        perror("Error al asignar memoria para el texto del archivo");
        fclose(archivo);
        return;
    }

    size_t bytesLeidos = fread(texto, 1, tamanio, archivo);
    texto[bytesLeidos] = '\0';
    fclose(archivo);

    printf("Ingrese la palabra que desea buscar: ");
    scanf("%99s", palabraBuscar);

    printf("Ingrese la palabra con la que desea reemplazarla: ");
    scanf("%99s", palabraReemplazo);

    char* textoModificadoLocal = reemplazar_palabra_local(texto, palabraBuscar, palabraReemplazo);

    if (textoModificadoLocal != NULL) {
        printf("\nTexto modificado:\n%s\n", textoModificadoLocal);

        if (g_textoModificado != NULL) {
            free(g_textoModificado);
            g_textoModificado = NULL;
        }
        g_tamanoTextoModificado = strlen(textoModificadoLocal);
        g_textoModificado = (char*)malloc(g_tamanoTextoModificado + 1);
        if (g_textoModificado == NULL) {
            perror("Error al asignar memoria para la copia global del texto modificado");
            free(textoModificadoLocal);
            free(texto);
            return;
        }
        strcpy(g_textoModificado, textoModificadoLocal);

        printf("\nEl texto modificado ha sido guardado internamente para la opcion 4.\n");
        free(textoModificadoLocal);
    }

    free(texto);
}


void calcular_estadisticas_para_guardar(const char* texto, int* caracteres, int* palabras, int* espacios, int* lineas) {
    *caracteres = 0;
    *palabras = 0;
    *espacios = 0;
    *lineas = 1;

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
    if (en_palabra) (*palabras)++;
    if (*caracteres == 0 && *lineas == 1) {
        *lineas = 0;
    } else if (*caracteres > 0 && *lineas == 0) {
        *lineas = 1;
    }
}

void frecuencia_vocales_para_guardar(const char* texto, int* fa, int* fe, int* fi, int* fo, int* fu) {
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


void guardarResultadosEnArchivo() {
    if (g_textoModificado == NULL) {
        printf("\nNo hay un texto modificado para guardar. Por favor, realice la opcion 3 (Cambiar una palabra) primero.\n");
        return;
    }

    int caracteres, palabras, espacios, lineas;
    calcular_estadisticas_para_guardar(g_textoModificado, &caracteres, &palabras, &espacios, &lineas);

    int fa, fe, fi, fo, fu;
    frecuencia_vocales_para_guardar(g_textoModificado, &fa, &fe, &fi, &fo, &fu);

    char archivoSalida[100];
    printf("\n--- Guardar los resultados en un nuevo archivo ---\n");
    printf("Ingrese el nombre del archivo donde se guardarán los resultados: ");
    scanf("%99s", archivoSalida);

    FILE* fSalida = fopen(archivoSalida, "w");
    if (!fSalida) {
        perror("No se pudo crear el archivo de salida");
        return;
    }

    fprintf(fSalida, "Estadisticas del texto modificado:\n");
    fprintf(fSalida, "Caracteres (sin contar saltos de linea): %d\n", caracteres);
    fprintf(fSalida, "Palabras: %d\n", palabras);
    fprintf(fSalida, "Espacios en blanco: %d\n", espacios);
    fprintf(fSalida, "Lineas: %d\n\n", lineas);

    fprintf(fSalida, "Frecuencia de vocales en el texto modificado:\n");
    fprintf(fSalida, "a: %d\n", fa);
    fprintf(fSalida, "e: %d\n", fe);
    fprintf(fSalida, "i: %d\n", fi);
    fprintf(fSalida, "o: %d\n", fo);
    fprintf(fSalida, "u: %d\n\n", fu);

    fprintf(fSalida, "Texto modificado:\n%s\n", g_textoModificado);

    fclose(fSalida);

    printf("Resultados guardados en '%s'\n", archivoSalida);
}


int main(void) {
    int opcion;

    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcion);

        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                leerYMostrarArchivo();
                break;
            case 2:
                calcularEstadisticasTexto();
                break;
            case 3:
                cambiarPalabraEnTexto();
                break;
            case 4:
                guardarResultadosEnArchivo();
                break;
            case 5:
                printf("Usted ha salido correctamente.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, intente de nuevo.\n");
                break;
        }
    } while (opcion != 5);

    if (g_textoModificado != NULL) {
        free(g_textoModificado);
    }

    return 0;
}


void mostrarMenuPrincipal() {
    printf("\n--- A continuacion se mostraran las diferentes opciones que se pueden realizar, para analizar su archivo. ---\n");
    printf("Ingrese el numero de la opcion que desea realizar.\n");
    printf("1. Leer y mostrar el contenido de un archivo.\n");
    printf("2. Calcular estadisticas del texto.\n");
    printf("3. Cambiar una palabra de texto por otra.\n");
    printf("4. Guardar los resultados en un nuevo archivo.\n");
    printf("5. Salir.\n");
    printf("Ingrese su opcion: ");
}