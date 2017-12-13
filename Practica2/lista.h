#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"
#include "excep_lista.h"

template <typename T>
class Lista {
    typedef Nodo<T>* PtrNodo;

    public:
        class Iterador {      // clase iterador anidada dentro de la clase lista
           friend class Lista<T>;
           public:
                 void avanzar(const Lista& L) throw(PosicionErroneaExcepcion)
                 {
					 if (anterior == L.ultimo)
                        throw PosicionErroneaExcepcion();
                     anterior = anterior->getSig();
                 }
                 const T& observar(const Lista& L) const throw(PosicionErroneaExcepcion)
                 {
					 if (anterior == L.ultimo)
                        throw PosicionErroneaExcepcion();
                     return anterior->getSig()->getObj();
                 }
                 int posicion(const Lista& L) const
                 {
                     int pos = 1;
                     PtrNodo p = L.primero;
                     while (p != anterior) {
                         p = p->getSig();
                         pos++;
                     }
                     return pos;
                 }
                 bool operator!=(const Iterador & der) const
                 {
					 return (anterior != der.anterior);
			     }
                 bool operator==(const Iterador & der) const
                 {
					 return (anterior == der.anterior);
			     }
            private:
                 PtrNodo anterior;
                 Iterador(PtrNodo p) { anterior = p; }
        };

		Lista();
		Lista(const Lista& list);
		bool esVacia() const;
		int longitud() const;
		void anadirIzq(const T& objeto);
		void anadirDch(const T& objeto);
		void eliminarIzq() throw(ListaVaciaExcepcion);
		void eliminarDch() throw(ListaVaciaExcepcion);
		const T& observarIzq() const throw(ListaVaciaExcepcion);
		const T& observarDch() const throw(ListaVaciaExcepcion);
		void concatenar(const Lista& list);
		bool pertenece(const T& objeto) const;
		void insertar(int posicion, const T& objeto) throw(PosicionErroneaExcepcion);
		void eliminar(int posicion) throw(PosicionErroneaExcepcion);
		void modificar(int posicion, const T& objeto) throw(PosicionErroneaExcepcion);
		const T& observar(int posicion) const throw(PosicionErroneaExcepcion);
		int posicion(const T& objeto) const throw(ObjetoInexistenteExcepcion);
		~Lista();

		// Métodos propios de la lista con iterador
		void insertar(const Iterador& it, const T& objeto);
		void eliminar(const Iterador& it) throw(PosicionErroneaExcepcion);
        void modificar(const Iterador& it, const T& objeto) throw(PosicionErroneaExcepcion);
        const T& observar(const Iterador& it) const throw(PosicionErroneaExcepcion);
        const Iterador& principio() const;
		const Iterador& final() const;
		const Iterador& ponerIterador(int posicion) const throw(IndiceErroneoExcepcion);

    private:
		PtrNodo primero, ultimo;
		int num;
};

#endif
