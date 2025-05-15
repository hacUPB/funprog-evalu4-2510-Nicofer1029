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

    fseek(archivo, 0, SEEK_END);
    tamano = ftell(archivo);
    rewind(archivo);

    contenido = (char *)malloc((tamano + 1) * sizeof(char));
    if (contenido == NULL) {
        perror("No se pudo asignar memoria");
        fclose(archivo);
        return 1;
    }

    
    fread(contenido, sizeof(char), tamano, archivo);
    contenido[tamano];

    printf("\n Contenido del archivo:\n%s\n", contenido);

    free(contenido);
    fclose(archivo);

    return 0;
}
