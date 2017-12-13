#ifndef _INDICE_H_
#define _INDICE_H_

#include <string>
#include "termino.h"
#include "abb.h"

class Indice {
	public:
    	Indice();
        void insertarReferencia(string p, int numPag);
        // si la palabra ya existe, añade la nueva referencia a la página 
        // en caso contrario, añade tanto la palabra como la página en la que aparece
        void generarRefsCruzadas();
        // muestra en pantalla una secuencia ordenada de palabras, y para cada una de ellas, 
        // una secuencia ordenada de números de página. 
        // Si una palabra aparece varias veces en la misma página, 
        // sólo se mostrará una vez ese número de página
	private:
		ABB<Termino> referencias;
};

#endif







