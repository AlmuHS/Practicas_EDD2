#include "cartelera.h"
#include <iostream>

using namespace std;

Cartelera::Cartelera():espectaculos()
{
}

void Cartelera::insertaEspectaculo(const string& e)
{
    espectaculos.insert(PEspectaculos(e, DSalas()));
}

void Cartelera::insertaSala(const string& e, const string& s, const string& c)
{
    espectaculos[e].insert(PSalas(s,c));
}

void Cartelera::eliminaEspectaculo(const string& e)
{
    espectaculos.erase(e);
}

void Cartelera::eliminaSala(const string& e, const string& s)
{
    DEspectaculos::iterator it = espectaculos.find(e);
    if(it != espectaculos.end()) it->second.erase(s);
}

void Cartelera::listaEspectaculos()
{
    if(!espectaculos.empty())
        for(DEspectaculos::iterator it = espectaculos.begin(); it != espectaculos.end(); it++){
            cout<<"Espectaculo: "<<it->first<<endl;
            cout<<"Salas: ";
            listaSalas(it->first);
            cout<<endl;
        }
}

void Cartelera::listaSalas(const string& e)
{
    DEspectaculos::iterator it_esp=espectaculos.find(e);
    if(it_esp != espectaculos.end()){
        if(!it_esp->second.empty())
            for(DSalas::iterator it_sala = it_esp->seoond.begin(); it_sala != it_esp->second.end(); it_sala++)
                cout<<it_sala->second<<"\t";
    }
}

