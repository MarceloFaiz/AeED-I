/*
15. Leia um ângulo em radianos e apresente-o convertido em graus. A fórmula de conversão
é: G = R ∗ 180/π, sendo G o ângulo em graus e R em radianos e π = 3.14.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float r, g, pi = 3.14;

    scanf ( "%f", &r );
    g = r * 180 / pi;

    printf ( "%.2f radianos equivalem a: %.2f graus", r, g );

    return 0;
}