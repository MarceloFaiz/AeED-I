/*
26. Leia um valor de área em metros quadrados m² e apresente-o convertido em hectares.
A fórmula de conversão é: H = M ∗ 0.0001, sendo M a área em metros quadrados e H
a área em hectares.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float metro, hectare;

    scanf ( "%f", &metro );
    hectare = metro * 0.0001;

    printf ( "%.2f metros quadrados equivalem a: %.4f hectares.", metro, hectare );

    return 0;
}