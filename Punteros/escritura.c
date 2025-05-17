#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *p_archivo;
    p_archivo = fopen("Texto1.txt","w");

if (p_archivo != NULL){
    printf("Se crea el archivo. \n");
}

 fprintf(p_archivo,"Este texto de pruba para el archivo texto1.txt");
 

fclose(p_archivo);

    return 0;
}
