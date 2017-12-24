/*Copyright 2015 Almudena Garcia Jurado-Centurion

This file is part of Practica3_EDD2.

Practica3_EDD2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica3_EDD2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica3_EDD2.  If not, see <http://www.gnu.org/licenses/>.*/

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

