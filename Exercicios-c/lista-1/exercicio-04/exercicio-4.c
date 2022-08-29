/*
4. Leia um número real e imprima o resultado do quadrado desse número
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    double n, q;

    scanf ( "%lf", &n );
    q = n * n;

    printf ( "O quadrado de %lf é: %lf", n, q );
}