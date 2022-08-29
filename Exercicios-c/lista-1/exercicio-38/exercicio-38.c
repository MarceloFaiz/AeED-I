/*
38. Leia o salário de um funcionário. Calcule e imprima o valor do novo salário, sabendo que
ele recebeu um aumento de 25%.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float salario, aumento;

    scanf ( "%f", &salario );

    aumento = ( salario + ( salario * 0.25 ) );

    printf ( "Seu salario com aumento e: %.2f. ", aumento);

    return 0;
}