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

