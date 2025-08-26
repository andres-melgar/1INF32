#include <iostream>
#include <iomanip>
#include <vector>
#include "NReinas.h"

using namespace std;

NReinas::NReinas(int tamaño) {
    this->tamaño = tamaño;
    this->inicializar_tablero();
}

void NReinas::inicializar_tablero() {
    this->tablero = vector(tamaño, vector<int>(tamaño, CELDA_VACIA));
}

void NReinas::mostrar_tablero() const {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            cout << setw(2) << (tablero[i][j] == CELDA_VACIA ? "." : "Q");
        }
        cout << endl;
    }
    cout << endl;
}

void NReinas::mostrar_soluciones() {
    //TODO
}

bool NReinas::encontrar_solucion(int columna, int &cantidad_soluciones) {
    //TODO
    return false;
}

bool NReinas::es_movimiento_valido(int fila, int columna) {
    //TODO
    return false;
}
