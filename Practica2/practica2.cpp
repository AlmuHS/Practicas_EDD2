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

template<typename T>
Arbin<T> numHojas(const Arbin<T>& a){
    return numHojas(a.getRaiz());
}

template<typename T>
int numHojas(const Arbin<T>& a, typename Arbin<T>::Iterador& it){
    int nhojas;
    if(a.esVacio()) nhojas=0;
    else if(a.subIzq().arbolVacio() && a.subDer().arbolVacio()) nhojas=1;
    else nhojas=numHojas(a.subIzq(), it)+numHojas(a.subDer(), it);
    return nhojas;
}


/****************************************************************************/
//Ejercicio 2

template<typename T>
Arbin<T> simetrico(const Arbin<T> &a){
    return simetrico(a.getRaiz());
}

template<typename T>
Arbin<T> simetrico(const Arbin<T> &a, typename Arbin<T>::Iterador& it){
    Arbin<T> sim;
    if(!it.arbolVacio())
        sim(it.observar(), simetrico(a, a.subDer(it)), simetrico(a, a.subIzq(it)));
    return sim;
}

/****************************************************************************/
//Ejercicio 3

template<typename T>
Arbin<T> recorridoZigzag(const Arbin<T> &a){
    return recorridoZigzag(a.getRaiz());
}

template<typename T>
void recorridoZigzag(const Arbin<T> &a, char sentido){
    if(!a.esVacio()){
        if(sentido=='D'){
            cout<<a.subDer().observar();
            recorridoZigzag(a, 'I');
        }
        else if(sentido=='I'){
            cout<<a.subIzq().observar();
            recorridoZigzag(a, 'D');
        }
    }//fin if
}

/******************************************************************************/
//Ejercicio 4

template<typename T>
Arbin<T> numNodos(const Arbin<T> &a){
    return numNodos(a.getRaiz());
}

template<typename T>
int numNodos(const Arbin<T> &a, typename Arbin<T>::Iterador& it){
    int nNodos=0;
    if(!it.arbolVacio()){
        if(!a.subDer().arbolVacio()) nNodos++;
        if(!a.subIzq().arbolVacio()) nNodos++;
    }
    nNodos+=numNodos(a, a.subDer(it))+numNodos(a, a.subIzq(it));
    return nNodos;
}

template<typename T>
Arbin<T> compensado(const Arbin<T> &a){
    return(a.getRaiz());
}

template<typename T>
bool compensado(const Arbin<T> &a, typename Arbin<T>::Iterador& it){
    bool comp=false;
    if(a.esVacio() || a.getRaiz().arbolVacio()) comp=true;
    else{
        if(abs(numNodos(a.subIzq())-numNodos(a.subDer()))<=1 && compensado(a, a.subDer())&& compensado(a, a.subIzq()))
            comp=true;
    }
    return comp;
}

/*****************************************************************************/
//Ejercicio 5

void palabras(const Arbin<char> &a){
    palabras(a.getRaiz());
}

void palabras(const Arbin<char> &a, typename Arbin<char>::Iterador& it){
    string palabra;
    if(!it.arbolVacio()){
        palabras(a, a.subIzq(it));
        palabras(a, a.subDer(it));
        palabra+=it.observar();
    }
    else cout<<palabra;
}

/******************************************************************************/
//Ejercicio 6

template<typename T>
ABB<T> posicion(const ABB<T> &a){
    return posicion(a.getRaiz());
}

template<typename T>
int posicion(const ABB<T> &a, typename ABB<T>::Iterador& it, const T& n){
    int pos=0;
    if(a.buscar(n)){
        if(it.observar()<T){
            pos+=posicion(a.subDer(it))+1;
        }
        else{
            pos+=posicion(a.subIzq(it))-1;
        }
    }
    return pos;
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

/*

    // NUMERO HOJAS //
    cout << "Num. hojas del arbol B: " << numHojas(B) << endl;
    cout << "Num. hojas del arbol E: " << numHojas(E) << endl << endl;

    // COPIA SIMETRICA //
    Arbin<char> C = simetrico(B);
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

    // INDICE //

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
