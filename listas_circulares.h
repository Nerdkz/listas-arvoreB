#ifndef LISTAS_CIRCULARES_H_INCLUDED

#define LISTAS_CIRCULARES_H_INCLUDED



// Struct para cada no

struct no

{
	int info;

	no *next;

};

typedef no* noptr;



// Insere um no no inicio de uma lista circular

void pushc (noptr &lista, int x);



// Remove um no do inicio de uma lista circular

int popc (noptr &lista, int &x);



// Insere um no no final de uma lista circular

void inserec(noptr &lista, int x);



//remove todos os nos iguais a x

void removetudo(noptr &lista, int x);



#endif // LISTAS_CIRCULARES_H_INCL
