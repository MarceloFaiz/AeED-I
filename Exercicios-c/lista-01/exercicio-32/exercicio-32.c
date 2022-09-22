/*

*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int numero, soma;

    scanf ( "%d", &numero );

    soma = ( ( numero * 3 ) + 1 ) + ( ( numero * 2 ) - 1 );

    printf ( "A soma do sucessor do triplo de %d com o antecessor de seu dobro e: %d. ", numero, soma );
    return 0;
}