/*
46. Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999).
Gere outro número formado pelos dígitos invertidos do número lido. Exemplo:
Número Lido = 123
Número Gerado = 321
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int numero;

    printf ( "Digite um numero inteiro positivo (entre 100 e 999): " );
    scanf ( "%d", &numero );
    printf ( "Numero lido: %d. \n", numero );
    printf ( "Numero gerado: %d%d%d. ", numero % 10, numero / 10 % 10, numero / 100 % 10 );
    
    return 0;
}