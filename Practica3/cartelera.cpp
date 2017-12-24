/*Copyright 2015 Almudena Garcia Jurado-Centurion

This file is part of Practica4_EDD2.

Practica4_EDD2 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Practica4_EDD2 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Practica4_EDD2.  If not, see <http://www.gnu.org/licenses/>.*/


#include "cartelera.h"

using namespace std;

Cartelera::Cartelera(){

}

void Cartelera::insertaEspectaculo(const string& e){
    PEspectaculos nuevo_espectaculo(e, DSalas());
    espectaculos.insert(nuevo_espectaculo);
}

void Cartelera::insertaSala(const string& e, const string& s, const string& c){
    espectaculos[e].insert(PSalas(s,c));
}


void Cartelera::eliminaEspectaculo(const string& e){
    espectaculos.erase(e);
}

void Cartelera::eliminaSala(const string& e, const string& s){
    DEspectaculos::iterator it;
    it=espectaculos.find(e);
    if(it!=espectaculos.end()) it->second.erase(s);
}

void Cartelera::listaEspectaculos(){
    DEspectaculos::iterator it;
    for(it=espectaculos.begin(); it!=espectaculos.end(); it++){
        cout<<"\nEspectaculo: "<<it->first<<endl;
        DSalas::iterator it2=it->second.begin();
        cout<<"Salas: ";
        while(it2!=it->second.end()){
            cout<<it2->first<<"\t";
            cout<<it2->second<<endl;
            it2++;
        }
    }
}


void Cartelera::listaSalas(const string& e){
    DEspectaculos::iterator it;
    it=espectaculos.find(e);

    if(it!=espectaculos.end()){
        DSalas::iterator it2=it->second.begin();
        cout<<endl<<"Salas: ";
        while(it2!=it->second.end()){
            cout<<it2->first<<"\t";
            cout<<it2->second<<endl;
            it2++;
        }
    }
}

