/*
19. Escreva uma função que aceita como parâmetro um array de inteiros com N valores, e
determina o maior elemento do array e o número de vezes que este elemento ocorreu
no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
8, 6, 15, a função deve retornar para o programa que a chamou o valor 15 e o número 3
(indicando que o número 15 ocorreu 3 vezes). A função deve ser do tipo void.
*/

#include <stdio.h>
#include <stdlib.h>

void NumberCount ( int *Array, int *Num, int *Amt );

int main () {
    int iArray [ 9 ] = { 5, 2, 15, 3, 7, 15, 8, 6, 15 }, iNum = 0, iAmt = 0;

    NumberCount ( iArray, &iNum, &iAmt );

    printf ( "No vetor, o maior número é %d, e ele foi repetido %d vez(es)! ", iNum, iAmt );
    
    return 0;
}

void NumberCount ( int *Array, int *Num, int *Amt ) {
    int i;

    for ( i = 0; i < 9; i++ ) {
        if ( *Num < *( Array + i ) ) {
            *Num = *( Array + i );
        }
    }

    for ( i = 0; i < 9; i++ ) {
        if ( *Num == *( Array + i ) ) {
            *Amt = *Amt + 1;
        }
    }

}