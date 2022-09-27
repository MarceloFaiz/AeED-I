#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char Symbol;
	struct Node_t *Next;
} Node_t;

Node_t *Base = NULL;
Node_t *Top = NULL;
int *NodeQty = 0;

void Push ( char c ) {
	Node_t *Node;
	Node_t *NewNode;

	if ( Base == NULL ) {
		Node = NULL;
		Node -> Symbol = c;
		Node -> Next = NULL;

		Base = Node;
		Top = Node;
		NodeQty++;

	} else {
		NewNode = NULL;
		NewNode -> Symbol = c;
		NewNode -> Next = NULL;

		Node -> Next = ( struct Node_t* ) NewNode;
		NewNode = Node;

		Top -> Next = Node -> Next;
		NodeQty++;

	}

}

int main()
{
	char Character;

	printf ( "Teste de uso de parênteses: " );

	while ( Character != 'x' ){
		printf ( "Digite os termos referentes a uma expressão matemática, adicionando parênteses quando necessário. ( Para encerrar o programa, digite a letra x. ) " );
		scanf ( "%c", &Character);

		Push ( Character );

	}

	return (0);
}