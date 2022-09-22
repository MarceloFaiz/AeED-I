/*
13. Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres
das strings.
*/

#include <stdio.h>
#include <stdlib.h>

int FindSubstring ( char *String1, char *String2);

int main () {
    char *pString1 = "bolo de cenoura", *pString2 = "louro";
    int iReturn;

    iReturn = FindSubstring ( pString1, pString2 );

    if ( iReturn = 1 ) {
        printf ( "A string \"%s\" foi encontrada na string \"%s\"!", pString2, pString1 );
    } else if ( iReturn = -1 ) {
        printf ( "Erro! A string %d não foi encontrada dentro da string %d! ", pString2, pString1 );
    }

    return 0;
}

int FindSubstring ( char *String1, char *String2) {
    int i = 0, j = 0;

    while ( ( *( String1 + i ) != '\0' ) && ( *( String2 +j ) != '\0' ) ) {
        if ( *( String2 + j ) != *( String1 + i ) ) {
            i++;
            j = 0;
        } else {
            i++;
            j++;
        }
    }
    if ( *( String2 + j ) == '\0' ) {
        return 1;
    } else {
        return -1;
    }

}