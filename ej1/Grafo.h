#include <iostream>
#include <fstream>
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
