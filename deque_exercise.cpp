#include <iostream>

using namespace std;

struct deque
{
	int comeco;		  // garda a posicao do comeco
    int topo;         // guarda a posicao do topo
    int capacidade;   // guarda a capacidade da pilha
    float *elementos; // vetor que armazena os valores
};

void init(deque *d, int c)
{ 
	d -> comeco = -1;
    d -> topo = -1;                // indica que a pilha está vazia
    d -> capacidade = c;           // define a capacidade da pilha
    d -> elementos = new float[c]; // aloca memória para a capacidade fornecida
}

bool isEmpty(deque *d)
{
    if ( d -> comeco == -1 && d -> topo == -1 )
        return true;
    else
        return false;
}

bool isFull(deque *d)
{
    if (d -> topo == d -> capacidade - 1)
        return true;
    else
        return false;
}

void insertRear(deque *d, float v)
{
	if(d -> comeco == -1){
		
		d -> comeco = 0;
		d -> topo = 0;
	}	
	
	else if( d -> topo == d -> capacidade - 1){
		d -> topo = 0;
	}
	
	else{
		d -> topo = d -> topo + 1;
	}
	
	d -> elementos[ d -> topo ] = v;
	  
}

void insertFront(deque *d, float v){
	
	if( d -> comeco == -1){
		d -> comeco = 0;
		d -> topo = 0;
	}
	
	else if(d -> comeco == 0){
		d -> comeco = d -> capacidade - 1;
	}
	
	else{
		d -> comeco = d -> comeco - 1;
	}
	
	d -> elementos[ d -> comeco ] = v;	
}

void deleteFront(deque* d)
{
    if(d -> comeco == d -> topo){
		
		d -> comeco = -1;
		d -> topo = -1;
	}
	
	else{
		
		if(d -> comeco == d -> capacidade - 1){
			d -> comeco = 0;
		}
	
		else{
			d -> comeco = d -> comeco + 1;	
		}
	}
	
}

void deleteRear(deque* d)
{
    if(d -> comeco == d -> topo){
		d -> comeco = -1;
		d -> topo = -1;
	}
	
	else if(d -> topo == 0){
		d -> topo = d -> capacidade - 1;
	}
	
	else{
		d -> topo = d -> topo - 1;
	}
}

float getRear(deque* d)
{
    return d -> elementos[ d-> topo ];
}

float getFront(deque* d)
{
    return d -> elementos[ d -> comeco ];
}

int main()
{
	int op;
	float value;
	float rem;
    deque d;                     // declaração da pilha
    
	init(&d, 5);                 // inicialização da pilha
    
    
    do{
    	cout << "---- 1 => inserir no comeco ----" << endl;
    	cout << "---- 2 => inserir no final ----" << endl;
    	cout << "---- 3 => remover no comeco ----" << endl;
    	cout << "---- 4 => remover no final ----" << endl;
    
    	
    	cout << "Op => ";
    	cin >> op;
    	cout << endl; 
    	
    	
	    switch(op){
			case 1:
				
				if(!isFull(&d)){
					
					cout << "valor => ";
	    			cin >> value;
	    			cout << endl << endl;
	    			
					insertFront(&d, value);
					cout << getFront(&d) << endl;     // imprime o valor do elemento no inicio do deque	
				}
				else{
					cout << "Falha ao Inserir, deque cheio!" << endl;	   	
				}
				
				break;
			
			case 2:
				
				if(!isFull(&d)){
					
					cout << "valor => ";
	    			cin >> value;
	    			cout << endl << endl;
	    			
					insertRear(&d, value);	
					cout << getRear(&d) << endl;     // imprime o valor do elemento no topo do deque
				}
				else{
					cout << "Falha ao Inserir, deque cheio!" << endl;	   	
				}
				
				break;
			
			case 3:
				
				if(!isEmpty(&d)){
					deleteFront(&d);	
				}
				else{
					cout << "Falha ao Deletar, deque vazio!" << endl;	   	
				}
				break;
			
			case 4: 
				
				if(!isEmpty(&d)){
					
					deleteRear(&d);
				}
				else{
					cout << "Falha ao Deletar, deque vazio!" << endl;	   	
				}
				
				break;
			
			default:
				cout << "Opcao Invalida!" << endl;
		}
		
	}while(op != 0);
    
	return 0;
}