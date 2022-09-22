/*
21. Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. As-
socie o ponteiro ao array. Agora, some mais um (+1) a cada posição do array usando o
ponteiro (use *).
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iArray [ 5 ] = { 1, 2, 3, 4, 5 }, *pPtr;

    pPtr = iArray;

    for ( int i = 0; i < 5; i++ ) {
        *( pPtr + i ) = *( pPtr + i ) + 1;
        printf ( "%dº elemento do vetor: %d \n", i + 1, *( pPtr + i ) );
    }

/*
    // também funciona.
    for ( int i = 0; i < 5; i++ ) {
        printf ( "\n%dº elemento do vetor: %d \n", i + 1, iArray [ i ] );
    }
*/
  
    return 0;
}