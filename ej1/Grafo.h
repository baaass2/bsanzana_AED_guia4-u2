#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

class Grafo {
	public:
		Grafo(Nodo *nodo);
		void recorrerArbol (Nodo *, ofstream &);
        
};
