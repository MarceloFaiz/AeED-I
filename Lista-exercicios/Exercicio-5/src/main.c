#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome [30];
	int idade;
	float altura;
} Pessoa;

Pessoa *pPessoa = NULL;
int iNumPessoas = 0;

int main () {
	int i, iEscolha = 0;

		pPessoa = ( Pessoa * ) malloc ( sizeof ( Pessoa ) );

	while ( 1 ) {
		printf ( "Deseja adicionar uma pessoa? ( 1 = sim, 0 = não ) \n" );
		printf ( "Escolha: " );
		scanf ( "%d", &iEscolha );

		if ( iEscolha == 1 ) {
			pPessoa = realloc ( pPessoa, sizeof ( Pessoa ) + ( sizeof ( Pessoa ) * iNumPessoas ) );

			if ( pPessoa == NULL ) {
				printf ( "nao foi possivel alocar memória! " );
				exit ( 0 );
			}

			printf ( "Digite um nome: " );
			scanf ( "%s", ( char * ) pPessoa + ( sizeof ( Pessoa ) * iNumPessoas ) );
			
			printf ( "Digite uma idade: " );
			scanf ( "%d", ( int * ) ( ( pPessoa + ( sizeof ( char ) * 30 ) ) + ( sizeof ( Pessoa ) * iNumPessoas ) ) );
			
			printf ( "Digite uma altura: " );
			scanf ( "%f", ( float * ) ( ( pPessoa + ( sizeof ( char ) * 30 ) + sizeof ( int ) ) + ( sizeof ( pPessoa ) * iNumPessoas ) ) );
			
			iNumPessoas++;

		} else if ( iEscolha == 0 ) {
			printf ( "\n----- Lista de pessoas -----\n" );

			for ( i = 0; i < iNumPessoas; i++ ) {

				printf ( "Nome: %s\n", ( char * ) pPessoa + ( sizeof ( Pessoa ) * i ) );
				printf ( "%d\n", * ( int * ) ( ( pPessoa + ( sizeof ( char ) * 30 ) ) + ( sizeof ( Pessoa ) * i ) ) );
				printf ( "%.2f\n", * ( float * ) ( ( pPessoa + ( sizeof ( char ) * 30 ) + sizeof ( int ) ) + ( sizeof ( pPessoa ) * i ) ) );
				printf ( "----------------------------\n");

			}
			
			break;

		} else {			
			printf ( "----- Escolha invalida! -----\n" );

		}

	}

	free ( pPessoa );

	return 0;

}