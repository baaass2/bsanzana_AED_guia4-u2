#include <iostream>
#include <fstream>

using namespace std;

/* Archivo .h con todas las cabeceras */
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

class Grafo {
    private:
        Nodo *arbol = NULL;

    public:
        /* constructor*/
        Grafo(Nodo *arbol);
        
        /* Métodos de la clase Grafo */
        void crearGrafo();
        void recorrerArbol (Nodo *, ofstream &);
        
};
