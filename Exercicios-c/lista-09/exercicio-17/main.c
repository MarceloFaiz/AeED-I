/*
17. Escreva uma função que dado um número real passado como parâmetro, retorne a parte
inteira e a parte fracionária deste número. Escreva um programa que chama esta função.
Protótipo:
void frac(float num, int* inteiro, float* frac);
*/

#include <stdio.h>
#include <stdlib.h>

void frac(float num, int* inteiro, float* frac);

int main () {
    float num, fract;
    int inteiro;

    printf ( "Digite um número real: " );
    scanf ( "%f", &num );

    frac ( num, &inteiro, &fract );

    printf ( "Separando o número %.2f em parte inteira e fracionária, temos: %d como a parte inteira e %.2f como a parte fracionária! ", num, inteiro, fract );
    
    return 0;
}

void frac(float num, int* inteiro, float* frac) {

    *inteiro = ( int ) num;

    *frac = num - *inteiro;

}