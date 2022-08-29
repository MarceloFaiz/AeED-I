/*
10. Leia uma velocidade em km/h (quilômetros por hora) e apresente-a convertida em m/s
(metros por segundo). A fórmula de conversão é: M = K/3.6, sendo K a velocidade em
km/h e M em m/s.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    float km, m;

    scanf ( "%f", &km );
    m = km / 3.6;

    printf ( "%.1f kilometros por hora equivalem a: %.1f metros por segundo. ", km, m );

    return 0;
}