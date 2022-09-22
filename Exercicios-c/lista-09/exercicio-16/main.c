/*
16. Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um programa que leia a
variável A e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quádruplo.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int A, *B, **C, ***D;

    printf ( "Qual é o valor da variável A? " );
    scanf ( "%d", &A );

    B = &A;
    C = &B;
    D = &C; 

    printf ( "Valor de A = %d \n", A );
    printf ( "Valor de B = %d \n", ( A + *B ) );
    printf ( "Valor de C = %d \n", ( A + *B + **C ) );
    printf ( "Valor de D = %d \n", ( A + *B + **C + ***D ) );
    
    return 0;
}