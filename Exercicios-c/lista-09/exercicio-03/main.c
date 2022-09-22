/*
3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do
teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iInt1, iInt2;

    scanf ( "%d", &iInt1 );
    scanf ( "%d", &iInt2 );

    if ( &iInt1 < &iInt2 ) {
        printf ( "Conteúdo da variável de maior endereço ( iInt2 = %p): %d!", &iInt2, iInt2 );
    } else if ( &iInt2 < &iInt1 ) {
        printf ( "Conteúdo da variável de maior endereço ( iInt1 = %p): %d!", iInt1, iInt1 );
    }
    
    return 0;
}