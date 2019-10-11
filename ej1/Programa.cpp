#include <iostream>
#include "Grafo.h"
#include "Arbol.h"
using namespace std;

void menu(Arbol a){
	
	int opc = 0;
	int dato = 0;
	int datoNuevo = 0;
	Nodo *arbol = NULL;
	
	cout<< "MENU" <<endl;
	do{
		cout<< "" <<endl;
		cout<< "[1] Insertar nodo." <<endl;
		cout<< "[2] Eliminar nodo." <<endl;
		cout<< "[3] Modificar nodo NO ." <<endl;
		cout<< "[4] Imprimir Preorden, Inorden y Posorden." <<endl;
		cout<< "[5] Generar Grafo." <<endl;
		cout<< "[6] Salir.        " <<endl;
		cout<< "Eliga una opción: "; 
		cin >> opc;
		
		switch(opc){
			case 1: cout<< "Digite un numero: "; 
					cin >> dato;
					a.insertarNodo(arbol,dato);
					break;
					
			case 2: cout<< "Digite nodo a eliminar: "; 
					cin >> dato;
					a.eliminarNodo(arbol, dato);
					break;
					
			case 3: cout<< "Digite nodo a modificar: "; 
					cin >> dato;
					cout<< ""<<endl;
					a.eliminarNodo(arbol, dato)
					cout<< "Digite valor del nodo nuevo: "; 
					cin >> datoNuevo;
					a.insertarNodo(arbol, datoNuevo);
					break;
			
			case 4: cout<< "PREORDEN"<<endl;
					a.imprimirPreorden(arbol);
					cout<< "" <<endl;
					cout<< "INORDEN"<<endl;
					a.imprimirInorden(arbol);
					cout<< "" <<endl;
					cout<< "POSORDEN"<<endl;
					a.imprimirPosorden(arbol);
					break;
			
			case 5: a.generarGrafo(arbol);
					break;
					
					
		}
	}while(opc != 6);
}

int main (void) {
	Arbol a = Arbol();
	menu(a);
	
    return 0;
}
