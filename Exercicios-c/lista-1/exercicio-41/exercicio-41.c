/*
41. Faça um programa que leia o valor da hora de trabalho (em reais) e número de horas
trabalhadas no mês. Imprima o valor a ser pago ao funcionário, adicionando 10% sobre
o valor calculado.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int horas;
    float salario, valor;

    printf ( "Digite o valor da hora de trabalho em R$ e o numero de horas trabalhadas. " );
    scanf ( "%f %d", &valor, &horas );

    salario = valor * horas + ( ( valor * horas ) / 10 );

    printf ( "O valor que deve ser pago ao funcionario e: %.2f R$. ", salario );
    return 0;
}