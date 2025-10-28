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
    this->beneficio = -1;
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

        double smin, smax;
        vector<pair<double, int>> puntajes = this-> construir_puntajes_de_candidatos(candidatos, smin, smax);
        vector<pair<double, int>> RCL = this->formacion_de_la_RCL(puntajes, smin, smax);
        int elegido = this->eleccion_de_item_aleatorio(RCL, rng);
        solucionCandidata.incluir(elegido, this->articulos[elegido].get_peso(), this->articulos[elegido].get_beneficio());
        this->retirar_elegido_de_los_no_elegidos(elegido, no_elegidos);
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
    //TODO: probar el push
    //candidatos.resize(no_elegidos.size());
    for (int id: no_elegidos) {
        if (solucionCandidata.get_peso()+this->articulos[id].get_peso() <= this->capacidad) {
            candidatos.push_back(id);
        }
    }
    return candidatos;
}

bool Knapsack::hacer_intercambio_1_1(SolucionCandidata &solucion_candidata) {
    int n = this->articulos.size();
    long long beneficio = solucion_candidata.get_beneficio();
    int peso = solucion_candidata.get_peso();
    vector<bool> tomar = solucion_candidata.get_tomar();

    for (int p=0; p<n; p++) {
        if (tomar[p]) {
            for (int q=0; q<n; q++) {
                if (!tomar[q]) {
                    long long nuevo_peso = peso - this->articulos[p].get_peso() + this->articulos[q].get_peso();
                    if (nuevo_peso <= this->capacidad) {
                        long long delta_beneficio = this->articulos[q].get_beneficio()-this->articulos[p].get_beneficio();
                        if (delta_beneficio>0) {
                            tomar[p] = false;
                            tomar[q] = true;
                            solucion_candidata.set_peso(nuevo_peso);
                            solucion_candidata.set_beneficio(beneficio + delta_beneficio);
                            solucion_candidata.set_tomar(tomar);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Knapsack::hacer_intercambio_1_2(SolucionCandidata &solucion_candidata) {
    int n = this->articulos.size();
    long long beneficio = solucion_candidata.get_beneficio();
    int peso = solucion_candidata.get_peso();
    vector<bool> tomar = solucion_candidata.get_tomar();

    for (int p=0; p<n; p++) {
        if (tomar[p]) {
            for (int q=0; q<n; q++) {
                if (!tomar[q]) {
                    for (int r=q+1; r<n; r++) {
                        if (!tomar[r]) {
                            long long nuevo_peso = peso - this->articulos[p].get_peso()+this->articulos[q].get_peso()+this->articulos[r].get_peso();
                            if (nuevo_peso <= this->capacidad) {
                                long long delta_beneficio = this->articulos[q].get_beneficio()+this->articulos[r].get_beneficio()-this->articulos[p].get_beneficio();
                                if (delta_beneficio>0) {
                                    tomar[p] = false;
                                    tomar[q] = true;
                                    tomar[r] = true;
                                    solucion_candidata.set_peso(nuevo_peso);
                                    solucion_candidata.set_beneficio(beneficio + delta_beneficio);
                                    solucion_candidata.set_tomar(tomar);
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Knapsack::se_puede_mejorar(SolucionCandidata &solucion_candidata) {
    if (this->hacer_intercambio_1_1(solucion_candidata))
        return true;
    if (this->hacer_intercambio_1_2(solucion_candidata))
        return true;
    return false;
}

void Knapsack::busqueda_local(SolucionCandidata &solucion_candidata) {
    while (this->se_puede_mejorar(solucion_candidata)) {
        //seguir intentando la mejora
    }
}

void Knapsack::mejorar(SolucionCandidata &solucionCandidata) {
    this->busqueda_local(solucionCandidata);
    if (solucionCandidata.get_beneficio() > this->beneficio) {
        this->beneficio = solucionCandidata.get_beneficio();
        this->peso = solucionCandidata.get_peso();
        this->tomar = solucionCandidata.get_tomar();
    }
}

void Knapsack::retornar() {
    cout << "====================================" << endl;
    cout << "Mejor beneficio:" << this->beneficio << endl;
    cout << "Peso total: " << this->peso << "/ Capacidad " << this->capacidad<< endl;
    cout << "Artículos tomados: id: (peso, beneficio): " << endl;
    for (int i=0; i<this->articulos.size(); i++) {
        if (this->tomar[i]) {
            cout << this->articulos[i].get_id() << ":(" <<
                this->articulos[i].get_peso() <<"," <<
                this->articulos[i].get_beneficio() << ")"  << endl;
        }
    }
    cout << endl;
}

void Knapsack::resetar_solucion_final() {
    this->tomar.assign(this->articulos.size(), false);
    this->beneficio = 0;
    this->peso = 0;
}

vector<pair<double, int>> Knapsack::construir_puntajes_de_candidatos(const vector<int> &candidatos, double &smin,
    double &smax) {
    vector<pair<double, int>> puntajes;
    smin = numeric_limits<double>::infinity();
    smax = -numeric_limits<double>::infinity();
    for (int id: candidatos) {
        double razon = (double)this->articulos[id].get_beneficio()/this->articulos[id].get_peso();
        double p = this->tau*razon + (1.0 - this->tau)*this->articulos[id].get_beneficio();
        smin = min(smin, p);
        smax = max(smax, p);
        puntajes.emplace_back(p, id);
    }
    return puntajes;
}

vector<pair<double, int>> Knapsack::formacion_de_la_RCL(const vector<pair<double, int>> &puntajes, double smin,
                                                        double smax) {
    vector<pair<double, int>> RCL;
    this->formacion_de_la_RCL_por_umbral(RCL, puntajes, smin, smax);
    this->formacion_de_la_RCL_por_cardinalidad(RCL);
    return RCL;
}

int Knapsack::eleccion_de_item_aleatorio(const vector<pair<double, int>> &RCL, mt19937_64 rng) {
    //se escoge un número al azar
    uniform_int_distribution<int> dist(0, RCL.size()-1);
    int elegido = RCL[dist(rng)].second;
    return elegido;
}

void Knapsack::retirar_elegido_de_los_no_elegidos(int elegido, vector<int> &no_elegidos) {
    auto it=find(no_elegidos.begin(), no_elegidos.end(), elegido);
    if (it != no_elegidos.end()) {
        no_elegidos.erase(it);
    }
}

void Knapsack::formacion_de_la_RCL_por_umbral(vector<pair<double, int>> &RCL,
                                              const vector<pair<double, int>> &puntajes, double smin, double smax) {
    if (this->alpha <=0.0) {
        double umbral = smax;
        for (auto &puntaje: puntajes) {
            if (puntaje.first>= umbral)
                RCL.push_back(puntaje);
        }
    } else if (alpha >= 1.0) {
        for (auto &puntaje: puntajes) {
            RCL.push_back(puntaje);
        }
    } else {
        double umbral = smax - this->alpha*(smax-smin);
        for (auto &puntaje: puntajes) {
            if (puntaje.first>= umbral)
                RCL.push_back(puntaje);
        }
    }
}

void Knapsack::formacion_de_la_RCL_por_cardinalidad(vector<pair<double, int>> &RCL) {
    int k = this->beta > 0? min(this->beta, (int)RCL.size()): RCL.size();
    if (RCL.size()>k) {
        nth_element(RCL.begin(), RCL.begin()+(k-1), RCL.end(),
            [] (const auto&a, const auto&b) { return a.first > b.first; }
        );
        RCL.resize(k);
    }
}
