#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <limits>
#include "Grafo.h"

using namespace std;

Grafo::Grafo(int numero_vertices) {
    this->numero_vertices = numero_vertices;
    this->lista_adyacencia.resize(this->numero_vertices);
}

void Grafo::agregarArista(int u, int v, int peso) {
    this->lista_adyacencia[u].emplace_back(v, peso);
}

void Grafo::imprime_costo(const vector<int> &costo) {
    cout << "[";
    for (int valor: costo) {
        if (valor == numeric_limits<int>::max())
            cout << " INF ";
        else
            cout << fixed << setw(5) << valor;
    }
    cout << "] ";
}

void Grafo::imprime_por_visitar(const priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > &visitados) {
    cout << "{";
    auto copia = visitados;
    bool mostrar_coma = false;
    while (!copia.empty()) {
        if (mostrar_coma)
            cout << ", ";
        auto [dist, nodo] = copia.top();
        cout << " {";
        cout << nodo << ", " << dist;
        cout << " }";
        mostrar_coma = true;
        copia.pop();
    }
    cout << " }" << endl;
}

void Grafo::imprime_distancias_minimas(int origen, const vector<int> &costo) {
    cout << "Distancias mínimas desde el nodo " << char('A'+origen) << endl;
    for (int i = 0; i < this->numero_vertices; ++i) {
        cout << "Nodo " << char('A' + i) << ": " << costo[i] << " | Camino: ";
        imprimir_camino(i);
        cout << endl;
    }
}

void Grafo::dijkstra(int origen) {
    cout << "Algoritmo Dijkstra: " << endl;
    vector<int> costo(this->numero_vertices, numeric_limits<int>::max());
    this->ruta.resize(this->numero_vertices, -1);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<> > por_visitar;

    costo[origen] = 0;
    por_visitar.emplace(0, origen);

    while (!por_visitar.empty()){
        int distancia_actual = por_visitar.top().first;
        int u = por_visitar.top().second;
        por_visitar.pop();

        this->imprime_costo(costo);
        cout << "COLA: " << u << "}";
        this->imprime_por_visitar(por_visitar);
        if (distancia_actual>costo[u])
            continue;
        for(auto &[v,peso]: this->lista_adyacencia[u]){
            if (costo[u] + peso < costo[v]){
                costo[v] = costo[u] + peso;
                this->ruta[v] = u;
                por_visitar.emplace(costo[v], v);
            }
        }
    }
    this->imprime_distancias_minimas(origen, costo);
}

void Grafo::imprime_grafo() {
    cout << "Grafo: " << endl;
    for (int u = 0; u < lista_adyacencia.size(); u++) {
        cout << "[" << char('A' + u) << "] ";
        for (const auto &[v, peso]: lista_adyacencia[u]) {
            cout << char('A' + v) << "(" << peso << ") ";
        }
        cout << endl;
    }
}

void Grafo::imprime_ruta_mas_corta(int final) {
    cout << "Ruta más corta hasta (inversa): " << char('A' + final) << endl;
    do {
        cout << char('A' + final) << "->";
        int indice = final;
        final = this->ruta[indice];
    } while (final != 0);
    cout << char('A' + final) << endl;
}

void Grafo::imprimir_camino(int destino) {
    if (ruta[destino] != -1) {
        this->imprimir_camino(this->ruta[destino]);
        cout << "->";
    }
    cout << char('A' + destino);
}
