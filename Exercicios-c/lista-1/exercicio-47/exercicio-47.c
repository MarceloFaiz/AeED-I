/*
47. Leia um número inteiro de 4 dígitos (de 1000 a 9999) e imprima 1 dígito por linha.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int numero;

    printf ( "Digite um numero inteiro de 4 digitos: " );
    scanf ( "%d", &numero );
    printf ("Primeiro digito:   %d \n", numero / 1000 % 10 );
    printf ("Segundo digito:    %d \n", numero / 100 % 10 );
    printf ("Terceiro digito:   %d \n", numero / 10 % 10);
    printf ("Quarto digito:     %d \n", numero % 10 );
    
    return 0;
}