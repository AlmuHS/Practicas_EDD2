#ifndef _INDICE_H_
#define _INDICE_H_

#include <string>
#include <stack>
#include <vector>
#include "termino.h"
#include "abb.h"

class Indice {
	public:
    	Indice();
        void insertarReferencia(string p, int numPag);
        // si la palabra ya existe, a�ade la nueva referencia a la p�gina
        // en caso contrario, a�ade tanto la palabra como la p�gina en la que aparece
        void generarRefsCruzadas();
        // muestra en pantalla una secuencia ordenada de palabras, y para cada una de ellas,
        // una secuencia ordenada de n�meros de p�gina.
        // Si una palabra aparece varias veces en la misma p�gina,
        // s�lo se mostrar� una vez ese n�mero de p�gina
        Termino buscarTermino(Termino t, const ABB<Termino> &a);
        Termino buscarTermino(Termino t, typename ABB<Termino>::Iterador& it);
        void recorrerABB(const ABB<Termino> &a);
        void recorrerABB(const ABB<Termino> &a, typename ABB<Termino>::Iterador& it);
	private:
		ABB<Termino> referencias;

};

#endif







