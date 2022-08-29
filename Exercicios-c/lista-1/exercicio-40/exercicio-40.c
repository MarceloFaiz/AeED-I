/*
40. Uma empresa contrata um encanador a R$ 30.00 por dia. Faça um programa que solicite
o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser
paga, sabendo-se que são descontados 8% para imposto de renda.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float salario, diaria = 30.00;
    int dia;

    printf ( "Informe o numero de dias trabalhados pelo encanador: " );
    scanf ( "%d", &dia );

    salario = ( diaria * dia ) - ( diaria * dia ) * 0.08;

    printf ( "O valor a ser pago e: %.2f R$. ", salario );

    return 0;
}