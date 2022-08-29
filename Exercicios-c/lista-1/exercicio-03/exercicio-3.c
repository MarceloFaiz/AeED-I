/*
3. Peça ao usuário para digitar três valores inteiros e imprima a soma deles.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int a, b, c, d;

    printf ( "Digite 3 numeros: " );
    scanf( "%d %d %d", &a, &b, &c );

    d = a + b + c;

    printf( "O resultado da soma é: %d", d );
}