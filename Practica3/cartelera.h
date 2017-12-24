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


#ifndef _CARTELERA_H_
#define _CARTELERA_H_

#include <iostream>
#include <map>
#include <utility>
#include <string>


using namespace std;

class Cartelera {
      public:
             Cartelera();
             void insertaEspectaculo(const string& e);
             void insertaSala(const string& e, const string& s, const string& c);
             void eliminaEspectaculo(const string& e);
             void eliminaSala(const string& e, const string& s);
             void listaEspectaculos();
             void listaSalas(const string& e);
      private:
              typedef map<string, string> DSalas;
              typedef pair<string, string> PSalas;
              typedef map<string, DSalas> DEspectaculos;
              typedef pair<string, DSalas> PEspectaculos;
              DEspectaculos espectaculos;
};


#endif
