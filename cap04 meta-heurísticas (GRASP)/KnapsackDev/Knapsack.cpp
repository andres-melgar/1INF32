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
    mt19937_64 rng(random_device{}());
    for (int i=0; i< this->iteraciones; i++) {
        SolucionCandidata solucionCandidata = construir(rng);
        mejorar(solucionCandidata);
    }
    retornar();
}

SolucionCandidata Knapsack::construir(mt19937_64 rng) {
    int n = this->articulos.size();
    SolucionCandidata solucionCandidata(n);
    vector<int> no_elegidos = this->construir_candidatos_no_elegidos(n);

    while (true) {
        vector<int> candidatos = this->construir_candidatos_factibles(solucionCandidata, no_elegidos);
        if (candidatos.empty()) {
            break;
        }
    }
    return solucionCandidata;
}

vector<int> Knapsack::construir_candidatos_no_elegidos(int n) {
    vector<int> no_elegidos(n);
    //no_elegidos tiene [0..n[
    iota(no_elegidos.begin(), no_elegidos.end(), 0);
    return no_elegidos;
}

vector<int> Knapsack::construir_candidatos_factibles(const SolucionCandidata &solucionCandidata,
    const vector<int> &no_elegidos) {
    vector<int> candidatos;
    candidatos.resize(no_elegidos.size());
    for (int id: no_elegidos) {
        if (solucionCandidata.get_peso()+this->articulos[id].get_peso() <= this->capacidad) {
            candidatos.push_back(id);
        }
    }
    return candidatos;
}

void Knapsack::mejorar(SolucionCandidata &solucionCandidata) {

}

void Knapsack::retornar() {

}

void Knapsack::resetar_solucion_final() {
    this->tomar.assign(this->articulos.size(), false);
    this->beneficio = 0;
    this->peso = 0;
}