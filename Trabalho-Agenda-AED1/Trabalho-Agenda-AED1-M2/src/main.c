/*
Agenda:

•Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.

	1. Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
    	1. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
    	2. Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)
	
	2. Não pode usar struct em todo o programa.
	
	3. Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
    
	4. Implementar a base de dados da agenda usando lista duplamente ligada
        1. Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

Seguir as orientações elaborados pelo monitor para código!
Entregar link de um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* NodeInit () {
	void *Node;

	Node = ( void* ) malloc ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) * 2 ) );

	return Node;
}

void Add ( void **Head, void *pBuffer ) {
	char *cName;
	int *iAge, *iTel, *iTracerIndex = ( int* ) ( pBuffer + sizeof ( int ) * 2 );
	void *pNode = NodeInit (), *pOldNode, **pNodeNext, **pNodePrev, **Tracer = Head;

	*iTracerIndex = 0;

	cName = ( char* ) ( pNode );
	iAge = ( int* ) ( pNode + ( sizeof ( char ) * 10 ) );
	iTel = ( int* ) ( pNode + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) ) );
	pNodePrev = ( void** ) ( pNode + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) );
	pNodeNext = ( void** ) ( pNode + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) );

	printf ( "Digite um nome: " );
	scanf ( "%s", cName );

	printf ( "Agora, digite uma idade: " );
	scanf ( "%d", iAge );

	printf ( "Por último, digite um número de telefone: " );
	scanf ( "%d", iTel );

	while ( ( *Tracer ) && strcmp ( *Tracer, ( char* ) pNode ) < 1 ) {
		pOldNode = *Tracer;
		Tracer = ( ( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) );
		*iTracerIndex = *iTracerIndex + 1;
	}

	if ( *( int* ) ( pBuffer + sizeof ( int ) ) == 0 || *iTracerIndex == 0 ) {
		*pNodeNext = *Tracer;
		*pNodePrev = NULL;
		if ( *Tracer != NULL ) {
			*( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) = pNode;
		}
		*Tracer = pNode;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;

		return;
	}

	if ( *Tracer == NULL ) {
		*pNodeNext = NULL;
		*pNodePrev = pOldNode;
		*Tracer = pNode;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;

		return;
	}
	
	else {
		*pNodeNext = *Tracer;
		*Tracer = pNode;
		*pNodePrev = pOldNode;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;

	}
}

void Delete ( void **Head, void *pBuffer ) {
	void **Tracer = Head;
	void *pOldNode1, *pOldNode2;
	char *cName;

	cName = ( char* ) ( pBuffer + ( sizeof ( int ) * 2 ) );

	if ( *( int* ) ( pBuffer + sizeof ( int ) ) == 0 ) {
		printf ( "Erro! Lista vazia!" );
		
		return;
	}

	printf ( "Digite o nome a ser deletado: " );
	scanf ( "%s", cName );

	while ( ( *Tracer ) && !( strcmp ( cName, *Tracer ) == 0 ) ) {
		pOldNode1 = *Tracer;
		pOldNode2 = pOldNode1;
		Tracer = ( ( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) );

	}

	if ( strcmp ( cName, *Tracer ) == 0 && *( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) == NULL ) {
		pOldNode1 = *Tracer;
		*Tracer = ( *( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) );
		free ( pOldNode1 );
		*( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) = NULL;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

		return;
	}

	if ( strcmp ( cName, *Tracer ) == 0 && *( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) == NULL ) {
		pOldNode1 = *Tracer;
		*Tracer = pOldNode2;
		free ( pOldNode1 );
		*( void** ) ( pOldNode2 + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) = NULL;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

		return;
	}

	else {
		pOldNode1 = *Tracer;
		*Tracer = ( *( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) );
		free ( pOldNode1 );
		*( void** ) ( pOldNode2 + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) = *Tracer;
		*( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) = pOldNode2;
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

		return;
	}
}

void Display ( void **Head, void *pBuffer ) {
	void **Tracer = Head;

	if ( *( int* ) ( pBuffer + sizeof ( int ) ) == 0 ) {
		printf ( "Erro! Lista vazia!" );
		
		return;
	}

	for ( *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) = 0; *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) < *( int* ) ( pBuffer + sizeof ( int ) ); *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) = *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) + 1 ){
		printf ( "\n------------------------------" );
		printf ( "\nNome: %s ", ( char* ) *Tracer );
		printf ( "\nIdade: %d", *( int* ) ( *Tracer + sizeof ( char ) * 10 ) );
		printf ( "\nTelefone : %d ", *( int* ) ( *Tracer + ( sizeof ( char ) * 10 ) + sizeof ( int ) ) ); 
		Tracer = ( ( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) ) );
	}

	printf ( "\n------------------------------\n" );

	return;
}

void Clear ( void **Head, void *pBuffer ) {
	void **Tracer = Head;
	void *pOldNode;

	while ( *Tracer != NULL ) {
		pOldNode = *Tracer;
		*Tracer = *( void** ) ( *Tracer + ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void** ) ) );
		free ( pOldNode );

	}

	free ( pBuffer );
}

int main () {
	int *iChoice, *iNodeQty;
    void *pBuffer, *Head = NULL;


    pBuffer = malloc ( ( sizeof ( int ) * 3 ) + ( sizeof ( char ) * 10 ) );

    iChoice = ( int* ) pBuffer;
	iNodeQty = ( int* ) ( pBuffer + sizeof ( int ) );
	*iNodeQty = 0;

    while ( 1 ) {
        printf ( "\n------- Agenda: Menu -------" );
        printf ( "\nSelecione uma alternativa: " );
        printf ( "\n1 - Adicionar um nome. " );
        printf ( "\n2 - Excluir um nome. " );
        printf ( "\n3 - Mostrar a lista. " );
        printf ( "\n4 - Sair do programa. " );
        printf ( "\n----------------------------" );
        printf ( "\nSua escolha: " );
		scanf ( "%d", iChoice );

        switch ( *iChoice ) {
            case 1:
            	Add ( &Head, pBuffer );
                break;
            case 2:
                Delete ( &Head, pBuffer );
                break;
            case 3:
                Display ( &Head, pBuffer );
                break;
            case 4:
				Clear ( &Head, pBuffer );
                exit ( 0 );

        }

    } 
}