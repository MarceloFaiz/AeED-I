/*
Agenda

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
	char *cName;
	int *Age, *Tel;
	void **PrevNode, **NextNode, *Node;
	
	Node = ( void* ) malloc ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) * 2 ) ); 

	cName = ( char* ) Node;
	Age = ( int* ) ( Node + ( sizeof ( char ) * 10 ) );
	Tel = ( int* ) ( Node + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) ) ) ); 
	PrevNode = ( void** ) ( Node + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
	NextNode = ( void** ) ( Node + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

	printf ( "Digite um nome: " );
	scanf ( "%s", ( char* ) cName );

	printf ( "Agora, digite uma idade: " );
	scanf ( "%d", ( int* ) Age );
	getchar ();

	printf ( "Por último, digite um número de telefone: " );
	scanf ( "%d", ( int* ) Tel );
	getchar ();

	PrevNode = NULL;
	NextNode = NULL;

	return Node;	
}

void Add ( void **Head, void *pBuffer ) {
	void *pNode, *pNode_old;
	int *TracerIndex;
	char *cName;
	void **PrevNode_new, **NextNode_new, **PrevNode_old, **NextNode_old;
	void **Tracer = Head;

	TracerIndex = ( int* ) ( pBuffer + ( sizeof ( int ) * 2 ) );

	*TracerIndex = 0;

	pNode_old = *Tracer;
	PrevNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
	NextNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

	pNode = NodeInit ();  

	cName = ( char* ) pNode;
	PrevNode_new = ( void** ) ( pNode + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
	NextNode_new = ( void** ) ( pNode + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

	while ( ( *Tracer ) && strcmp ( *Tracer, cName ) < 1 ) {
		pNode_old = *Tracer;
		PrevNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
		NextNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

		Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
		*( int* ) ( pBuffer + ( sizeof ( int ) * 2 ) ) = *( int* ) ( pBuffer + ( sizeof ( int ) * 2 ) ) + 1;
	}

	if ( *( int* ) ( pBuffer + sizeof ( int ) ) == 0 || *( int* ) ( pBuffer + ( sizeof ( int ) * 2 ) ) == 0 ) {
		*NextNode_new = *Tracer;
		*PrevNode_new = NULL;
		*Tracer = pNode;

		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;
	
		return;
	} 

	if ( *Tracer == NULL ) {
		*NextNode_new = NULL;
		*Tracer = pNode;
		*PrevNode_new = pNode_old;

		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;

		return;
	}

	else {
		*NextNode_new = *NextNode_old;
		*NextNode_old = pNode;
		*PrevNode_new = pNode_old;

		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) + 1;

		return;
	}
}

void Delete ( void **Head, void *pBuffer ) {
	void **Tracer = Head;
	void *pNode_old = NULL, *pNode_del = NULL;
	char *cName_del;
	void **NextNode_old = NULL, **PrevNode_Tracer = NULL, **NextNode_Tracer = NULL;

	pNode_del = *Tracer;
	pNode_old = pNode_del;

	cName_del = ( char* ) ( pBuffer + ( sizeof ( int ) * 4 ) );

	printf ( "Digite o nome da pessoa que você deseja deletar da lista: " );
	scanf ( "%s", ( char* ) ( pBuffer + ( sizeof ( int ) * 4 ) ) );

	if ( ( int* ) ( pBuffer + sizeof ( int ) ) == 0 ) {
		printf ( "Erro! A agenda está vazia!" );
		
		return;
	}

	if ( strcmp ( *Tracer, cName_del ) == 0 ) {
		Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

		*Head = *Tracer;
		free ( pNode_del );
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

		return;
	}

	while ( ( *Tracer ) && strcmp ( *Tracer, cName_del ) < 1 ) {
		pNode_del = *Tracer;
		pNode_old = pNode_del;

		Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
		NextNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

		if ( *NextNode_Tracer == NULL ) {
			pNode_del = *Tracer;
			*Tracer = pNode_old;
			free ( pNode_del );

			NextNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
			NextNode_old = NULL;
			NextNode_Tracer = NULL;

			*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

			return;
		}

		if ( strcmp ( *Tracer, cName_del ) == 0 ) {
			pNode_del = *Tracer;
			Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

			
			NextNode_old = ( void** ) ( pNode_old + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );

			PrevNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
		

			*NextNode_old = *Tracer;
			*PrevNode_Tracer = pNode_old;

			free ( pNode_del );

			*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;

			return;
		}
	}
}

void Display ( void **Head, void *pBuffer ) {
	void **Tracer = Head;

	if ( *( int* ) ( pBuffer + sizeof ( int ) ) == 0 ) {
		printf ( "Erro! Lista vazia!" );
		
		return;
	}

	for ( *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) = 0; *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) < *( int* ) ( pBuffer + sizeof ( int ) ); *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) = *( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) ) + 1 ){
		printf ( "------------------------------" );
		printf ( "\nNome: %s ", ( char* ) *Tracer );
		printf ( "\nIdade: %d", *( int* ) ( *Tracer + sizeof ( char ) * 10 ) );
		printf ( "\nTelefone : %d ", *( int* ) ( *Tracer + ( sizeof ( char ) * 10 ) + sizeof ( int ) ) );
		printf ( "\n------------------------------" ); 
		Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
	}

	return;
}

/*void Clear ( void **Head, void *pBuffer ) {
	void **Tracer = Head, **NextNode_Tracer = NULL, **PrevNode_Tracer = NULL, *pNode_del;

	NextNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
	PrevNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );

	while ( *( int* ) ( pBuffer + sizeof ( int ) ) != 0 ) {
		PrevNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
		
		
		while ( *NextNode_Tracer != NULL ) {
			Tracer = ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
			NextNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
			PrevNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) ) );
		}

		pNode_del = *Tracer;
		*Tracer = *PrevNode_Tracer;
		*NextNode_Tracer = *Tracer;
		free ( pNode_del );
		*( int* ) ( pBuffer + sizeof ( int ) ) = *( int* ) ( pBuffer + sizeof ( int ) ) - 1;
	}

	return;
}*/

void Clear (void **Head, void *pBuffer ) {
	void *pNode_del;
	void **Tracer;
	void **NextNode_Tracer;

	while ( *Head != NULL ) {
		pNode_del = *Head;
		Tracer = Head;
		NextNode_Tracer = ( void** ) ( *Tracer + ( ( sizeof ( char ) * 10 ) + ( sizeof ( int ) * 2 ) + ( sizeof ( void* ) ) ) );
		Head = NextNode_Tracer;
		free ( pNode_del );	
	}
	return;
}

int main () {
	int *iChoice, *NodeQty, *Index;
    void *pBuffer, *Head = NULL;

    pBuffer = malloc ( ( sizeof ( int ) * 4 ) + ( sizeof ( char ) * 10 ) );

    iChoice = ( int* ) pBuffer;
	NodeQty = ( int* ) ( pBuffer + sizeof ( int ) );
	*NodeQty = 0;
	Index = ( int* ) ( pBuffer + ( sizeof ( int ) * 3 ) );

    while ( 1 ) {
        printf ( "\n------- Agenda: Menu -------\n" );
        printf ( "Selecione uma alternativa: \n" );
        printf ( "1 - Adicionar um nome. \n" );
        printf ( "2 - Excluir um nome. \n" );
        printf ( "3 - Mostrar a lista. \n" );
        printf ( "4 - Sair do programa. \n" );
        printf ( "----------------------------\n" );
        printf ( "Sua escolha: " );
		scanf ( "%d", ( int* ) pBuffer );

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
				free ( pBuffer );
                exit ( 0 );
        }
    } 

    return 0;
}