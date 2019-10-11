#include <iostream>
#include "Grafo.h"
#include "Arbol.h"

Arbol::Arbol(){
}

Nodo* Arbol::crearNodo(int n){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato = n;
	nuevoNodo->der = NULL;
	nuevoNodo->izq = NULL;
	
	return nuevoNodo;
}

void Arbol::insertarNodo(Nodo *&arbol, int n){
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
void Arbol::generarGrafo(Nodo *arbol){
	
	Grafo *grap = new Grafo(arbol);
}

void Arbol::imprimirPreorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		cout<< arbol->dato << "-";
		imprimirPreorden(arbol->izq);
		imprimirPreorden(arbol->der);
	}
}
void Arbol::imprimirInorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirInorden(arbol->izq);
		cout<< arbol->dato << "-";
		imprimirInorden(arbol->der);
	}
}
void Arbol::imprimirPosorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		imprimirPosorden(arbol->izq);
		imprimirPosorden(arbol->der);
		cout<< arbol->dato << "-";
	}
}
Nodo* Arbol::buscarMinimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq != NULL){
		return buscarMinimo(arbol->izq);
	}else{
		return arbol;
	}
}
void Arbol::eliminarNodo(Nodo *&nEliminar, int n){
	
	Nodo* nOtro = NULL;
	Nodo* nAux = NULL;
	Nodo* nAux1 = NULL;
	bool bo = false;
	
	if(nEliminar != NULL){
		if(n < nEliminar->dato){
			eliminarNodo(nEliminar->izq, n);
		}
		else if(n > nEliminar->dato){
			eliminarNodo(nEliminar->der, n);
		}else{
			nOtro = nEliminar;
			if(nOtro->der == NULL){
				nEliminar = nOtro->izq;
			}
			else if(nOtro->izq == NULL){
				nEliminar = nOtro->der;
			}
			else{
				nAux = nEliminar->izq;
				bo = false;
				while(nAux->der != NULL){
					nAux1 = nAux;
					nAux = nAux->der;
					bo = true;
				}
				nEliminar->dato = nAux->dato;
				nOtro = nAux;
				if(bo == true){
					nAux1->der == nAux->izq;
				}
				else{
					nEliminar->izq = nAux->izq;
				}
				delete nOtro;
			}
		}
	}
	else{
		cout<< "No se ha encontrado nodo." <<endl;
	}
}

Nodo* Arbol::busqueda(Nodo *nEliminar, int n){
	
	if(nEliminar == NULL){
		cout<< "No se ha encontrado nodo." <<endl;
	}
	else if(n < nEliminar->dato){	
		busqueda(nEliminar->izq, n);
	}
	else if(n > nEliminar->dato){
		busqueda(nEliminar->der, n);
	}else{
		return nEliminar;
	}
}

//~ Nodo* Arbol::getArbol(){
	//~ return this->raiz;
//~ }

//~ void Arbol::setArbol(Nodo *arbol){
	//~ this->arbol = raiz;
//~ }
		
