#include <iostream>
#include <vector>
#include <algorithm>
#include "ActivitySelection.h"

using namespace std;

ActivitySelection::ActivitySelection() {
    this->inicializar_actividades();
}

//cada par indica: <inicio, fin> de una actividad
bool compararPorFin(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

vector<pair<int, int> > ActivitySelection::encontrar_solucion() {
    sort(this->actividades.begin(), this->actividades.end(), compararPorFin);
    vector<pair<int, int> > solucion;
    int tiempo_fin_ultima_actividad = 0;

    for (const auto &actividad: this->actividades) {
        if (actividad.first >= tiempo_fin_ultima_actividad) {
            solucion.push_back(actividad);
            tiempo_fin_ultima_actividad = actividad.second;
        }
    }
    return solucion;
}

void ActivitySelection::inicializar_actividades() {
    //cada par indica: <inicio, fin> de una actividad
    //this->actividades = {
    //    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    //};

    this->actividades = {
        {0, 6}, {8, 9}, {5, 7}, {1, 4}, {5, 9}, {3, 5}
    };
}
