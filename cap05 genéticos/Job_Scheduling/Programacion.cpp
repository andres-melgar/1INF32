#include "Programacion.h"
#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;

Programacion::Programacion(int n) {
    this->n = n;
    this->asignaciones.assign(n, -1);
    this->makespan = 0;
}

void Programacion::calcular_makespan(const vector<Trabajo> &trabajo, int num_maquinas) {
    vector<int> maquinas(num_maquinas, 0);
    for (int i=0; i<this->asignaciones.size(); i++) {
        int id_maquina = this->asignaciones[i];
        maquinas[id_maquina] += trabajo[i].get_tiempo();
    }
    this->makespan = *max_element(maquinas.begin(), maquinas.end());
}

//otro nombre podría ser mostrar_cromosoma
void Programacion::mostrar_programacion(const vector<Trabajo> &trabajo) {
    cout << "Programacion (Trabajos asignados a la maquina): " << endl;
    for (int i=0; i<this->asignaciones.size(); i++) {
        cout << "Trabajo " << trabajo[i].get_id() << " -> Maquina " << this->asignaciones[i] << endl;
    }
    cout << "makespan: " << this->makespan << endl;
}

void Programacion::set_asignacion(int indice, int valor) {
    this->asignaciones[indice] = valor;
}

int Programacion::get_asignacion(int indice) {
    return this->asignaciones[indice];
}

int Programacion::get_n() {
    return this->n;
}

int Programacion::get_makespan() {
    return this->makespan;
}
