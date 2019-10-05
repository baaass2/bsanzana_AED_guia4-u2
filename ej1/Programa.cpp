#include <iostream>
#include "Grafo.h"
using namespace std;

Nodo *crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevoNodo = crearNodo(n);
		arbol = nuevoNodo;
	}else{
		int valorRaiz = arbol->dato;
		
		if(n < valorRaiz){
			insertarNodo(arbol->izq, n);
		}
		else if(n > valorRaiz){
			insertarNodo(arbol->der, n);		
		}else{
			cout<< "ERROR: DATO REPETIDO" <<endl;
		}
			
	}
}
void generarGrafo(Nodo *arbol){
	
	Grafo *grap = new Grafo(arbol);
	grap->crearGrafo();
}

void imprimirPreorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		cout<< arbol->dato << "-";
		imprimirPreorden(arbol->izq);
		imprimirPreorden(arbol->der);
	}
}
void imprimirInorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirInorden(arbol->izq);
		cout<< arbol->dato << "-";
		imprimirInorden(arbol->der);
	}
}
void imprimirPosrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirPosrden(arbol->izq);
		imprimirPosrden(arbol->der);
		cout<< arbol->dato << "-";
	}
}

void eliminarNodo(Nodo *q){
	
}

Nodo *busqueda(Nodo *arbol, int n){
	Nodo *q = NULL;
	
	if(arbol == NULL){
		cout<< "No se ha encontrado nodo." <<endl;
	}
	else if(n < arbol->dato){
		eliminar(arbol->izq, n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->der, n);
	}else{
		q=arbol;
	}
	
	return q;
}

void menu(Nodo *&arbol){
	
	int opc = 0;
	int dato = 0;
	int datoNuevo = 0;
	
	cout<< "MENU" <<endl;
	do{
		cout<< "" <<endl;
		cout<< "[1] Insertar nodo." <<endl;
		cout<< "[2] Eliminar nodo." <<endl;
		cout<< "[3] Modificar nodo." <<endl;
		cout<< "[4] Imprimir Preorden, Inorden y Posorden." <<endl;
		cout<< "[5] Generar Grafo." <<endl;
		cout<< "[6] Salir.        " <<endl;
		cout<< "Eliga una opción: "; 
		cin >> opc;
		
		switch(opc){
			case 1: cout<< "Digite un numero: "; 
					cin >> dato;
					insertarNodo(arbol,dato);
					break;
			case 2: cout<< "Digite nodo a buscar: "; 
					cin >> dato;
					q=busqueda(arbol, dato);
					eliminarNodo(q);
					break;
					
			case 3: cout<< "Digite nodo a modificar: "; 
					cin >> dato;
					cout<< ""<<endl;
					cout<< "Digite valor del nodo nuevo: "; 
					cin >> datoNuevo;
					break;
			
			case 4: cout<< "PREORDEN"<<endl;
					imprimirPreorden(arbol);
					cout<< "" <<endl;
					cout<< "INORDEN"<<endl;
					imprimirInorden(arbol);
					cout<< "" <<endl;
					cout<< "POSORDEN"<<endl;
					imprimirPosrden(arbol);
					break;
			
			case 5: generarGrafo(arbol);
					break;
					
					
		}
	}while(opc != 6);
}

void menu(Nodo *&);
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void generarGrafo(Nodo *);
void imprimirPreorden(Nodo *);
void imprimirInorden(Nodo *);
void imprimirPosorden(Nodo *);
Nodo *busqueda(Nodo *, int);
void eliminarNodo(Nodo *);

Nodo *arbol = NULL;


int main (void) {
	
	int cont = 0;
	
	menu(arbol);
	
    return 0;
}
