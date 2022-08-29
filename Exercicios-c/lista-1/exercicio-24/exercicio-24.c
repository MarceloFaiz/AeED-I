/*
24. Leia um valor de área em metros quadrados m² e apresente-o convertido em acres. A
fórmula de conversão é: A = M ∗ 0.000247, sendo M a área em metros quadrados e A
a área em acres.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int metro;
    float acre;

    scanf ( "%d", &metro );
    acre = metro * 0.000247;

    printf ( "%d metros quadrados equivalem a: %f acres. ", metro, acre );

    return 0;
}