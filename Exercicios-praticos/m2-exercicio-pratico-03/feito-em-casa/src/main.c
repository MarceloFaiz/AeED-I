#include <stdio.h>
#include <stdlib.h>

struct node {
	int iInfo;
	struct node *pRight;
	struct node *pLeft

};

typedef struct node* tree_t;

tree_t* Init_Tree () {
	tree_t *root = ( tree_t* ) malloc ( sizeof ( tree_t ) );

	*root = NULL;

	return root;
}

int Insert_Node ( tree_t *root, int value ) {

	if ( *root == NULL ) {
		struct node *new;
		new = ( struct node* ) malloc ( sizeof ( struct node ) );
		if ( new == NULL ) {
			return 0;
		}

		new -> iInfo = value;
		new -> pLeft = NULL;
		new -> pRight = NULL;

		*root = new;

		return 1;

	}

	struct node* current_t = *root;

	if ( value < current_t -> iInfo ) {
		Insert_Node ( & ( current_t -> pLeft ), value );
		return 1;

	} else if ( value > current_t -> iInfo ) {
		Insert_Node ( & ( current_t -> pRight ), value );
		return 1;

	} else {
		return 0;

	}

	return 0;
}

int Rotate_Left ( tree_t *node ) {
	struct node *pAux;

	if ( ( *node ) -> pRight == NULL ) {
		return 0;

	} else {
		pAux = ( *node ) -> pRight;
		( *node ) -> pRight = pAux -> pLeft;
		pAux -> pLeft = ( *node ); 
		( *node ) = pAux;

		return 1;
	}
}

int Rotate_Right ( tree_t *node ) {
	struct node *pAux;

	if ( ( *node ) -> pLeft == NULL ) {
		return 0;

	} else {
		pAux = ( *node ) ->  pLeft;
		( *node ) ->  pLeft = pAux -> pRight;
		pAux -> pRight = ( *node );
		( *node ) = pAux;

		return 1;
	}
}

int Search_Node ( tree_t *root, int value, int choice ) {
	struct node **current_t = root;
	int result;

	while ( 1 ) {
		if ( value == ( *current_t ) -> iInfo ) {
			if ( choice == 1 ) {
				result = Rotate_Left ( &( *current_t ) );
				break;

			} else if ( choice == 2 ) {
				result = Rotate_Right ( &( *current_t ) );				
				break;

			}

		} else if ( value < ( *current_t ) -> iInfo ) {
			if ( ( *current_t ) -> pLeft != NULL ) {
				current_t = &( *current_t ) -> pLeft;

			} else {
				result = 0;
				break;

			}

		} else if ( value > ( *current_t ) -> iInfo ) {
			if ( ( *current_t ) -> pRight != NULL ) {
				current_t = &( *current_t ) -> pRight;

			} else {
				result = 0;
				break;

			}

		}

	}

	return result;
}

void In_Order ( tree_t *root ) {
	if ( root == NULL ) {
		return; 

	}

	if ( *root != NULL ) {
		printf ( "%d ", ( *root ) -> iInfo );
		In_Order ( & ( ( *root ) -> pLeft ) );
		In_Order ( & ( ( *root ) -> pRight ) );
	}

}

void Clear_Node ( struct node *node ) {
	if ( node == NULL ) {
		return;
	}

	Clear_Node ( node -> pLeft );
	Clear_Node ( node -> pRight );
	free ( node );

}

void Clear_Tree ( tree_t *root ) {
	if ( root == NULL ) {
		return;
	}

	Clear_Node ( *root );
	free ( root );

}

int main () {
	tree_t *root = Init_Tree ();
	int iValue, iResult, iChoice; 

	do {
		printf ( "Digite um n??mero: ( para encerrar a adi????o de n??meros, digite 0 )" );
		scanf ( "%d", &iValue );
		getchar ();

		if ( iValue != 0) {
			iResult = Insert_Node ( root, iValue );

			if ( iResult == 1 ) {
				printf ( "O n??mero foi adicionado com sucesso na ??rvore! " );

			} else {
				printf ( "Erro! N??o foi poss??vel adicionar o n??mero ?? ??rvore! " );

			}

		}

	} while ( iValue != 0 );

	do {
		printf ( "Digite um n??mero que esteja presente na ??rvore: ( para encerrar o programa, digite 0 )" );
		scanf ( "%d", &iValue );
		getchar (); 

		if ( iValue != 0 ) {
			printf ( "Deseja realizar uma rota????o ?? esquerda ( 1 ) ou ?? direita ( 2 )? " );
			scanf ( "%d", &iChoice );
			getchar ();

			switch ( iChoice ) {
				case 1:
					iResult = Search_Node ( root, iValue, iChoice );
					break;
				case 2:
					iResult = Search_Node ( root, iValue, iChoice );
					break;
				default:
					iResult = 0;
					break;

			}

			if ( iResult == 1 ) {
				printf ( "A rota????o foi bem sucedida!" );

			} else {
				printf ( "Erro! N??o foi poss??vel realizar a rota????o!" );

			}	

		}

	} while ( iValue != 0 );

	In_Order ( root );
	Clear_Tree ( root );

	return 0;
}