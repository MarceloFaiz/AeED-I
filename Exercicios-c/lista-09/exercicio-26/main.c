/*
26. Implemente uma função que calcule as raízes de uma equação do segundo grau do tipo
Ax² + Bx + C = 0. Lembrando que:

    X = −B ± √∆ / 2A

Onde:

    ∆ = B² − 4AC

A variável A tem que ser diferente de zero.

    • Se ∆ < 0 não existe real.
    • Se ∆ = 0 existe uma raiz real.
    • Se ∆ ≥ 0 existem duas raízes reais.

Essa função deve obedecer ao seguinte protótipo:

int raizes ( float A, float B, float C, float *X1, float *X2 );

Essa função deve ter como valor de retorno o número de raízes reais e distintas da
equação. Se existirem raízes reais, seus valores devem ser armazenados nas variáveis
apontadas por X1 e X2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes ( float A, float B, float C, float *X1, float *X2 );

int main () {
    float fA, fB, fC, fX1, fX2;
    int Ret;

    printf ( "Para calcular utilizar a fórmula de Bhaskara, digite um valor para A ( Ax² ): " );
    scanf ( "%f", &fA );

    printf ( "Agora, digite o valor referente à B ( Bx ): " );
    scanf ( "%f", &fB );

    printf ( "Por último, digite o valor referente à C ( C ): " );
    scanf ( "%f", &fC );

    Ret = raizes ( fA, fB, fC, &fX1, &fX2 );

    switch (Ret) {
    case 1:
        printf ( "\nComo o delta é maior que zero, são encontrados duas raizes reais.\n" );
        printf ( "Os valores referentes às raízes X1 e X2 são: %.1f e %.1f!", fX1, fX2 );
        break;
    
    case 0:
        printf ( "\nComo o delta é igual a zero, é encontrado apenas uma raiz real.\n" );
        printf ( "Os valores referentes às raízes X1 e X2 é: %.1f!", fX1 );
        break;
    
    case -1:
        printf ( "Erro! O Valor do delta é menor que zero e, portanto, não há raizes reais!" );
        break;
    }
    
    return 0;
}

int raizes ( float A, float B, float C, float *X1, float *X2 ) {
    float Dlt;

    Dlt = ( pow ( B, 2 ) - ( 4 * A * C ) );

    if ( Dlt >= 0 ) {
        *X1 = ( - B + ( sqrt ( Dlt ) ) ) / ( 2 * A );

        *X2 = ( - B - ( sqrt ( Dlt ) ) ) / ( 2 * A ); 

        if ( *X1 == *X2 ) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return -1;
    }

}