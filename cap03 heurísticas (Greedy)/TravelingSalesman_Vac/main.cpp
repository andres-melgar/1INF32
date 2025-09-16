#include <iostream>
#include "TravelingSalesman.h"

using namespace std;

int main() {
    TravelingSalesman travelingSalesman;
    int ciudad_inicio = 0;
    int costo = travelingSalesman.encontrar_solucion(ciudad_inicio);

    cout << "Ruta seguida (heurística greedy): ";
    travelingSalesman.imprimirRuta();
    cout << "Costo total de la ruta: " << costo << endl;
    return 0;
}