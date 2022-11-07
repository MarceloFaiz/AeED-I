#include <stdio.h>
#include <stdlib.h>

struct node {
	int iInfo;
	int height;
	struct node *pRight;
	struct node *pLeft
};

typedef struct node* tree_t;

tree_t* Init_Tree () {
	tree_t *root;

	root = ( tree_t* ) malloc ( sizeof ( tree_t ) );

	*root = NULL;

	return root;
}

int Get_Height ( struct node* node ) {
	if ( node == NULL ) {
		return NULL;
	}

	return node -> height;
}

int Insert_Node ( tree_t *root, int value ) {
	struct node *new;

	if ( *root == NULL ) {
	new = ( struct node* ) malloc ( sizeof ( struct node ) );

	new -> iInfo = value;
	new -> height = 0;
	new -> pLeft = NULL;
	new -> pRight = NULL;

	root = new;
	}

	struct node* current_t = root;
	if ( current_t -> pLeft == NULL ) {
		current_t -> pLeft = Insert_Node ( current_t -> pLeft, value );
	} else if ( current_t -> pRight == NULL ) {
		current_t -> pRight = Insert_Node ( current_t -> pRight, value );
	}

}

tree_t* Search_Node ( tree_t *root, int value ) {
	struct node* current_t;
	if ( value != ( *root ) -> iInfo ) {
		Search_Node ( ( *root ) -> pLeft, value );
		Search_Node ( ( *root ) -> pRight, value );
	} else {
		current_t = ( *root );

		return current_t;	
	}

}

int rotate_left ( struct node *node, int value ) {
	if ( node == NULL ) {
		return 0;
	}

	

}

int rotate_right ( struct node *node, int value ) {
	if ( node == NULL ) {
		return 0;
	}
}

int main () {
	tree_t *root = Init_Tree ();
	int iValue, iResult, iChoice; 

	do {
		printf ( "Digite um número: ( para encerrar a adição de números, digite 0 )" );
		scanf ( "%d", &iValue );
		getchar ();

		if ( iValue != 0) {
			iResult = Insert_Node ( root, iValue );

			if ( iResult == 1 ) {
				printf ( "O número foi adicionado com sucesso na árvore! " );
			} else {
				printf ( "Erro! Não foi possível adicionar o número à árvore! " );
			}
		}
	} while ( iValue != 0 );

	do {
		printf ( "Digite um número que esteja presente na árvore: ( para encerrar o programa, digite 0 )" );
		scanf ( "%d", &iValue );
		getchar (); 

		if ( iValue != 0 ) {
			printf ( "Deseja realizar uma rotação à esquerda ( 1 ) ou à direita ( 2 )?" );
			scanf ( "%d", &iChoice );
			getchar ();

			switch ( iChoice ) {
				case 1:
					iResult = rotate_left ( root, iValue );
					break;
				case 2:
					iResult = rotate_left ( root, iValue );
					break;
				default:
					printf ( "Erro! Opção inválida!" );
					break;
			}

			if ( iResult == 1 ) {
				printf ( "A rotação foi bem sucedida!" );
			} else {
				printf ( "Erro! Não foi possível realizar a rotação!" );
			}			
		}
	} while ( iValue != 0 );

	return 0;
}