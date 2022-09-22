/*
30. Leia um valor em real e a cotação do dólar. Em seguida, imprima o valor correspondente
em dólares.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float real, cambio, dolar;
    
    printf ( "Quantos R$ voce tem? " );
    scanf ( "%f", &real );
    printf ( "Qual e a cotacao do US$? " );
    scanf ( "%f", &cambio );

    dolar = real / cambio;

    printf ( "Voce tem %.2f US$. ", dolar );

    return 0;
}