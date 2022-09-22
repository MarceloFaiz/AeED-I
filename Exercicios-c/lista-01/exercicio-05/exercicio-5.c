/*
5. Leia um número real e imprima a quinta parte deste número
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    double n, q;

    scanf ( "%lf", &n );
    q = n / 5;

    printf ( "A quinta parte de %lf é: %lf", n, q );
    
    return 0;
}