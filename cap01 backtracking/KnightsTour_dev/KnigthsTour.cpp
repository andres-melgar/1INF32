#include <iostream>
#include <iomanip>
#include <vector>
#include "KnigthsTour.h"

using namespace std;

KnigthsTour::KnigthsTour(int tamaño) {
    this->tamaño = tamaño;
    this->inicializar_tablero();
    this->cargar_lista_movimientos();
}

void KnigthsTour::inicializar_tablero() {
    this->tablero = vector(tamaño, vector<int>(tamaño, CELDA_VACIA));
}

void KnigthsTour::mostrar_tablero() const {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            cout << setw(2) << setfill('0') << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void KnigthsTour::setInicio(int x0, int y0) {
    if (this->es_movimiento_valido(x0, y0))
        this->tablero[x0][y0] = 1;
}

bool KnigthsTour::es_movimiento_valido(int x, int y) {
    return x>=0 && y>=0 && x<this->tamaño && y<this->tamaño &&
        this->tablero[x][y] == CELDA_VACIA;
}

bool KnigthsTour::encontrar_solucion(int i, int x, int y) {
    if (i == this->tamaño * tamaño + 1)
        return true;
    for (const auto&[dx,dy]: this->lista_movimientos) {
        int nuevo_x = x + dx;
        int nuevo_y = y + dy;
        if (this->es_movimiento_valido(nuevo_x, nuevo_y)) {
            this->tablero[nuevo_x][nuevo_y] = i;
            if (encontrar_solucion(i+1, nuevo_x, nuevo_y))
                return true;
            else
                this->tablero[nuevo_x][nuevo_y] = CELDA_VACIA;
        }
    }
    return false;
}

void KnigthsTour::cargar_lista_movimientos() {
    this->lista_movimientos = {
        {2, 1},
        {1, 2},
        {-1, 2},
        {-2, 1},
        {-2, -1},
        {-1, -2},
        {1, -2},
        {2, -1}
    };
}
