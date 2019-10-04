#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

insertarNodo(Nodo q, int n){
	if(q == NULL){
		Nodo *nuevoNodo = crearNodo(n);
		q = nuevoNodo;
	}else{
		int valorRaiz = q->dato;
		
		if(n < valorRaiz){
			insertarNodo(q->izq, n);
		}else{
			insertarNodo(q->der, n);		
		}
	}
}
void mostrarArbol(Nodo *q, int cont){
	if(q == NULL){
		return;
	}else{
		mostrarArbol(q->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"  ";
		}
		cout<< q->dato <<endl;
		mostrarArbol(q->izq, cont+1);
	}
}
int main (void) {
	int cont = 0;
	Nodo *arbol = NULL;
	arbol = crearNodo(20);	
	insertarNodo(arbol, 10);
	insertarNodo(arbol, 99);
	mostrarArbol(arbol, cont);
	
    return 0;
}
