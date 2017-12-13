#ifndef _TERMINO_H_
#define _TERMINO_H_

#include <string>
#include "lista.h"

class Termino {
	public:
    	Termino(string p, Lista<int> *pgs);
        Termino(const Termino& t);
        string getPalabra() const { return pal; }
        Lista<int>* getPaginas() const { return pags; }
        void setPalabra(string p);
        void setPaginas(const Lista<int>* pgs);
        bool operator==(const Termino& t) const { return pal == t.pal; }
        bool operator<(const Termino& t) const { return pal < t.pal; }
        bool operator>(const Termino& t) const { return pal > t.pal; }
	private:
		string pal;
		Lista<int> *pags;
};

#endif







