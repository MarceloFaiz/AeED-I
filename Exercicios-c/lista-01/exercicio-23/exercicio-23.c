/*
23. Leia um valor de comprimento em metros e apresente-o convertido em jardas. A fórmula
de conversão é: J = M / 0.91 , sendo J o comprimento em jardas e M o comprimento em
metros.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float met, jar;

    scanf ( "%f", &met );
    jar = met / 0.91;

    printf ( "%.2f metros equivalem a: %.2f jardas. ", met, jar );

    return 0;
}