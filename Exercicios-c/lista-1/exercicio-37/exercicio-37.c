/*
37. Faça um programa que leia o valor de um produto e imprima o valor com desconto, tendo
em vista que o desconto foi de 12%
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float preco, desconto;

    scanf ( "%f", &preco );
    desconto = ( preco - ( preco * 0.12 ) );

    printf ( "O valor com desconto e: %.2f. ", desconto );
    return 0;
}