/*
43. Escreva um programa de ajuda para vendedores. A partir de um valor total lido, mostre:
• o total a pagar com desconto de 10%;
• o valor de cada parcela, no parcelamento de 3× sem juros;
• a comissão do vendedor, no caso da venda ser a vista (5% sobre o valor com des-
conto)
• a comissão do vendedor, no caso da venda ser parcelada (5% sobre o valor total)
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float total, desconto, parcela, comVista, comParcela;

    scanf ( "%f", &total );

    desconto = total - ( total / 10 );
    parcela = total / 3;
    comVista = desconto * 0.05;
    comParcela = total * 0.05;

    printf ( "Valor total: %.2f \n", total );
    printf ( "Total a pagar (10 por cento de desconto aplicado): %.2f R$. \n", desconto );
    printf ( "Valor de cada parcela (3x sem juros): %.2f R$. \n", parcela );
    printf ( "Caso a compra seja a vista, a comissao do vendedor e: %.2f R$. \n", comVista );
    printf ( "Caso a compra seja parcelada, a comissao do vendedor e: %.2f R$. \n", comParcela );

    return 0;
}