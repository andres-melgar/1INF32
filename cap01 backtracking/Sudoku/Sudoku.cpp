#include "Sudoku.h"

#include <iostream>

Sudoku::Sudoku() {
    this->tamaño = 9;
    this->inicializar_tablero();
}

void Sudoku::mostrar_tablero() {
    for (int i = 0; i < this->tamaño; i++) {
        if (i % 3 == 0)
            cout << endl;
        for (int j = 0; j < this->tamaño; j++) {
            if (j % 3 == 0)
                cout << " ";
            if (this->tablero[i][j] == NO_ASIGNADO)
                cout << "*";
            else
                cout << this->tablero[i][j];
        }
        cout << endl;
    }
}

bool Sudoku::encontrar_solucion() {
    int fil, col;
    if (!this->encontrar_casilla_no_asignada(fil, col))
        return true;
    for (int num=1; num<=9; num++) {
        if (!this->hay_conflicto(fil, col, num)) {
            this->tablero[fil][col] = num;
            if (this->encontrar_solucion())
                return true;
            else
                this->tablero[fil][col] = NO_ASIGNADO;
        }
    }
    return false;
}

void Sudoku::inicializar_tablero() {
    this->tablero = {
        {0, 2, 0, 0, 0, 0, 0, 9, 0},
        {3, 0, 1, 9, 0, 6, 5, 0, 2},
        {0, 0, 0, 8, 0, 4, 0, 0, 0},
        {0, 9, 0, 0, 0, 0, 0, 5, 0},
        {5, 0, 0, 2, 0, 3, 0, 0, 6},
        {0, 7, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 4, 0, 7, 0, 0, 0},
        {8, 0, 2, 5, 0, 1, 7, 0, 3},
        {0, 5, 0, 0, 0, 0, 0, 8, 0}
    };
}

bool Sudoku::encontrar_casilla_no_asignada(int &fil, int &col) {
    for (int i=0; i<this->tamaño; i++)
        for (int j=0; j<this->tamaño; j++)
            if (this->tablero[i][j] == NO_ASIGNADO) {
                fil = i;
                col = j;
                return true;
            }
    return false;
}

bool Sudoku::usando_en_fila(int num, int fil) {
    for (int i=0; i<this->tamaño; i++)
        if (this->tablero[fil][i] == num)
            return true;
    return false;
}

bool Sudoku::usando_en_columna(int num, int col) {
    for (int i=0; i<this->tamaño; i++)
        if (this->tablero[i][col] == num)
            return true;
    return false;
}

bool Sudoku::usado_en_subtablero(int num, int fil_ini, int col_ini) {
    for (int dfil=0; dfil<3; dfil++) {
        for (int dcol=0; dcol<3; dcol++) {
            int fil_nueva = fil_ini + dfil;
            int col_nueva = col_ini + dcol;
            if (this->tablero[fil_nueva][col_nueva] == num)
                return true;
        }
    }
    return false;
}

bool Sudoku::hay_conflicto(int fil, int col, int num) {
    bool es_usado_en_fila = this->usando_en_fila(num, fil);
    bool es_usado_en_columna = this->usando_en_columna(num, col);
    int fil_ini = fil - fil%3;
    int col_ini = col - col%3;
    bool es_usado_en_subtablero = this->usado_en_subtablero(num, fil_ini, col_ini);
    return es_usado_en_columna || es_usado_en_fila || es_usado_en_subtablero;
}
