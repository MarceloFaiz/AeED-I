#include <stdio.h>
#include <stdlib.h>

void selectionsort ( int *nums, int h) {
	int i, j, x, swap;

	for ( i = 0; i < h - 1; i++ ) {
		x = nums [ i ];

		for ( j = i + 1; j < h; j++ ) {
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

void insertionsort ( int *nums ) {
	int i, j, x;

	for ( j = 1; j < 4; j++ ) {
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
 	int nums [ 4 ] = { 3 , 1 , 2 , 4 };
	int iH = 4;

	//selectionsort ( nums, iH );

	//insertionsort ( nums );

	for ( int i = 0; i < 4; i++ ){
		printf ( " %d ", nums [ i ] );
	}
	
	return 0;

}