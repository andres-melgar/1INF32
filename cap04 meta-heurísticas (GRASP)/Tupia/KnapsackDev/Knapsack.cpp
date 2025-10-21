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
    for (int i = 0; i < this->iteraciones; i++) {
        SolucionCandidata solucionCandidata = construir(rng);
        mejorar(solucionCandidata);
    }
    retornar();
}

void Knapsack::resetar_solucion_final() {
    this->tomar.assign(this->articulos.size(), false);
    this->beneficio = 0;
    this->peso = 0;
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
        double smin, smax;
        vector<pair<double, int> > puntajes = this->construir_puntajes_de_candidatos(candidatos, smin, smax);
        vector<pair<double, int> > RCL= this->formacion_de_la_RCL(puntajes, smin, smax);
        int elegido = this->eleccion_de_item_aleatorio(RCL, rng);
        solucionCandidata.incluir(elegido, this->articulos[elegido].get_peso(), this->articulos[elegido].get_beneficio());
        this->retirar_elegido_de_los_no_elegidos(elegido, no_elegidos);
    }
    return solucionCandidata;
}

vector<int> Knapsack::construir_candidatos_no_elegidos(int n) {
    vector<int> no_elegidos(n);
    //voy a colocar los enteros: 0, 1, 2, 3, 4, 5, ..., n-2, n-1
    iota(no_elegidos.begin(), no_elegidos.end(), 0);
    return no_elegidos;
}

vector<int> Knapsack::construir_candidatos_factibles(const SolucionCandidata &solucionCandidata,
                                                     const vector<int> &no_elegidos) {
    vector<int> candidatos;
    candidatos.reserve(no_elegidos.size());
    for (int id: no_elegidos) {
        if (solucionCandidata.get_peso() + this->articulos[id].get_peso() <= this->capacidad) {
            candidatos.push_back(id);
        }
    }
    return candidatos;
}

vector<pair<double, int> > Knapsack::construir_puntajes_de_candidatos(const vector<int> &candidatos, double &smin,
                                                                      double &smax) {
    vector<pair<double, int> > puntajes;
    puntajes.reserve(candidatos.size());
    smin = numeric_limits<double>::infinity();
    smax = -numeric_limits<double>::infinity();
    for (int id: candidatos) {
        double razon = (double) this->articulos[id].get_beneficio() / (double) this->articulos[id].get_peso();
        double p = this->tau * razon + (1.0 - this->tau) * this->articulos[id].get_beneficio();
        smin = min(smin, p);
        smax = max(smax, p);
        puntajes.emplace_back(p, id);
    }
    return puntajes;
}

vector<pair<double, int> > Knapsack::formacion_de_la_RCL(const vector<pair<double, int> > &puntajes, double smin,
                                                         double smax) {
    vector<pair<double, int> > RCL;
    RCL.reserve(puntajes.size());
    this->formacion_de_la_RCL_por_umbral(RCL, puntajes, smin, smax);
    this->formacion_de_la_RCL_por_cardinalidad(RCL);
    return RCL;
}

void Knapsack::formacion_de_la_RCL_por_umbral(vector<pair<double, int> > &RCL,
                                              const vector<pair<double, int> > &puntajes,
                                              double smin, double smax) {
    if (this->alpha <= 0.00) {
        double umbral = smax;
        for (auto &puntaje: puntajes) {
            if (puntaje.first >= umbral) {
                RCL.push_back(puntaje);
            }
        }
    } else if (this->alpha >= 1.00) {
        for (auto &puntaje: puntajes) {
            RCL.push_back(puntaje);
        }
    } else {
        double umbral = smax - this->alpha * (smax - smin);
        for (auto &puntaje: puntajes) {
            if (puntaje.first >= umbral) {
                RCL.push_back(puntaje);
            }
        }
    }
}

void Knapsack::formacion_de_la_RCL_por_cardinalidad(vector<pair<double, int> > &RCL) {
    int k = this->beta>0 ? min(this->beta, (int)RCL.size()): RCL.size();
    if (RCL.size() > k) {
        nth_element(RCL.begin(), RCL.begin() + k-1, RCL.end(),
            [](const auto& a, const auto& b) {return a.first > b.first;});
        RCL.resize(k);
    }
}

int Knapsack::eleccion_de_item_aleatorio(const vector<pair<double, int>> &RCL, mt19937_64 rng) {
    uniform_int_distribution<> dist(0, RCL.size() - 1);
    int elegido = RCL[dist(rng)].second;
    return elegido;
}

void Knapsack::retirar_elegido_de_los_no_elegidos(int elegido, vector<int> &no_elegidos) {
    auto it = find(no_elegidos.begin(), no_elegidos.end(), elegido);
    if (it != no_elegidos.end()) {
        no_elegidos.erase(it);
    }
}

void Knapsack::mejorar(SolucionCandidata &solucionCandidata) {
}

void Knapsack::retornar() {
}
