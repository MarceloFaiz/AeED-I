/*
13. Leia uma distância em quilômetros e apresente-a convertida em milhas. A fórmula de
conversão é: M = K / 1,61 , sendo K a distância em quilômetros e M em milhas.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float km, mi;

    scanf ( "%f", &km );
    mi = km / 1.61;

    printf ( "%.2f kilometros equivalem a: %.2f milhas. ", km, mi );

    return 0;
}