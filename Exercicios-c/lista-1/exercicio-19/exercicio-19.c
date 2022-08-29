/*
19. Leia um valor de volume em litros e apresente-o convertido em metros cúbicos m³. A
fórmula de conversão é: M = L / 1000 , sendo L o volume em litros e M o volume em metros
cúbicos.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int l, mc;

    scanf ( "%d", &l );
    mc = l / 1000;

    printf ( "%d litros equivalem a: %d metros cubicos. ", l, mc );

    return 0;
}