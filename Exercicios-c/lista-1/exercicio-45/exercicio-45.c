/*
Faça um programa para converter uma letra maiúscula em letra minúscula. Use a tabela
ASCII para resolver o problema.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    char c;

    scanf ( "%c", &c );
    printf ( "Convertendo a letra maiucsula %c para minuscula, temos: %c. ", c, c + 32);

    return 0;
}