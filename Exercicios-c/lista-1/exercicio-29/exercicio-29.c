/*
29. Leia quatro notas, calcule a média aritmética e imprima o resultado.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float nota1, nota2, nota3, nota4, media;

    scanf ( "%f %f %f %f", &nota1, &nota2, &nota3, &nota4 );
    media = ( nota1 + nota2 + nota3 + nota4 ) / 4;

    printf ( "A media aritmetica de %.1f, %.1f, %.1f e %.1f e: %.2f. ", nota1, nota2, nota3, nota4, media );

    return 0;
}