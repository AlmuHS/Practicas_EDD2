#include <cstdlib>
#include <iostream>
# include "cartelera.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cartelera c;

    c.insertaEspectaculo("Oblivion");
    c.insertaEspectaculo("Conversaciones con mama");
    c.insertaEspectaculo("Los miserables");
    c.insertaEspectaculo("Romeo y Julieta");
    c.insertaEspectaculo("El gato montes");
    c.insertaEspectaculo("El malentendido");
    c.insertaEspectaculo("Los Croods");
    c.listaEspectaculos();
    cout << endl;

    c.insertaSala("Los Croods", "Al Andalus", "Punta Umbria");
    c.insertaSala("Los Croods", "Cinebox Aqualon Puerto", "Huelva");
    c.insertaSala("Los Croods", "La Dehesa", "Isla Antilla");
    c.insertaSala("Los Croods", "La Dehesa", "Isla Cristina");
    c.insertaEspectaculo("Los Croods");
    c.listaSalas("Los Croods");
    cout << endl;

    c.eliminaSala("Los Croods", "La Dehesa");
    cout << "Despues de eliminar la sala La Dehesa del espectaculo Los Croods." << endl;
    c.listaSalas("Los Croods");
    cout << endl;

    c.eliminaEspectaculo("Los Croods");
    cout << "Despues de eliminar el espectaculo Los Croods." << endl;
    c.listaEspectaculos();
    cout << endl;

    cout << "Los Croods ya se elimino como espectaculo." << endl;
    cout << "Despues de eliminar la sala La Dehesa de un espectaculo que no existe" << endl;
    c.eliminaSala("Los Croods", "La Dehesa");
    c.listaEspectaculos();
    cout << endl;

    c.listaSalas("Los Croods");
    c.listaEspectaculos();
    cout << endl;

    cout << "Inserta sala de un espectaculo inexistente." << endl;
    c.insertaSala("Los Croods", "Al Andalus", "Punta Umbria");
    c.listaEspectaculos();

    //system("PAUSE");
    return EXIT_SUCCESS;
}
