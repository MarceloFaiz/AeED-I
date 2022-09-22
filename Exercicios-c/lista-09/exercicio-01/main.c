/*
1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para in-
teiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de
cada variável usando os ponteiros. Imprima os valores das variáveis antes e ap  ́os a
modificac ̧  ̃ao.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int iInt = 15, *pInt;
    float fFloat = 3.14, *pFloat;
    char cChar = 'B', *pChar;

    pInt = &iInt;
    pFloat = &fFloat;
    pChar = &cChar;

    printf ( "Os valores referentes aos dados int, float e char são: %d, %.2f e %c!\n", *pInt, *pFloat, *pChar );

    *pInt = 16;
    *pFloat = 2.42;
    *pChar = 'C';

    printf ( "Após as mudanças, os valores para int, float e char são: %d, %.2f e %c!", *pInt, *pFloat, *pChar );
    
    return 0;
}