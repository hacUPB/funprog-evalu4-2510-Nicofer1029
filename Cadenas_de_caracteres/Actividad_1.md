# Actividad 1: Investigación práctica

Funciones de <string.h>
Esta biblioteca proporciona funciones para manipular cadenas de caracteres (arrays de tipo char terminados en un carácter nulo \0).

1. strlen

- ¿Para qué sirve? Calcula la longitud de una cadena de caracteres, es decir, el número de caracteres que contiene antes del carácter nulo de terminación.

- Prototipo: size_t strlen(const char *s);

- Parámetros:
    - s: Un puntero constante a la cadena de caracteres cuya longitud se va a calcular. El calificador const indica que la función no modificará la cadena apuntada por s.

Ejemplo:

C

´´´

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Hola, mundo!";
    size_t longitud = strlen(cadena);
    printf("La longitud de la cadena '%s' es: %zu\n", cadena, longitud);
    return 0;
}

´´´

2. strcpy

- ¿Para qué sirve? Copia la cadena de caracteres apuntada por la fuente (incluyendo el carácter nulo) al destino. Importante: Se debe asegurar que el array destino tenga suficiente espacio para contener la cadena fuente, incluyendo el carácter nulo. De lo contrario, puede haber desbordamiento de búfer.

- Prototipo: char *strcpy(char *dest, const char *src);

- Parámetros:
    - dest: Un puntero al array de caracteres destino donde se copiará la cadena.
    - src: Un puntero constante a la cadena de caracteres fuente que se va a copiar.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char fuente[] = "Copiando esta cadena";
    char destino[50]; // Aseguramos suficiente espacio
    strcpy(destino, fuente);
    printf("La cadena fuente es: '%s'\n", fuente);
    printf("La cadena destino es: '%s'\n", destino);
    return 0;
}


3. strncpy

- ¿Para qué sirve? Copia hasta n caracteres de la cadena fuente a la cadena destino. Si la longitud de la cadena fuente es menor que n, el destino se rellena con caracteres nulos hasta alcanzar la longitud n. Si la longitud de la cadena fuente es mayor o igual a n, el destino no estará terminado con un carácter nulo.

- Prototipo: char *strncpy(char *dest, const char *src, size_t n);

- Parámetros:
    - dest: Un puntero al array de caracteres destino donde se copiará la cadena.
    - src: Un puntero constante a la cadena de caracteres fuente que se va a copiar.
    - n: El número máximo de caracteres que se copiarán de la fuente.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char fuente[] = "Copiando parcialmente";
    char destino1[10];
    char destino2[5];

    strncpy(destino1, fuente, 9);
    destino1[9] = '\0'; // Aseguramos la terminación nula
    printf("Copia de 9 caracteres: '%s'\n", destino1);

    strncpy(destino2, fuente, 4);
    // En este caso, destino2 NO está terminado con '\0'
    printf("Copia de 4 caracteres (sin terminación nula): '");
    for (int i = 0; i < 4; i++) {
        printf("%c", destino2[i]);
    }
    printf("'\n");

    return 0;
}

4. strcat

- ¿Para qué sirve? Concatena (añade) la cadena fuente al final de la cadena destino. El carácter nulo de terminación original del destino es sobrescrito por el primer carácter de la fuente, y un nuevo carácter nulo se añade al final de la cadena resultante. Importante: Se debe asegurar que el array destino tenga suficiente espacio para contener la concatenación de ambas cadenas (incluyendo el carácter nulo).

- Prototipo: char *strcat(char *dest, const char *src);

- Parámetros:
    - dest: Un puntero al array de caracteres destino al que se le añadirá la cadena fuente. Debe tener suficiente espacio.
    - src: Un puntero constante a la cadena de caracteres fuente que se añadirá al final del destino.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char destino[50] = "Hola, ";
    char fuente[] = "mundo!";
    strcat(destino, fuente);
    printf("Cadena concatenada: '%s'\n", destino);
    return 0;
}

5. strncat

- ¿Para qué sirve? Concatena como máximo n caracteres de la cadena fuente al final de la cadena destino. Se añade un carácter nulo al final de la cadena resultante. Si la cadena fuente tiene menos de n caracteres, solo se concatenan los caracteres presentes.

- Prototipo: char *strncat(char *dest, const char *src, size_t n);

- Parámetros:
    - dest: Un puntero al array de caracteres destino al que se le añadirán los caracteres de la cadena fuente. Debe tener suficiente espacio para la cadena resultante más el carácter nulo.
    - src: Un puntero constante a la cadena de caracteres fuente cuyos primeros n caracteres (o menos si es más corta) se añadirán al destino.
    - n: El número máximo de caracteres que se concatenarán de la fuente.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char destino[50] = "Esta es la primera parte. ";
    char fuente[] = "Y esta es la segunda parte, mucho más larga.";
    strncat(destino, fuente, 10);
    printf("Cadena concatenada (máximo 10 caracteres): '%s'\n", destino);
    return 0;
}

6. strcmp

- ¿Para qué sirve? Compara dos cadenas de caracteres lexicográficamente (según el orden alfabético o el valor ASCII de sus caracteres).

- Prototipo: int strcmp(const char *s1, const char *s2);

- Parámetros:
    - s1: Un puntero constante a la primera cadena de caracteres a comparar.
    - s2: Un puntero constante a la segunda cadena de caracteres a comparar.

- Valor de retorno:
    - Devuelve 0 si las cadenas s1 y s2 son iguales.
    - Devuelve un valor negativo si s1 es lexicográficamente menor que s2.
    - Devuelve un valor positivo si s1 es lexicográficamente mayor que s2.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[] = "manzana";
    char cadena2[] = "manzana";
    char cadena3[] = "pera";
    char cadena4[] = "mandarina";

    if (strcmp(cadena1, cadena2) == 0) {
        printf("'%s' es igual a '%s'\n", cadena1, cadena2);
    } else {
        printf("'%s' no es igual a '%s'\n", cadena1, cadena2);
    }

    if (strcmp(cadena1, cadena3) < 0) {
        printf("'%s' es menor que '%s'\n", cadena1, cadena3);
    } else {
        printf("'%s' no es menor que '%s'\n", cadena1, cadena3);
    }

    if (strcmp(cadena1, cadena4) > 0) {
        printf("'%s' es mayor que '%s'\n", cadena1, cadena4);
    } else {
        printf("'%s' no es mayor que '%s'\n", cadena1, cadena4);
    }

    return 0;
}

7. strncmp

- ¿Para qué sirve? Compara los primeros n caracteres de dos cadenas de caracteres lexicográficamente.

Prototipo: int strncmp(const char *s1, const char *s2, size_t n);

- Parámetros:
    - s1: Un puntero constante a la primera cadena de caracteres a comparar.
    - s2: Un puntero constante a la segunda cadena de caracteres a comparar.
    - n: El número máximo de caracteres a comparar de ambas cadenas.

- Valor de retorno: Similar a strcmp, basado en la comparación de los primeros n caracteres.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[] = "comparacion";
    char cadena2[] = "comparativa";

    if (strncmp(cadena1, cadena2, 7) == 0) {
        printf("Los primeros 7 caracteres de '%s' y '%s' son iguales.\n", cadena1, cadena2);
    } else {
        printf("Los primeros 7 caracteres de '%s' y '%s' son diferentes.\n", cadena1, cadena2);
    }

    if (strncmp(cadena1, "compara", 8) == 0) {
        printf("Los primeros 8 caracteres de '%s' son iguales a 'compara'.\n", cadena1);
    }

    return 0;
}

8. strchr

- ¿Para qué sirve? Busca la primera ocurrencia de un carácter específico dentro de una cadena de caracteres.

- Prototipo: char *strchr(const char *s, int c);

- Parámetros:
    - s: Un puntero constante a la cadena de caracteres donde se realizará la búsqueda.
    - c: El carácter que se va a buscar (se promociona a un int).

- Valor de retorno:
    - Devuelve un puntero a la primera ocurrencia del carácter c en la cadena s.
    - Devuelve NULL si el carácter c no se encuentra en la cadena s.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Este es un ejemplo.";
    char caracter_buscar = 'e';
    char *ptr = strchr(cadena, caracter_buscar);

    if (ptr != NULL) {
        printf("El carácter '%c' se encontró en la posición: %ld\n", caracter_buscar, ptr - cadena);
        printf("La subcadena a partir de la primera ocurrencia es: '%s'\n", ptr);
    } else {
        printf("El carácter '%c' no se encontró en la cadena.\n", caracter_buscar);
    }

    char caracter_no_existe = 'z';
    ptr = strchr(cadena, caracter_no_existe);
    if (ptr == NULL) {
        printf("El carácter '%c' no se encontró en la cadena.\n", caracter_no_existe);
    }

    return 0;
}

9. strstr

- ¿Para qué sirve? Busca la primera ocurrencia de una subcadena dentro de una cadena de caracteres.

- Prototipo: char *strstr(const char *haystack, const char *needle);

- Parámetros:
    - haystack: Un puntero constante a la cadena de caracteres donde se realizará la búsqueda (la cadena principal).
    - needle: Un puntero constante a la subcadena que se va a buscar.
    
- Valor de retorno:
    - Devuelve un puntero al inicio de la primera ocurrencia de la subcadena needle en la cadena haystack.
    - Devuelve NULL si la subcadena needle no se encuentra en la cadena haystack.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Esta es una cadena de ejemplo para buscar una subcadena.";
    char subcadena[] = "ejemplo";
    char *ptr = strstr(cadena, subcadena);

    if (ptr != NULL) {
        printf("La subcadena '%s' se encontró en la posición: %ld\n", subcadena, ptr - cadena);
        printf("La subcadena a partir de la primera ocurrencia es: '%s'\n", ptr);
    } else {
        printf("La subcadena '%s' no se encontró en la cadena.\n", subcadena);
    }

    char subcadena_no_existe[] = "inexistente";
    ptr = strstr(cadena, subcadena_no_existe);
    if (ptr == NULL) {
        printf("La subcadena '%s' no se encontró en la cadena.\n", subcadena_no_existe);
    }

    return 0;
}

10. strtok

- ¿Para qué sirve? Divide una cadena de caracteres en una secuencia de tokens (subcadenas) delimitados por caracteres específicos (delimitadores). Importante: strtok modifica la cadena original. En llamadas posteriores con un puntero NULL como primer argumento, continúa tokenizando la misma cadena. No es reentrante y puede tener comportamientos inesperados en entornos multihilo o al procesar cadenas de forma anidada.

- Prototipo: char *strtok(char *str, const char *delim);

- Parámetros:
    - str: Un puntero a la cadena de caracteres que se va a tokenizar. En la primera llamada, debe ser la cadena original. En llamadas posteriores para continuar la tokenización de la misma cadena, debe ser NULL.
    - delim: Un puntero constante a una cadena que contiene los caracteres delimitadores.

- Valor de retorno:
    - Devuelve un puntero al siguiente token encontrado.
    - Devuelve NULL si no se encuentran más tokens.

Ejemplo:

C

#include <stdio.h>
#include <string.h>

int main() {
    char cadena[] = "Esto,es;un-ejemplo de tokenización.";
    char delimitadores[] = ",;- ";
    char *token;

    token = strtok(cadena, delimitadores);
    while (token != NULL) {
        printf("Token: '%s'\n", token);
        token = strtok(NULL, delimitadores);
    }

    // La cadena original 'cadena' ha sido modificada por strtok.
    printf("Cadena original modificada: '%s'\n", cadena);

    return 0;
}