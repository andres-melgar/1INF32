//
// Created by amelgar on 30/07/2025.
//

#ifndef NREINAS_H
#define NREINAS_H
#include <vector>
#define CELDA_VACIA 0
#define CELDA_LLENA 1

using namespace std;

class NReinas {
private:
    int tamaño;
    vector<vector<int>> tablero;

public:
    NReinas(int tamaño);

    void inicializar_tablero();

    void mostrar_tablero() const;

    bool encontrar_solucion(int columna, int &cantidad_soluciones);

    void mostrar_soluciones();

private:
    bool es_movimiento_valido(int fila, int columna);
};



#endif //NREINAS_H
