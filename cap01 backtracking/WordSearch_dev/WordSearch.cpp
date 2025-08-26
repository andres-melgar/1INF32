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
    if (indice == palabra.length())
        return true;

    //verifico que no se salga del tablero o que no coincida la letra
    if (fil < 0 || col < 0 || fil >= this->tablero.size() || col >= this->tablero[0].size()
        || this->tablero[fil][col] != palabra[indice])
        return false;

    char caracter_original = this->tablero[fil][col];
    this->tablero[fil][col] = VISITADO;

    for (const auto &[dx, dy]: this->movimientos) {
        int nueva_fila = fil + dx;
        int nueva_col = col + dy;
        if (buscar_palabra(palabra, nueva_fila, nueva_col, indice+1))
            return true;
    }
    this->tablero[fil][col] = caracter_original; //bactracking
    return false;
}

bool WordSearch::encontrar_solucion(string palabra) {
    int filas = this->tablero.size();
    int columnas = this->tablero[0].size();
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (buscar_palabra(palabra, i, j, 0))
                return true;
        }
    }
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
