/*Copyright 2015 Almudena Garcia Jurado-Centurion

This file is part of Practica2_EDD2.

Practica3_EDD2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica3_EDD2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica2_EDD2.  If not, see <http://www.gnu.org/licenses/>.*/

#include <iostream>
#include <cstdlib>
#include <queue>
#include "arbin.h"
#include "abb.h"
#include "indice.h"

// Recorridos

template <typename T>
void inorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        inorden(a, a.subIzq(r));
        cout << r.observar() << " ";
        inorden(a, a.subDer(r));
    }
}

template <typename T>
void preorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        cout << r.observar() << " ";
        preorden(a, a.subIzq(r));
        preorden(a, a.subDer(r));
    }
}

template <typename T>
void postorden(const Arbin<T>& a, const typename Arbin<T>::Iterador& r) {
    if (!r.arbolVacio()) {
        postorden(a, a.subIzq(r));
        postorden(a, a.subDer(r));
        cout << r.observar() << " ";
    }
}

template <typename T>
void anchura(const Arbin<T>& a) {
    if (!a.esVacio()) {
        queue<typename Arbin<T>::Iterador> c;
        typename Arbin<T>::Iterador ic = a.getRaiz();
        c.push(ic);
        while (!c.empty()) {
             ic = c.front();
             c.pop();
             cout << ic.observar() << " ";
             if (!a.subIzq(ic).arbolVacio())
                c.push(a.subIzq(ic));
             if (!a.subDer(ic).arbolVacio())
                c.push(a.subDer(ic));
        }
    }
}


/***************************************************************************/
/****************************** EJERCICIOS *********************************/
/***************************************************************************/
//Ejercicio 1


template <typename T>
int numHojas(const Arbin<T> &a){
	return numHojas(a, a.getRaiz());
}

template <typename T>
int numHojas(const Arbin<T> &a, const typename Arbin<T>::Iterador& r){
	if(r.arbolVacio()) return 0;
	else{
		if(a.subIzq(r).arbolVacio() &&	a.subDer(r).arbolVacio()) return 1;
		else return numHojas(a, a.subIzq(r)) + numHojas(a,a.subDer(r));
	}	
}



/****************************************************************************/
//Ejercicio 2

template <typename T>
Arbin<T> Simetrico(const Arbin<T> &a){
	return Simetrico(a, a.getRaiz());
}

template <typename T>
Arbin<T> Simetrico(const Arbin<T> &a, const typename Arbin<T>::Iterador& r){
	if(r.arbolVacio()) return Arbin<T> ();
	else return  Arbin<T>(r.observar(), Simetrico(a, a.subDer(r)), Simetrico(a, a.subIzq(r)));
}

/****************************************************************************/
//Ejercicio 3

template <typename T>
void recorridoZigzag(const Arbin<T> &a, char sentido){
	recorridoZigzag(a, a.getRaiz(), sentido);
}

template <typename T>
void recorridoZigzag(const Arbin<T> &a, const typename Arbin<T>::Iterador& r, char sentido){
	if(!r.arbolVacio()){
		cout<<r.observar();
		
		if(sentido == 'I'){	
			recorridoZigzag(a, a.subIzq(r), 'D');
		}
		else if(sentido == 'D')
			recorridoZigzag(a, a.subDer(r), 'I');
	}
}


/******************************************************************************/
//Ejercicio 4

template <typename T>
int numNodos(const Arbin<T> &a, const typename Arbin<T>::Iterador& r){
	if(r.arbolVacio()) return 0;
	else return 1 + numNodos(a, a.subIzq(r)) + numNodos(a, a.subDer(r));
}

template <typename T>
bool compensado(const Arbin<T> &a){
	return compensado(a, a.getRaiz());	
}

template <typename T>
bool compensado(const Arbin<T> &a, const typename Arbin<T>::Iterador& r){
	if(r.arbolVacio()) return true;
	else if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()) return true;
	else{
		if(abs(numNodos(a, a.subIzq(r)) - numNodos(a, a.subDer(r))) > 1) return false;
		else if(compensado(a, a.subIzq(r)) && compensado(a, a.subDer(r))) return true; 
	}
}

/*****************************************************************************/
//Ejercicio 5

template <typename T>
void palabras(const Arbin<T> &a){
	string pal = "";
	palabras(a, a.getRaiz(), pal);
}

template <typename T>
void palabras(const Arbin<T> &a, const typename Arbin<T>::Iterador& r, string palabra){
	if(!r.arbolVacio()){
		if(a.subIzq(r).arbolVacio() && a.subDer(r).arbolVacio()) cout<<palabra + r.observar()<<endl;
		else{
			palabras(a, a.subIzq(r), palabra + r.observar());
			palabras(a, a.subDer(r), palabra + r.observar());
		}
	}
}

/******************************************************************************/
//Ejercicio 6

template <typename T>
int posicionInorden(const ABB<T> &a, int num){
	return posicionInorden(a, a.getRaiz(), num);
}

template <typename T>
int numNodos(const ABB<T> &a, const typename ABB<T>::Iterador& r){
	if(r.arbolVacio()) return 0;
	else return 1 + numNodos(a, a.subIzq(r)) + numNodos(a, a.subDer(r));
}

template <typename T>
int posicionInorden(const ABB<T> &a, const typename ABB<T>::Iterador& r, int num){
	if(!r.arbolVacio()){
		if(num < r.observar()) return posicionInorden(a, a.subIzq(r), num);
		else if(num > r.observar()) return posicionInorden(a, a.subDer(r), num);	
		else if(num == r.observar()) return numNodos(a, a.subIzq(r)) + 1;
	}
	else return 0;
}

/****************************************************************************/
/****************************************************************************/
int main(int argc, char *argv[])
{
    Arbin<char> A('t', Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())),

                       Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()));

    Arbin<char> B('t', Arbin<char>('n', Arbin<char>(),
                                        Arbin<char>('d', Arbin<char>('e', Arbin<char>(), Arbin<char>()),
                                                         Arbin<char>())),
                       Arbin<char>('m', Arbin<char>('f', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('n', Arbin<char>(), Arbin<char>())));

    Arbin<char> D('t', Arbin<char>('k', Arbin<char>('d', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>()),
                       Arbin<char>('m', Arbin<char>(),
                                        Arbin<char>('f', Arbin<char>(), Arbin<char>())));

    Arbin<char> E('o', Arbin<char>('r', Arbin<char>(),
                                        Arbin<char>('o', Arbin<char>(), Arbin<char>())),
                       Arbin<char>('l', Arbin<char>('a', Arbin<char>(), Arbin<char>()),
                                        Arbin<char>('e', Arbin<char>(), Arbin<char>())));

    ABB<int> BB;



    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = Simetrico(B);
    cout << "Recorrido en inorden del arbol B: " << endl;
    inorden(B, B.getRaiz());
    cout << endl << "Recorrido en inorden del arbol C: " << endl;
    inorden(C, C.getRaiz());
    cout << endl << endl;


    // RECORRIDO EN ZIG-ZAG //
    cout << "Recorrido en zigzag I de B:\n";
    recorridoZigzag(B, 'I');
    cout << endl;
    cout << "Recorrido en zigzag D de C:\n";
    recorridoZigzag(C, 'D');
    cout << endl << endl;


    // COMPENSADO //
    cout << "Esta A compensado?:";
    cout << (compensado(A) ? " SI" : " NO") << endl;
    cout << "Esta B compensado?:";
    cout << (compensado(B) ? " SI" : " NO") << endl << endl;


    // PALABRAS DE UN ARBOL //
    cout << "PALABRAS DE A:\n";
    palabras(E);
    cout << "PALABRAS DE B:\n";
    palabras(B);
    cout << endl;



    // POSICION INORDEN //
    BB.insertar(5); BB.insertar(1); BB.insertar(3); BB.insertar(8); BB.insertar(6);
    cout << "Posicion Inorden en BB de 3: ";
    cout << posicionInorden(BB, 3);
    cout << endl << "Posicion Inorden en BB de 8: ";
    cout << posicionInorden(BB, 8);
    cout << endl << "Posicion Inorden en BB de 7: ";
    cout << posicionInorden(BB, 7);
    cout << endl << endl;

/*    // INDICE //

    Indice ind;
    ind.insertarReferencia("modelo", 4);
    ind.insertarReferencia("modelo", 2);
    ind.insertarReferencia("modelo", 4);
    ind.insertarReferencia("programa", 4);
    ind.insertarReferencia("programa", 1);
    ind.insertarReferencia("programa", 1);
    ind.insertarReferencia("algoritmo", 3);
    ind.insertarReferencia("algoritmo", 1);
    ind.generarRefsCruzadas();

    ind.insertarReferencia("tad", 15);
    ind.generarRefsCruzadas();

*/
    system("PAUSE");
    return 0;
}
