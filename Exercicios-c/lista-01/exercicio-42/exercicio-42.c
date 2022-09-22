/*
42. Receba o salário-base de um funcionário. Calcule e imprima o salário a receber, sabendo-
se que esse funcionário tem uma gratificação de 5% sobre o salário-base. Além disso,
ele paga 7% de imposto sobre o salário-base.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float sal, gra, imp;

    scanf ( "%f", &sal );
    gra = sal * 0.05;
    imp = sal * 0.07;

    printf ( "O valor de seu salario e: %.2f R$", sal + gra - imp);
    
    return 0;
}