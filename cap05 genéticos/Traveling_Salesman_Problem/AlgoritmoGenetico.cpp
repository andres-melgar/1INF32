#include "AlgoritmoGenetico.h"

#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <ranges>

using namespace std;

AlgoritmoGenetico::AlgoritmoGenetico(int num_generaciones, double tasa_mutacion, vector<vector<int>> distancias) {
    this->num_generaciones = num_generaciones;
    this->tasa_mutacion = tasa_mutacion;
    this->tsp = TSP(distancias);
}

Cromosoma AlgoritmoGenetico::ejecutar(int tamaño_ploblacion) {
    this->generar_poblacion_inicial(tamaño_ploblacion);
    Cromosoma mejor = this->poblacion[0];
    for (int generacion = 0; generacion < this->num_generaciones; generacion++) {
        vector<Cromosoma> nueva_poblacion;
        for (int i=0; i<tamaño_ploblacion; i++) {
            Cromosoma padre = this->seleccionar();
            Cromosoma madre = this->seleccionar();
            Cromosoma hijo = this->casamiento(padre, madre);
            hijo.mutacion(this->tasa_mutacion);
            hijo.set_costo(this->tsp.costo_tour(hijo.get_tour()));
            nueva_poblacion.push_back(hijo);

            if (hijo.get_costo()< mejor.get_costo())
                mejor = hijo;
        }
        this->poblacion = nueva_poblacion;
    }
    return mejor;
}

void AlgoritmoGenetico::generar_poblacion_inicial(int tamaño_ploblacion) {
    int n = tsp.get_n();
    vector<int> base(n);
    // base [0,1,2,3,...,n-1]
    //for (int i=0; i<n ; i++)
    //  base[i] = i;
    iota(base.begin(), base.end(), 0);

    this->poblacion.clear();
    for (int i= 0; i<tamaño_ploblacion; i++) {
        random_shuffle(base.begin(), base.end()); //desordena el arreglo base
        Cromosoma cromosoma(base);
        cromosoma.set_costo(this->tsp.costo_tour(cromosoma.get_tour()));
        poblacion.push_back(cromosoma);
    }
}

Cromosoma AlgoritmoGenetico::seleccionar() {
    int i = rand()%this->poblacion.size();
    int j = rand()%this->poblacion.size();
    return this->poblacion[i].get_costo()<this->poblacion[j].get_costo()?
        this->poblacion[i] :
        this->poblacion[j];
}

Cromosoma AlgoritmoGenetico::casamiento(Cromosoma &padre, Cromosoma &madre) {
    int n = this->tsp.get_n();
    int a = rand() % n;
    int b = rand() % n;
    if (a>b)
        swap(a, b);

    vector<int> p1 = madre.get_tour();
    vector<int> p2 = padre.get_tour();
    vector<int> hijo(n, -1);

    for (int i=a; i<=b; i++)
        hijo[i] = p1[i];

    for (int i=0; i<n; i++) {
        if (i>=a && i<=b)
            continue;

        int ciudad = p2[i];
        if (find(hijo.begin(), hijo.end(), ciudad) == hijo.end()) {
            hijo[i] = ciudad;
            continue;
        }


    }
}
