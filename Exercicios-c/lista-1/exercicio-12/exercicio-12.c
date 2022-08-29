/*
12. Leia uma distância em milhas e apresente-a convertida em quilômetros. A fórmula de
conversão é: K = 1.61 ∗ M , sendo K a distância em quilômetros e M em milhas.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float mi, km;

    scanf ( "%f", &mi );
    km = 1.61 * mi;

    printf ( "%.2f milhas equivalem a: %.2f kilometros. ", mi, km );

    return 0;
}