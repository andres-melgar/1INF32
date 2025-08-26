#ifndef KNIGTHSTOUR_H
#define KNIGTHSTOUR_H
#include <vector>
#include <list>
#define CELDA_VACIA 0

using namespace std;

class KnigthsTour {
private:
    int tamaño;
    vector<vector<int>> tablero;
    list<pair<int,int>> lista_movimientos;
public:
    KnigthsTour(int tamaño);

    void inicializar_tablero();

    void mostrar_tablero() const;

    void setInicio(int x0, int y0);

    bool es_movimiento_valido(int x, int y);

    bool encontrar_solucion(int i, int x, int y);

private:
    void cargar_lista_movimientos();
};

#endif //KNIGTHSTOUR_H
