#include <stdio.h>
#include <stdlib.h>

int main() {
    char nombreArchivo[100];
    FILE *archivo;
    char *contenido;
    long tamano;

    printf("Ingrese el nombre del archivo .txt a leer: ");
    scanf("%s", nombreArchivo); 

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    contenido = (char *)malloc((tamano + 1) * sizeof(char));
    if (contenido == NULL) {
        perror("No se pudo asignar memoria");
        fclose(archivo);
        return 1;
    }

    
    char *fgets (char *string, int n, FILE *stream);

    printf("\n Contenido del archivo:\n%s\n", contenido);

    free(contenido);
    fclose(archivo);

    return 0;
}
