
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>

using namespace std;

class Grafo {
private:
    int numero_vertices; // número de vértices
    vector<vector<pair<int, int>>> lista_adyacencia; // lista de adyacencia: (vecino, peso)
    vector<int> ruta;
public:
    Grafo(int numero_vertices);

    void agregarArista(int u, int v, int peso);

    void dijkstra(int origen);

    void imprime_grafo();

    void imprime_ruta_mas_corta(int final);

private:
    void imprimir_camino(int destino);

    void imprime_costo(const vector<int> & costo);

    void imprime_visitados(const priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> & visitados);

    void imprime_distancias_mininas(int origen, const vector<int> & costo);
};



#endif //GRAFO_H
