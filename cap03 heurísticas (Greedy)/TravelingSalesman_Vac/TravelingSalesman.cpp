#include <iostream>
#include <vector>
#include <limits>
#include "TravelingSalesman.h"

using namespace std;

TravelingSalesman::TravelingSalesman() {
    this->inicializar_distancias();
}

int TravelingSalesman::encontrar_solucion(int ciudad_inicio) {

    return 0;
}

void TravelingSalesman::imprimirRuta() {
    for (int ciudad: ruta) {
        cout << ciudad << " -> ";
    }
    cout << ruta[0] << endl; // Retorno al inicio
}

void TravelingSalesman::inicializar_distancias() {
    this->distancias = {
        {0, 2, 9, 10, 7},
        {2, 0, 6, 4, 3},
        {9, 6, 0, 8, 5},
        {10, 4, 8, 0, 6},
        {7, 3, 5, 6, 0}
    };
}