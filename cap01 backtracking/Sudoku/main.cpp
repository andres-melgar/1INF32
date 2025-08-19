#include <iostream>
#include "Sudoku.h"

using namespace std;

int main() {
    Sudoku sudoku;
    sudoku.mostrar_tablero();
    sudoku.encontrar_solucion();
    sudoku.mostrar_tablero();
    return 0;
}