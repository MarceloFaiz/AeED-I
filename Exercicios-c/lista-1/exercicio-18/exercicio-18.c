/*
18. Leia um valor de volume em metros cúbicos m³ e apresente-o convertido em litros. A
fórmula de conversão é: L = 1000 ∗ M , sendo L o volume em litros e M o volume em
metros cúbicos.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int mc, l;

    scanf ( "%d", &mc );
    l = 1000 * mc;

    printf ( "%d metros cubicos equivalem a: %d litros. ", mc, l );

    return 0;
}