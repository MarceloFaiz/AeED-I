/*
25. Faça um programa que possua uma função para:
    • ler 2 notas e retorná-las por parâmetro (chamar uma função dedicada a ler 2 notas
    válidas e que devolver os 2 nímeros lidos);

    • calcular a média simples e a média ponderada e retorná-las por parâmetro, onde a
    segunda nota tem peso 2. média ponderada = (n1 + n2 ∗ 2)/3;
*/

#include <stdio.h>
#include <stdlib.h>

void ReadGrade ( float *Grade1, float *Grade2 );
void AvgCalc ( float *Grade1, float *Grade2, float *SAvg, float *WAvg );

int main () {
    float fGrade1, fGrade2, fSAvg, fWAvg;

    ReadGrade ( &fGrade1, &fGrade2 );
    printf ( "Nota 1: %.1f \n", fGrade1 );
    printf ( "Nota 2: %.1f \n", fGrade2 );

    AvgCalc ( &fGrade1, &fGrade2, &fSAvg, &fWAvg );
    printf ( "Média simples entre a nota 1 e a nota 2: %.1f \n", fSAvg );
    printf ( "Média ponderada entre a nota 1 e a nota 2: %.1f \n", fWAvg );
    
    return 0;
}

void ReadGrade ( float *Grade1, float *Grade2 ) {
    printf ( "Digite o valor referente à nota 1: " );
    scanf ( "%f", Grade1 );

    printf ( "Digite o valor referente à nota 2: " );
    scanf ( "%f", Grade2 );

    return 0;
}

void AvgCalc ( float *Grade1, float *Grade2, float *SAvg, float *WAvg ) {
    *SAvg = ( *Grade1 + *Grade2 ) / 2;
    
    *WAvg = ( *Grade1 + ( *Grade2 * 2 ) ) / 3;
}