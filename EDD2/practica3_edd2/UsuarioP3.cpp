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

#include <cstdlib>
#include <iostream>
# include "cartelera.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cartelera c;
    
    c.insertaEspectaculo("Perdiendo el norte");
    c.insertaEspectaculo("Cincuenta sombras de Grey");
    c.insertaEspectaculo("Into the woods");
    c.insertaEspectaculo("Interstelar");
    c.insertaEspectaculo("Torrente 5");
    c.insertaEspectaculo("Boyhood");
    c.insertaEspectaculo("Birdman");
    c.listaEspectaculos();
    cout << endl;
    c.insertaSala("Birdman", "Al Andalus", "Punta Umbria");
    c.insertaSala("Birdman", "Cinebox Aqualon Puerto", "Huelva");
    c.insertaSala("Birdman", "La Dehesa", "Isla Antilla");
    c.insertaSala("Birdman", "Artesiete Holea", "Huelva");
    c.insertaEspectaculo("Birdman");
    
    c.listaSalas("Birdman");
    cout << endl;
    
    c.eliminaSala("Birdman", "La Dehesa");
    cout << "Despues de eliminar la sala La Dehesa del espectaculo Birdman." << endl;
    c.listaSalas("Birdman");
    cout << endl;

    c.eliminaEspectaculo("Birdman");
    cout << "Despues de eliminar el espectaculo Birdman." << endl;
    c.listaEspectaculos();
    cout << endl;

    cout << "Birdman ya se elimino como espectaculo." << endl;
    cout << "Despues de eliminar la sala La Dehesa de un espectaculo que no existe" << endl;

    c.eliminaSala("Birdman", "La Dehesa");
    c.listaEspectaculos();
    cout << endl;

    c.listaSalas("Birdman");
    c.listaEspectaculos();

    system("PAUSE");
    return EXIT_SUCCESS;
}

