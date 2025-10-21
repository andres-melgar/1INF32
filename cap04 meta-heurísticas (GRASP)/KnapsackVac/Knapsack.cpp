#include "Knapsack.h"
#include <algorithm>
#include <iostream>
#include <random>
#include "SolucionCandidata.h"

using namespace std;

Knapsack::Knapsack(const vector<Articulo> &articulos, long long capacidad, double alpha, int beta, double tau,
                   int iteraciones) {
    // Datos de la instancia
    this->articulos = articulos;
    this->capacidad = capacidad;
    // Parámetros GRASP
    this->alpha = alpha;
    this->beta = beta;
    this->tau = tau;
    this->iteraciones = iteraciones;
    // Solución final
    this->resetar_solucion_final();
}

void Knapsack::GRASP() {

}

void Knapsack::resetar_solucion_final() {
    this->tomar.assign(this->articulos.size(), false);
    this->beneficio = 0;
    this->peso = 0;
}
