/*
8. Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius. A
fórmula de conversão é: C = K − 273.15, sendo C a temperatura em Celsius e K a
temperatura em Kelvin.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float k, c;

    scanf ( "%f", &k );
    c = k - 273.15;

    printf ( "%.2f graus Kelvin equivalem a: %.2f graus Celsius.", k, c );

    return 0;
}