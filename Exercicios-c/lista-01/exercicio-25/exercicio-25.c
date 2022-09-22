/*
25. Leia um valor de área em acres e apresente-o convertido em metros quadrados m². A
fórmula de conversão é: M = A ∗ 4048.58, sendo M a área em metros quadrados e A a
área em acres.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float acre, metro;

    scanf ( "%f", &acre );
    metro = acre * 4048.58;

    printf ( "%f acres equivalem a: %f metros quadrados. ", acre, metro);

    return 0;
}