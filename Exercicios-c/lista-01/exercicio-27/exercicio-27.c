/*
27. Leia um valor de área em hectares e apresente-o convertido em metros quadrados m².
A fórmula de conversão é: M = H ∗ 10000, sendo M a área em metros quadrados e H
a área em hectares.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float hectare, metro;

    scanf ( "%f", &hectare );
    metro = hectare * 10000;

    printf ( "%f hectares equivalem a: %.2f metros quadrados.", hectare, metro );

    return 0;
}