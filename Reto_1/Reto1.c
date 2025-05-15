#include <stdio.h>

void menu();
 
int main(void)
{
    int opcion;

    do{
    menu();
    scanf("%d", &opcion);
    
        switch (opcion)
    {
    case 1:
    printf("Calcular estadisticas del texto \n");    
    break;
        
    case 2:
    printf("Calcular frecuencia de aparicion de vocales \n");
    break;

    case 3:
    printf("Cambiar una palabra de texto por otra \n");
    break;

    case 4:
    printf("Guardar los resultados en un nuevo archivo \n");
    break;

    case 5:
    printf("Usted ha salido correctamente \n");
    break;

    default:
    printf("Opción no valida \n");
    break;
    }
    } while (opcion != 5);
    
    
    return 0;
}

void menu(){
    printf("\n A continuacion se mostraran las diferentes opciones que se pueden realizar, para analizar su arhivo. \n");
    printf("Ingrese el numero de de la opcion que desea realizar. \n");
    printf("1. Calcular estadisticas del tesxto \n 2. Calcular frecuencia de aparicion de vocales \n 3. Cambiar una palabra de texto por otra. \n 4. Guardar los resultados en un nuevo archivo. \n 5. Salir \n");
}