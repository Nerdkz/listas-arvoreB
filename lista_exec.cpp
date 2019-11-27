#include <iostream>


using namespace std;


//struct do nó
struct no
{
	int info;

	no *next;

};
typedef no* noptr;


//insere um nó no início da lista
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



//removendo um elemento do inicio da lista
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


//remove todos os nos iguais a x

void removetudo(noptr &lista, int x)
{

	noptr p = NULL;
	noptr anterior = NULL;
	
	cout << "x = " << x << endl;
	
	for(p = lista->next; p != lista; )
	{
		noptr no = NULL;
				 			  		
		if(p->info == x){
			cout << "Entrei aqui " << endl;
			anterior->next = p->next;
			no = p;
			p = p->next;
			delete no;
		}
		else{
			anterior = p;
			p = p->next;	
		}		
	}

}



int main()
{

	int x, y;

	noptr lista = NULL;

	noptr p = NULL;



	//colocando numeros na lista

	cin >> x;

	while(x != 0){
		pushc(lista, x);

		cin >> x;
	}

	for(p = lista->next; p != lista; p = p->next){
		cout << p->info << " ";
	}
	cout << p->info << endl;
	
	//removendo da lista todos os x;
	cout << "elemento a ser removido: ";
	cin >> y;
	
	removetudo(lista, y);
 	
	for(p = lista->next; p != lista; p = p->next){
		cout << p->info << " ";
	}
	cout << p->info << endl;


	//limpando memoria

	while(lista != NULL)
		popc(lista, x);


	return 0;
}
