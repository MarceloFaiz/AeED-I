/*
14. Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de conversão
é: R = G ∗ π/180, sendo G o ângulo em graus e R em radianos e π = 3.14.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float g, r, pi = 3.14;

    scanf ( "%f", &g );
    r = g * pi / 180;

    printf ( "Um angulo de %.2f graus equivale a: %.2f radianos. ", g, r );

    return 0;
}