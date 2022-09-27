/*
Escreva um programa para verificar se uma expressão matemática tem os parênteses agrupados de 
forma correta, isto é: (1) se o número de parênteses à esquerda e à direita são iguais e; (2) se todo 
parêntese aberto é seguido posteriormente por um fechamentode parêntese.

Ex1: As expressões ((A+B) ou A+B( violam a condição 1

Ex2: As expressões )A+B( –C ou (A+B)) –(C + D violam a condição 2

O usuário digita uma letra e tecla enter até que ele digite x e enter para terminar a sequência.

Implemente a função POP e PUSH de pilha e resolva o problema com elas. No vídeo demonstre pelo 
menos 4 casos de sim e 4 casos de não.

Aviso: Conto com a honestidade de todos!
*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct {
	char *cChar;
	int iNum;
} Stack_t; 

Stack_t* InitStack () {
	Stack_t *Equation = ( Stack_t* ) malloc ( sizeof ( Stack_t ) );
	Equation -> cChar = ( char* ) malloc ( sizeof ( char ) );
	Equation -> iNum = 0;

	return Equation;
}
 
 
void Add ( char Char [ 1 ], Stack_t *Equation_add ) {
	Equation_add -> iNum = Equation_add -> iNum + 1;
	Equation_add -> cChar = realloc ( Equation_add -> cChar, ( sizeof ( char ) * Equation_add -> iNum ) );
	Equation_add -> cChar [ Equation_add -> iNum ] = Char [ 0 ];
}
 
void Remove ( char Char [ 1 ], Stack_t *Equation ) {
	if ( Equation -> iNum == 0 ) {
		printf ( "Erro! Pilha vazia!" );

		return;
	}

	Equation -> iNum--;
	Char [ 0 ] = Equation -> cChar [ Equation -> iNum ];
	Equation -> cChar = realloc ( Equation -> cChar, ( sizeof ( char ) * Equation -> iNum ) );

	return;
}

void Print ( Stack_t *Equation ) {
	for ( int i = 0; i < Equation -> iNum; i++ ) {
		printf ("%c ", Equation -> cChar [ i ] );
	}

	return;
}

int main () {	
	Stack_t *Equation = InitStack ();
	Stack_t *ParCount = InitStack ();
	char cChar [ 1 ];
	int *pLeftPar, *pRightPar, *pClosedPar, *pError;

	printf ( "Teste de parênteses!" );
	printf ( "\nDigite caracteres para formar uma expressão matemática!" );
	printf ( "\nDigite a letra \"x\" para encerrar o programa." );
	
	do {
		printf ( "\nSímbolo a ser adicionado: " );
		scanf ( "%c", cChar );
		getchar ();

		if ( cChar [ 0 ] != 'x' ){
			Add ( cChar, Equation );
		}			
	} while( cChar [ 0 ] != 'x');

	int i;
	char *cChar2 = NULL;

	for ( i = 0; i < Equation -> iNum; i++ ) {
		if ( Equation -> cChar [ i ] == '(' || Equation -> cChar [ i ] == ')' ) {
			*cChar2 = Equation -> cChar [ i ];
			Add ( cChar2, ParCount );
		}
	}

	for ( i = 0; i < ParCount -> iNum; i++ ) {
		if ( ParCount -> cChar [ i ] == '(' ) {
			*pLeftPar++;

		} else if ( ParCount -> cChar [ i ] == ')' ) {
			*pRightPar++;

			if ( *pLeftPar == *pRightPar ) {
				*pClosedPar++;

			} else if ( *pLeftPar < *pRightPar ) {
				*pError++;
			}
		}
	}

	printf ( "A expressão dada foi: " );
	Print ( Equation );
	printf ("\n\n-----Testando o agrupamento de parênteses-----" );

	if ( ParCount -> iNum % 2 == 0 ) {
		printf ( "\n\n- A expressão dada respeita a condição ( 1 )" );
	
	} else {
		printf ( "\n\n- A expressão dada não respeita a condição ( 1 )" );
	}

	if ( *pError == 0 && pClosedPar == pLeftPar ) {
		printf ( "\n\n- A expressão dada respeita a condição ( 2 )" );

	} else {
		printf ( "\n\n- A expressão dada não respeita a condição ( 2 )" );
	}

	free ( Equation -> cChar );
	free ( Equation );
	free ( ParCount -> cChar );
	free ( ParCount );

	return 0;
}