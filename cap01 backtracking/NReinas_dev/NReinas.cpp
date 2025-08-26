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
    int columna_inicial = 0;
    int cantidad_soluciones = 0;
    encontrar_solucion(columna_inicial, cantidad_soluciones);
    cout << "Hay" << cantidad_soluciones << " soluciones" << endl;
}

bool NReinas::encontrar_solucion(int columna, int &cantidad_soluciones) {
    if (columna == this->tamaño) {
        cantidad_soluciones++;
        cout << "Solución # " << cantidad_soluciones << endl;
        this->mostrar_tablero();
        return false; //por que deseo todas las soluciones
    }
    for (int fila = 0; fila < this->tamaño; fila++) {
        if (this->es_movimiento_valido(fila, columna)) {
            this->tablero[fila][columna] = CELDA_LLENA; //pongo reina
            if (this->encontrar_solucion(columna + 1, cantidad_soluciones))
                return true;
            else
                this->tablero[fila][columna] = CELDA_VACIA; //saco reina
        }
    }
    return false;
}

bool NReinas::es_movimiento_valido(int fila, int columna) {
    //valido que no haya reina al lado izquierdo de la fila
    for (int i = 0; i < columna; i++)
        if (this->tablero[fila][i] == CELDA_LLENA)
            return false;

    //valido que no haya reina en la diagonal superior izquierda
    for (int i = columna - 1, j = fila - 1; i >= 0 && j >= 0; i--, j--)
        if (this->tablero[j][i] == CELDA_LLENA)
            return false;

    //valido que no haya reina en la diagonal inferior izquierda
    for (int i = columna - 1, j = fila + 1; i >= 0 && j >= 0; i--, j++)
        if (this->tablero[j][i] == CELDA_LLENA)
            return false;
    return true;
}
