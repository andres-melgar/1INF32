#ifndef KNAPSACK_KNAPSACK_H
#define KNAPSACK_KNAPSACK_H
#include <random>
#include <vector>

#include "Articulo.h"
#include "SolucionCandidata.h"

using namespace std;

class Knapsack {
private:
    // Datos de la instancia
    vector<Articulo> articulos;
    long long capacidad;

    // Parámetros GRASP
    double alpha;    // umbral por valor (0: solo el mejor, 1: todos los factibles)
    int beta;      // top-k después de filtrar por alpha (<=0 => sin límite)
    double tau;    // puntaje: tau*(v/w) + (1-tau)*v
    int iteraciones;

    // Solución final
    vector<bool> tomar;
    long long beneficio;
    long long peso;
public:
    Knapsack(const vector<Articulo>& articulos, long long capacidad, double alpha, int beta, double tau, int iteraciones);

    void GRASP();
private:
    void resetar_solucion_final();
};


#endif //KNAPSACK_KNAPSACK_H