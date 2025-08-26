#include <iostream>
#include "KnigthsTour.h"

bool test(int tamaño, int x0, int y0);

int main() {
    test(8, 0, 0);
    test(6, 0, 0);
    test(6, 0, 1);
    return 0;
}

bool test(int tamaño, int x0, int y0) {
    cout << "backtracking: (" << x0 << "," << y0 << ")" << endl;
    KnigthsTour knigthsTour(tamaño);
    knigthsTour.mostrar_tablero();
    knigthsTour.setInicio(x0, y0);
    bool encontro_solucion;
    encontro_solucion = knigthsTour.encontrar_solucion(2, x0, y0);
    knigthsTour.mostrar_tablero();
    cout << "encontró solución:" << encontro_solucion << endl;
    return encontro_solucion;
}
