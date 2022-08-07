/*
8. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição desse array.
*/

#include <stdio.h>

int main(void) {

    float array[10];  

    printf("Enderecos do array: \n");

    for (int i=0; i<10; i++) {

        printf("%p\n", (void*) &array[i]);
    }

    return 0;
}
