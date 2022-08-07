/*
9. Faça uma função que receba a altura e o raio de um cilindro circular e retorne o volume
do cilindro. O volume de um cilindro circular é calculado por meio da seguinte fórmula:
V = π ∗ raio^2 ∗ altura, onde π = 3.141592.
*/

#include <stdio.h>

int main() {

    float pi = 3.141592;
    float r, h, v;

    printf("Digite o valor do raio: ");
    scanf("%f", &r);

    printf("Digite o valor da altura: ");
    scanf("%f", &h);

    v = pi * (r * r) * h;

    printf("Volume do cilindro: %.3f", v);

    return 0;
}
