/*
22. Leia um valor de comprimento em jardas e apresente-o convertido em metros. A fórmula
de conversão é: M = 0.91 ∗ J, sendo J o comprimento em jardas e M o comprimento
em metros.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float jar, met;

    scanf ( "%f", &jar );
    met = 0.91 * jar;

    printf ( "%.2f jardas equivalem a: %.2f metros. ", jar, met );

    return 0;
}