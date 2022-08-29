/*
44. Receba a altura do degrau de uma escada e a altura que o usuário deseja alcançar
subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir
seu objetivo.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    int alturaDegrau, alturaDesejada, numeroDegraus;

    scanf( "%d %d", &alturaDegrau, &alturaDesejada );
    numeroDegraus = alturaDesejada / alturaDegrau;

    printf ( "Para chegar na altura desejada, voce deve subir %d degraus. ", numeroDegraus );

    return 0;
}