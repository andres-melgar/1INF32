#include "Cromosoma.h"

#include <iostream>
#include <ostream>

Cromosoma::Cromosoma(vector<int> tour, int costo) {
    this->tour = tour;
    this->costo = costo;
}

void Cromosoma::imprimir() {
    cout << "Solución:" << endl;
    for (int x: this->tour) {
        cout << x << " ";
    }
    cout << "(Costo = " << this->costo << ")" << endl;
}

void Cromosoma::mutacion(double probabilidad) {
    double sorteo = (double)rand()/RAND_MAX;
    if (sorteo < probabilidad) {
        int n = this->tour.size();
        int i = rand()%n;
        int j = rand()%n;
        swap(this->tour[i], this->tour[j]);
    }
}

vector<int> Cromosoma::get_tour() const {
    return tour;
}

void Cromosoma::set_tour(const vector<int> &tour) {
    this->tour = tour;
}

int Cromosoma::get_costo() const {
    return costo;
}

void Cromosoma::set_costo(int costo) {
    this->costo = costo;
}
