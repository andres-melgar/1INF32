#include "AlgoritmoGenetico.h"

#include <cstdlib>

AlgoritmoGenetico::AlgoritmoGenetico(int num_generaciones, double tasa_mutacion, int num_maquinas) {
    this->num_generaciones = num_generaciones;
    this->tasa_mutacion = tasa_mutacion;
    this->num_maquinas = num_maquinas;
}

Programacion AlgoritmoGenetico::ejecutar(int tamaño_poblacion) {
    this->generar_poblacion_inicial(tamaño_poblacion);
    Programacion mejor_solucion = this->poblacion[0];

    for (int generacion=0; generacion<this->num_generaciones; generacion++) {
        //crear de nueva poblacion
        vector<Programacion> nueva_poblacion;
        while (nueva_poblacion.size() <= this->poblacion.size()) {
            Programacion padre = this->seleccionar();
            Programacion madre = this->seleccionar();
            Programacion hijo = this->casamiento(madre, padre);
            this->mutacion(hijo);
            hijo.calcular_makespan(this->trabajos, this->num_maquinas);
            nueva_poblacion.push_back(hijo);
        }
        this->poblacion = nueva_poblacion;

        for (Programacion &p: this->poblacion) {
            if (this->fitness(p) < this->fitness(mejor_solucion)) {
                mejor_solucion = p;
            }
        }
    }
    return mejor_solucion;
}

void AlgoritmoGenetico::set_trabajos(vector<Trabajo> trabajos) {
    this->trabajos = trabajos;
}

void AlgoritmoGenetico::generar_poblacion_inicial(int tamaño_poblacion) {
    this->poblacion.clear();
    for (int i=0; i<tamaño_poblacion; i++) {
        Programacion p(this->trabajos.size());
        for (int j=0; j<this->trabajos.size(); j++) {
            //rand()%n --> genera un número pseudoaleatorio entre
            // [0..n-1]
            p.set_asignacion(j, rand()%this->num_maquinas);
        }
        p.calcular_makespan(this->trabajos, this->num_maquinas);
        this->poblacion.push_back(p);
    }
}

Programacion AlgoritmoGenetico::seleccionar() {
    int idx1 = rand()%this->poblacion.size();
    int idx2 = rand()%this->poblacion.size();
    return (this->fitness(this->poblacion[idx1]) < this->fitness(this->poblacion[idx2]) ? this->poblacion[idx1] : this->poblacion[idx2]);
}

Programacion AlgoritmoGenetico::casamiento (Programacion &madre, Programacion &padre) {
    Programacion hijo(madre.get_n());

    //se van a cruzar en un punto. ¿En qué punto?
    int punto_cruce = rand() % madre.get_n();
    for (int i=0; i<punto_cruce; i++)
        hijo.set_asignacion(i, madre.get_asignacion(i));
    for (int i=punto_cruce; i<padre.get_n(); i++)
        hijo.set_asignacion(i, padre.get_asignacion(i));
    return hijo;
}

void AlgoritmoGenetico::mutacion(Programacion &hijo) {
    double probabilidad = rand() / (double)RAND_MAX;
    if (probabilidad <= this->tasa_mutacion) {
        int idxTrabajo   = rand() % hijo.get_n();
        int idxMaquina = rand() % this->num_maquinas;
        hijo.set_asignacion(idxTrabajo, idxMaquina);
    }
}

int AlgoritmoGenetico::fitness(Programacion &programacion) {
    return programacion.get_makespan();
}
