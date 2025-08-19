#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <vector>
#define NO_ASIGNADO 0

using namespace std;

class Sudoku {
private:
    int tamaño;
    vector<vector<int>> tablero;
public:
    Sudoku();

    void mostrar_tablero();

    bool encontrar_solucion();

private:
    void inicializar_tablero();

    bool encontrar_casilla_no_asignada(int &fil, int &col);

    bool usando_en_fila(int num, int fil);

    bool usando_en_columna(int num, int col);

    bool usado_en_subtablero(int num, int fil_ini, int col_ini);

    bool hay_conflicto(int fil, int col, int num);
};

#endif //SUDOKU_SUDOKU_H
