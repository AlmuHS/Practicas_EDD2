#ifndef _NODO_H_
#define _NODO_H_

template <typename T>
class Nodo {
    typedef Nodo<T>* PtrNodo;
    public:
        Nodo();   // constructor para crear un nodo vacío para usarlo como centinela
	    Nodo(const T& objeto);
		Nodo(const T& objeto, PtrNodo psig);
	    Nodo(const Nodo& n);
		const T& getObj() const;
		PtrNodo getSig() const;
		void setObj(const T& objeto);
		void setSig(PtrNodo psig);
	private:
		T obj;
	   	PtrNodo sig;
};

#endif


// ----------  Instanciaciones ----------
//
//  Nodo<char>
//  Nodo<int>


