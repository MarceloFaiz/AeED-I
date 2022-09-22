/*
2. Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e
exiba o maior endereço.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iInt1 = 1, *pPtr1, iInt2 = 0, *pPtr2;

    pPtr1 = &iInt1;
    pPtr2 = &iInt2;

    if ( pPtr1 < pPtr2 ) {
        printf ( "O endereço %p de pPtr2 é maior que o endereço %p de pPtr1! ", pPtr2, pPtr1 );
    } else if ( pPtr2 < pPtr1 ) {
        printf ( "O endereço %p de pPtr1 é maior que o endereço %p de pPtr2! ", pPtr1, pPtr2 );
    }
    
    return 0;
}