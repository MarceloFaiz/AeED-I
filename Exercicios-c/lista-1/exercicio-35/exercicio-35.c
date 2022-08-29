/*
35. Sejam a e b os catetos de um triângulo, onde a hipotenusa é obtida pela equação:
hipotenusa = √a² + b². Faça um programa que receba os valores de a e b e calcule
o valor da hipotenusa através da equação. Imprima o resultado dessa operação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int a, b;
    float hipo;

    scanf ( "%d %d", &a, &b );
    hipo = sqrt ( ( a * a ) + ( b * b ) );

    printf ( "A hipotenusa de um quadrado com catetos %d e %d e: %.2f. ", a, b, hipo );
    return 0;
}