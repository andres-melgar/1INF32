#include <iostream>
#include "CoinRow.h"

using namespace std;

int main() {
    CoinRow coinRow;
    int maxima_cantidad_monedas = coinRow.encontrar_solucion();
    cout << "Máximo de monedas que se pueden obtener: " << maxima_cantidad_monedas << endl;
    coinRow.imprimir_dp();
    return 0;
}
