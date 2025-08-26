#include <iostream>
#include "WordSearch.h"

using namespace std;

WordSearch::WordSearch() {
    this->inicializar_tablero();
    this->cargar_lista_movimientos();
}

void WordSearch::mostrar_tablero() const {
    int filas = this->tablero.size();
    int columnas = this->tablero[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << this->tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

bool WordSearch::buscar_palabra(const string &palabra, int fil, int col, int indice) {
    //TODO
    return false;
}

bool WordSearch::encontrar_solucion(string palabra) {
    //TODO
    return false;
}


void WordSearch::inicializar_tablero() {
    this->tablero = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
}

void WordSearch::cargar_lista_movimientos() {
    // Movimiento en 4 direcciones: arriba, abajo, izquierda, derecha
    this->movimientos = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
}
