
#ifndef TRAVELINGSALESMAN_H
#define TRAVELINGSALESMAN_H

#include <vector>

using namespace std;

class TravelingSalesman {
private:
    vector<vector<int>> distancias;
    vector<int> ruta;
public:
    TravelingSalesman();

    int encontrar_solucion(int ciudad_inicio);

    void imprimirRuta();

private:
    void inicializar_distancias();
};



#endif //TRAVELINGSALESMAN_H
