#include "indice.h"
#include <iostream>

using namespace std;

Indice::Indice(): referencias()
{

}

Termino Indice::buscarTermino(Termino t, const ABB<Termino> &a){
    return (buscarTermino(t, a.getRaiz()));
}


Termino Indice::buscarTermino(Termino t, typename ABB<Termino>::Iterador& it){
        if (!it.arbolVacio() && it.observar()!=t){
            if(it.observar()<t) buscarTermino(t, referencias.subDer(it));
            else buscarTermino(t, referencias.subIzq(it));
        }
        return it.observar();
}

void Indice::insertarReferencia(string p, int numPag)
{
    Lista<int> npag;
    npag.anadirDch(numPag);
    Termino t(p, &npag);
    if (!referencias.buscar(t)) referencias.insertar(t);
    else{
        Termino ter=buscarTermino(t, buscarTermino(referencias));
        npag.anadirDch(ter.getPaginas());
        t.setPaginas(npag);
        referencias.elimina(ter);
        referencias.insertar(t);
    }
}

stack<Termino> Indice::recorrerABB(const ABB<Termino> &a){
    return(recorrerABB(a, a.getRaiz(), 0));
}

stack<Termino> Indice::recorrerABB(const ABB<Termino> &a, typename ABB<Termino>::Iterador& it, int alt){
    int altura=a.altura();
    stack<Termino> pila_terminos;
    if(!it.arbolVacio() || alt<=altura){
        recorrerABB(a, a.subIzq());
        pila_terminos.push(it.observar());
        recorrerABB(a, a.subDer());
        alt++;
    }
    return pila_terminos;
}


void Indice::generarRefsCruzadas()
{
    Termino ter;
    Lista<int> lista_paginas;
    stack<Termino> pila=recorrerABB(referencias);
    while(!pila.empty()){
       ter=pila.top();
       cout<<ter.getPalabra()<<": \n";
       lista_paginas=ter.getPaginas();

       int longitud=lista_paginas.longitud();
       for(int pos=0; pos<longitud; pos++){
            typename Lista<int>::Iterador it=lista_paginas.ponerIterador(pos);
            int pag=it.observar(lista_paginas);
            lista_paginas.eliminar(pos);
            if(lista_paginas.pertenece(pag)) lista_paginas.eliminar(it);
            cout<<pag<<", ";
       }
       pila.pop();
    }
}



