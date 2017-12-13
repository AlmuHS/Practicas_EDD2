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

