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

int main(int argc, char const *argv[])
{
    char nombreArchivo[100];
    int opcion, cant_caracteres;
    FILE *archivo;
    menu();
    printf("Para contar caracteres desea incluir los saltos de linea? \n Ingrese 1 para si, 2 para no. ");
    scanf("%d", &opcion);

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo); 

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    if (opcion == 1){
        cant_caracteres = strlen(nombreArchivo);
        printf("La cantidad de caracteres en tu archivo es: %d ", cant_caracteres);


    }
    return 0;
}


void menu(){
    printf("A continuacion se van a mostrar las siguientes estadisticas del texto:\n");
    printf(" - Total de caracteres\n");
    printf(" - Total de palabras\n");
    printf(" - Total de espacios en blanco\n");
    printf(" - Total de lineas\n\n");
}