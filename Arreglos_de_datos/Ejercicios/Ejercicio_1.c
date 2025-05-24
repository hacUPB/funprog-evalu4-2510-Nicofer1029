#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numeros[10], i = numeros[0], j = numeros[0];

    for (i = 0; i < 10; i++){

        numeros[i] = i + 11;
        printf("%d ", numeros[i]);
    
        for (j = 9; j == 0; j--){

        printf("%d ", numeros[j]);
    }
}

    return 0;
}
