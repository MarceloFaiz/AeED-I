/*
22. Crie uma função para somar dois arrays. Esta função deve receber dois arrays e retornar
a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente
então a função retornará ZERO (0). Caso a função seja concluída com sucesso a mesma
deve retornar o valor UM (1). Utilize aritmética de ponteiros para manipulação do array.
*/

#include <stdio.h>
#include <stdlib.h>

int SomaArray ( int *Array1, int *Array2, int *Array3, int Size1, int Size2 );

int main () {
    int iArray1 [ 5 ] = { 1, 2, 3, 4, 5 }; 
    int iArray2 [ 5 ] = { 5, 4, 3, 2, 1 }; 
    int iArray3 [ 5 ];
    int iRet;
    int Size_Array1, Size_Array2;

    Size_Array1 = sizeof ( iArray1 ) / sizeof *( iArray1 + 0 );
    Size_Array2 = sizeof ( iArray2 ) / sizeof *( iArray2 + 0 );

    iRet = SomaArray ( iArray1, iArray2, iArray3, Size_Array1, Size_Array2 );

    if ( iRet == 1 ) {
        printf ( "Ao somar os valores dos dois vetores em um terceiro, temos: " );
        for ( int i = 0; i < 5; i++ ) {
            printf ( "%d ", *( iArray3 + 1 ) );
        }
    } else if ( iRet == 0 ) {
        printf ( "Erro! A quantidade de elementos do primeiro vetor é diferente do segundo! " );
    }
 
    return 0;
}

int SomaArray ( int *Array1, int *Array2, int *Array3, int Size1, int Size2 ) {
    int i;

    if ( Size1 == Size2 ) {
        for ( i = 0; i < 5; i++ ) {
            *( Array3 + i ) = *( Array1 + i ) + *( Array2 + i );
        }

        return 1;
    } else {
        return 0;
    }

}