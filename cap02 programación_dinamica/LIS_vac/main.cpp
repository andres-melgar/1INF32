#include <iostream>

#include "LIS.h"

int main() {
    LIS lisSolver;
    int longitud = lisSolver.encontrar_solucion();
    cout << "Longitud de la subsecuencia creciente más larga: " << longitud << endl;
    return 0;
}
