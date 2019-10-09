#include <fstream>
#include <iostream>
using namespace std;
#include "Grafo.h"
#include <unistd.h>

Grafo::Grafo (Nodo *nodo) {
	pid_t pid, pid2;
	pid = fork();
	ofstream fp;
	
	if (pid == 0) { 
		fp.open ("grafo.txt");                
		fp << "digraph G {" << endl;
		fp << "node [style=filled fillcolor=yellow];" << endl;
		
		recorrerArbol(nodo, fp);

		fp << "}" << endl;

		fp.close();

		system("dot -Tpng -ografo.png grafo.txt &");
			
		pid2 = fork();
		if (pid2 == 0) { 
			system("eog grafo.png &");
		}
	}
}

void Grafo::recorrerArbol(Nodo *p, ofstream &fp) {
	string cadena = "\0";
	  
	if (p != NULL) {
		if (p->izq != NULL) {
			fp <<  p->dato << "->" << p->izq->dato << ";" << endl;
		} else {      
			cadena = to_string(p->dato) + "i";
			fp <<"\"" << cadena << "\"" <<"[shape=point];" << endl;
			fp << p->dato << "->" <<"\"" << cadena << "\"" << ";" << endl;
		}
			
		if (p->der != NULL) { 
			fp << p->dato << "->" << p->der->dato << ";" << endl;
		} else {
			cadena = to_string(p->dato) + "d";
			fp <<"\"" << cadena << "\"" << "[shape=point];" << endl;
			fp << p->dato << "->" <<"\"" << cadena << "\"" << ";" << endl;
		}

		recorrerArbol(p->izq, fp);
		recorrerArbol(p->der, fp); 
	}
}

