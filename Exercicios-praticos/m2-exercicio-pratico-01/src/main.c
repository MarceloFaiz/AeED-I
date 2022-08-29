/*
	Faça um programa que solicita do usuário o tamanho de um vetor. Crie um vetor com esse
tamanho, utilizando memória dinâmica, onde números inteiros serão armazenados. Preencha esse
vetor com números inteiros gerados com a função "int rand()” e imprima o vetor. Em seguida solicite
um número inteiro do usuário. O programa deve procurar esse número dentro do vetor e indicar se
foi encontrado ou não. Caso encontre o número esse deve ser removido do vetor e o vetor deve
encolher. Caso não encontre procure dois números que somados geram o número sendo buscado,
caso encontrado ambos devem ser impressos na tela e removidos do vetor e esse deve encolher.
	Todas essas operações devem ser feitas com notação de ponteiros ( aritmética de ponteiros )
e não com notação de vetores ( vetor [10], por exemplo ).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main () {
	int i, j, iQtd1 = 0, iQtd2 = 0, iNumero, iTamanhoVetor, *pVetor;

	srand ( time ( NULL ) );	//Permite que os números gerados sejam diferentes à cada execução.

	printf ( "Qual será o tamanho do vetor? " );
	scanf ( "%d", &iTamanhoVetor );

	pVetor = ( int * ) malloc ( sizeof ( int ) * iTamanhoVetor );

	printf ( "Vetor gerado: " );

	for ( i = 0; i < iTamanhoVetor; i++ ) {		//Procura pelo numero "iNumero" e o exclui da lista.
		*( pVetor + i ) = rand () % 100;
		printf ( "%d ", *( pVetor + i ) );
	}

	printf ( "\n\nAgora, digite um número inteiro ( entre 0 e 99 ): " );
	scanf ( "%d", &iNumero );

	for ( i = 0; i < iTamanhoVetor; i++ ) { 	//Procura pelo numero "iNumero" e o exclui da lista.
		if ( *( pVetor + i ) == iNumero ) {	
			iQtd1++;

			for ( j = i; j < iTamanhoVetor - 1; j++ ) { 
				*( pVetor + j ) = *( pVetor + ( j + 1 ) );
			}

			i--; // necessário para remover o mesmo número duas vezes seguidas.
			iTamanhoVetor--;
			pVetor = realloc ( pVetor, sizeof ( int ) * iTamanhoVetor );
		}
	}	

	if ( iQtd1 == 0 ) {		// Procura por dois números que correspondam à soma do número "iNumero".
		int a, b;

		for ( i = 0; i < ( iTamanhoVetor - 1 ); i++ ) {
			for ( j = i + 1; j < iTamanhoVetor; j++ ) {
				if ( *( pVetor + i ) + *( pVetor + j ) == iNumero ) {
					iQtd2++;

					printf ( "Os números %d e %d somados resultam em %d! \n", *( pVetor + i ), *( pVetor + j ), iNumero );

					for ( a = i; a < iTamanhoVetor - 1; a++ ) {
						*( pVetor + a ) = *( pVetor + ( a + 1 ) );
					}

					for ( b = j; b < iTamanhoVetor - 1; b++ ) {
						*( pVetor + b - 1 ) = *( pVetor + b );
					}
					
					iTamanhoVetor = iTamanhoVetor - 2;
					pVetor = realloc ( pVetor, sizeof ( int ) * iTamanhoVetor );
				}
			}
		}

		printf ( "No vetor, o número %d foi encontrado %d vez(es)!\n", iNumero, iQtd2 );
		printf ( "O vetor resultante é: " );

		for ( i = 0; i < iTamanhoVetor; i++ ) {
			printf ( "%d ", *( pVetor + i ) );
		}

	} else if ( iQtd1 > 0 ) {
		printf ( "No vetor, o número %d foi encontrado %d vez(es)!\n", iNumero, iQtd1 );
		printf ( "O vetor resultante é: " );

		for ( i = 0; i < iTamanhoVetor; i++ ) {
			printf ( "%d ", *( pVetor + i ) );
		}
	}	

	free ( pVetor );	//Libera a memória alocada no ponteiro "pVetor".

	return 0;
}