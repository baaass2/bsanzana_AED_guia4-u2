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
	nuevoNodo->der = NULm
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

void insertarNodo(Nodo *arbol, int n){
	if(arbol == NULL){
		Nodo nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
	}else{
		int valorRaiz = arbol->dato;
		
		if(n < valorRaiz){
			insertarNodo(arbol->izq, n);
		}else{
			insertarNodo(arbol->der, n);		
		}
	}
}

void mostrarArbol(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->
	



int main (void) {
	Nodo *arbol = NULL;
	insertarNodo(arbol, 0);
    return 0;
}
