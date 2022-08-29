/*
21. Leia um valor de massa em libras e apresente-o convertido em quilogramas. A fórmula
de conversão é: K = L ∗ 0.45, sendo K a massa em quilogramas e L a massa em libras.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int li, qui;

    scanf ( "%d", &li );
    qui = li * 0.45;

    printf ( "%d libras equivalem a: %d quilogramas. ", li, qui );

    return 0;
    
}