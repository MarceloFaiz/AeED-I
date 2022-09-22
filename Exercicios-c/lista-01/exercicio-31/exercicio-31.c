/*
31. Leia um número inteiro e imprima o seu antecessor e o seu sucessor.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int numero, antes, depois;

    scanf ( "%d", &numero );
    
    antes = numero - 1;
    depois = numero + 1;

    printf ( "Antecessor de %d: %d.\nSucessor de %d: %d. ", numero, antes, numero, depois );
    
    return 0;
}