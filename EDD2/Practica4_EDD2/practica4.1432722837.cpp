#include <iostream>
#include <stdlib.h>
#include "grafo.h"
#include "conjunto.h"
#include <queue>
#include <sstream>
#include <map>

using namespace std;

//Ejercicio 1
template <typename T>
T verticeMaxCoste(const Grafo<T, float>& G)
{
	T Vert_max;
	float max_coste = 0;
	map<T, float> Dicc_vertices;
	typename Grafo<T,float>::ConjVertices cvertices, ady_vertice;//obtengo los vertices
	typename Grafo<T,float>::ConjAristas caristas = G.aristas();
	cvertices = G.vertices();
	
	while(!cvertices.esVacio()){
		Dicc_vertices[cvertices.quitar().getObj()] = 0;//inicializo el diccionario
	}
	
	while(!caristas.esVacio()){
		Arista<T, float> arista = caristas.quitar();
		Dicc_vertices[arista.getOrigen()] += arista.getEtiqueta();
	}
	
	for(typename map<T,float>::iterator it = Dicc_vertices.begin(); it != Dicc_vertices.end(); it++){
		if(it->second > max_coste){
			max_coste = it->second;
			Vert_max = it->first;
		} 
	}//fin for
	
	return Vert_max;
	
}


//Ejercicio 2
template <typename T, typename U>
void inaccesibles(const Grafo<T, U>& G)
{
	map <T, U> Dicc_vertices;
	typename Grafo<T,U>::ConjVertices cvertices = G.vertices();
	typename Grafo<T,U>::ConjAristas caristas = G.aristas();
	
	while(!cvertices.esVacio()){
		Dicc_vertices[cvertices.quitar().getObj()] = NULL;
	}
	
	while(!caristas.esVacio()){
		Arista<T,U> arista = caristas.quitar();
		Dicc_vertices[arista.getDestino()] = arista.getOrigen();
	}
	
	for(typename map<T,U>::iterator it = Dicc_vertices.begin(); it != Dicc_vertices.end(); it++){
		if(it->second == NULL) cout<<it->first<<"\t";
	}
	cout<<endl;
}


// Ejercicio 3
template <typename T, typename U>
void recorrido_anchura(const Grafo<T, U>& G, const T& v)
{
	queue<T> colaVertices;
	map<T, bool> Dicc_vertices;
	typename Grafo<T, U>::ConjVertices cvertices = G.vertices();
	
	while(!cvertices.esVacio()){
		Vertice<T> vertice = cvertices.quitar();
		Dicc_vertices[cvertices.getObj()] = false;
	}
	
	colaVertices.push(v);
	Dicc_vertices[v] = true;
	
	while(!colaVertices.empty()){
		
	}
	
	/*for(typename map<T,U>::iterator it = Dicc_vertices.begin(); it != Dicc_vertices.end(); it++){
		colaVertices.push(it->first);
		it->second = true;	
	}*/

	
	
	
	
}


//Ejercicio 4
template <typename T>
void caminosAcotados(const Grafo<T, float>& G, const T& vertice, float maxCoste)
{
	map<T,bool> recorridos;
	
	typename Grafo<T,float>::ConjVertices cvertices=G.vertices();
	
	stringstream camino;
	
	while(!cvertices.esVacio()) recorridos[vertice] = false;
	caminosAcotados(G, vertice, maxCoste, 0, recorridos, camino);
	
	cout<<camino;
		
}

template <typename T>
void caminosAcotados(const Grafo<T, float>& G, const T& vertice, float maxCoste, float dRecorrida, map<T,bool> Vrecorridos, stringstream &camino){
	
	typename Grafo<T,float>::ConjAristas caristas = G.aristas();

	if(dRecorrida < maxCoste){
		typename Grafo<T,float>::ConjVertices adyacentes = G.adyacentes(vertice);
		Vrecorridos[vertice]=true;
		while(!adyacentes.esVacio()){
			Arista<T,float> arista;
			if(dRecorrida < maxCoste && !Vrecorridos[vertice]){
				Vertice<T> ady = adyacentes.quitar();
				camino<<vertice;
				arista = caristas.quitar();
				while(arista.getOrigen() == vertice && arista.getDestino() == ady.getObj()) arista = caristas.quitar();
				
				caminosAcotados(G, ady.getObj(), maxCoste, dRecorrida + arista.getEtiqueta(), camino);
			}	
		}
	}
}

//Ejercicio 5
template <typename T, typename U>
T outConectado(const Grafo<T, U>& G)
{
}


//Ejercicio 6
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U>& G, const T& v)
{
}


//********************************************************************//
int main()
{
    Grafo<int, float> G(7);
    for (int i = 1; i <= 7; i++) G.insertarVertice(i);
    G.insertarArista(2, 1, 4);
    G.insertarArista(1, 3, 3);
    G.insertarArista(1, 4, 2);
    G.insertarArista(1, 6, 1);
    G.insertarArista(6, 4, 5);
    G.insertarArista(4, 7, 3);
    G.insertarArista(5, 1, 6);

    Grafo<string, float> H(7);
    H.insertarVertice("Huelva"); H.insertarVertice("Lepe"); H.insertarVertice("Niebla");
    H.insertarVertice("Mazagon"); H.insertarVertice("Almonte"); H.insertarVertice("Aljaraque");
    H.insertarVertice("Matalascañas");
    H.insertarArista("Lepe", "Huelva", 4);
    H.insertarArista("Huelva", "Niebla", 3);
    H.insertarArista("Huelva", "Mazagon", 2);
    H.insertarArista("Huelva", "Aljaraque", 1);
    H.insertarArista("Mazagon", "Almonte", 3);
    H.insertarArista("Mazagon", "Matalascañas", 4);
    H.insertarArista("Aljaraque", "Mazagon", 5);
    H.insertarArista("Almonte", "Huelva", 6);

    Grafo<int, float> H2;
    H2.insertarVertice(1);
    cout<<" Numero de vertices de H2: "<< H2.numVertices() << endl << endl;


    cout << " Vertice de maximo coste en G: " << verticeMaxCoste(G) << endl;
    cout << " Vertice de maximo coste en H: " << verticeMaxCoste(H) << endl;

    
	cout << endl << " Vertices inaccesibles en G: ";
    inaccesibles(G);


    /*cout << endl << " Recorrido en anchura de H desde el vertice Huelva:  ";
    recorrido_anchura(H, string("Huelva"));*/

    cout << endl << " Caminos acotados en G a coste 9 desde el vertice 2:" << endl;
    caminosAcotados(G, 2, 9);

    /*cout << endl << endl << " Vertice outConectado en G: " << outConectado(G);
    cout << endl << " Vertice outConectado en H: " << outConectado(H);

    cout << endl << endl << " Recorrido en profundidad de H desde el vertice Huelva:  ";
    recorrido_profundidad(H, string("Huelva"));
    cout << endl << endl;*/

    system("PAUSE");
    return 0;
}
