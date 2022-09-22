/*
20. Leia um valor de massa em quilogramas e apresente-o convertido em libras. A fórmula
de conversão é: L = K / 0,45 , sendo K a massa em quilogramas e L a massa em libras.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float qui, li;

    scanf ( "%f", &qui );
    li = qui / 0.45;

    printf ( "%.2f quilogramas equivalem a: %.2f libras. ", qui, li );

    return 0;
}