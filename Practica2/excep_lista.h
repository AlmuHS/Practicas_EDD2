#ifndef _EXCEP_LISTA_H_
#define _EXCEP_LISTA_H_

#include "excepcion.h"

class ListaVaciaExcepcion: public Excepcion
{
	public:
    	ListaVaciaExcepcion(): Excepcion("La lista esta vacia") {};
};

class PosicionErroneaExcepcion: public Excepcion
{
	public:
    	PosicionErroneaExcepcion(): Excepcion("Posicion erronea") {};
};

class ObjetoInexistenteExcepcion: public Excepcion
{
	public:
    	ObjetoInexistenteExcepcion(): Excepcion("Objeto inexistente") {};
};

class IndiceErroneoExcepcion: public Excepcion
{
	public:
    	IndiceErroneoExcepcion(): Excepcion("Indice erroneo") {};
};

#endif

