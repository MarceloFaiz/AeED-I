#include <stdio.h>
#include <stdlib.h>


void selectionsort1 ( int *nums, int qty ) {
	int i, j, x, swap;

	for ( i = 0; i < qty - 1; i++ ) {
		x = nums [ i ];

		for ( j = i + 1; j < qty; j++ ) {
			if ( nums [ j ] % 2 == 0 ) {
				x = nums [ j ];
				break;

			}
			
		}

		if ( x % 2 == 1 ) {
			return;

		} else {
			swap = nums [ i ];
			nums [ i ] = x;
			nums [ j ] = swap;

		}

	}
}

void selectionsort2 ( int *nums, int qty ) {
	int i, j, x, swap;

	for ( i = 0; i < qty - 1; i++ ) {
		x = i;

		for ( j = i + 1; j < qty; j++ ) {
			if ( nums [ j ] % 2 == 0 ) {
				x = j;

			}

		}

		if ( i != x ) {
			swap = nums [ i ];
			nums [ i ] = nums [ x ];
			nums [ x ] = swap;

		}

	}
}

void insertionsort ( int *nums, int qty ) {
	int i, j, x;

	for ( j = 1; j < qty; j++ ) {
		x = nums [ j ];
		i = j - 1;

		while ( i >= 0 && x % 2 == 0 ) {
			nums [ i + 1 ] = nums [ i ];
			i--;

		}

		nums [ i + 1 ] = x;

	}
}

int main() {
 	int nums [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int iQty = sizeof ( nums ) / sizeof ( nums [ 0 ] );
	int iChoice;

	printf ( "Escolha um método de ordenação:\n" );
	printf ( "1 - Seleção ( feito em aula )\n" );
	printf ( "2 - Seleção ( feito em casa )\n" );
	printf ( "3 - Inserção\n" );
	printf ( "Sua escolha: ");
	scanf ( "%d", &iChoice );
	getchar ();

	if ( iChoice == 1 ) {
		selectionsort1 ( nums, iQty );

		for ( int i = 0; i < iQty; i++ ){
			printf ( " %d ", nums [ i ] );

		}

	} else if ( iChoice == 2 ) {
		selectionsort2 ( nums, iQty );

		for ( int i = 0; i < iQty; i++ ){
			printf ( " %d ", nums [ i ] );

		}

	} else if ( iChoice == 3 ) {
		insertionsort ( nums, iQty );

		for ( int i = 0; i < iQty; i++ ){
			printf ( " %d ", nums [ i ] );

		}

	} else {
		printf ( "Erro! Opção inválida!\n" );

	}

	return 0;
}