#include<iostream>

#include"listas_circulares.h"



// Insere um no no inicio de uma lista circular

void pushc (noptr &lista, int x)

{

	noptr p;

	p = new no;

	p->info = x;

	if (lista == NULL) // e o primeiro no

		lista = p;

	else

		p->next = lista->next; // ja existem outros nos

	lista->next = p;

}



// Remove um no do inicio de uma lista circular

int popc (noptr &lista, int &x)

{

	noptr p;

	if (lista == NULL) // a lista ja esta vazia

		return -1;

	else // removendo no ininicial

	{

		p = lista->next;

		x = p->info;

		if (p == lista) // somente um no na lista

			lista = NULL;

		else // ja existem outros nos na lista

			lista->next = p->next;

		delete p;

		return 0;

	}

}



// Insere um no no final de uma lista circular

void inserec(noptr &lista, int x)

{

	pushc(lista, x);

	lista = lista->next;

}



//remove todos os nos iguais a x

void removetudo(noptr &lista, int x)

{

	noptr p = NULL;



	if(lista->info == x)

		popc(lista, x);



	for(p = lista->next; p != lista; p = p->next)

	{

		if(p->info == x)

		{

			lista->next = p->next;

			delete p;



		}

	}



	if(lista->info == x)
		delete lista;

}
