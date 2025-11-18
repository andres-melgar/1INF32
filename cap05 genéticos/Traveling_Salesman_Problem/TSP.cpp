#include "TSP.h"
#include <vector>

using namespace std;

TSP::TSP() {
    this->distancias  = {};
    this->n = 0;
}

TSP::TSP(vector<vector<int>> distancias) {
    this->distancias  = distancias;
    this->n = this->distancias.size();
}

//esta es la función objetivo --> fitness
//tour es el arreglo que esté en el cromosoma
int TSP::costo_tour(const vector<int> &tour) {
    int costo = 0;
    for (int i=0; i<this->n-1; i++) {
        int origen = tour[i];
        int destino = tour[i+1];
        costo += this->distancias[origen][destino];
    }
    int origen = tour[this->n-1];
    int destino = tour[0];
    costo += this->distancias[origen][destino];
    return costo;
}

vector<vector<int>> TSP::get_distancias() const {
    return distancias;
}

void TSP::set_distancias(const vector<vector<int>> &distancias) {
    this->distancias = distancias;
}

int TSP::get_n() const {
    return n;
}

void TSP::set_n(int n) {
    this->n = n;
}
