#ifndef JOB_SCHEDULING_ALGORITMOGENETICO_H
#define JOB_SCHEDULING_ALGORITMOGENETICO_H
#include <vector>

#include "Programacion.h"
#include "Trabajo.h"

using namespace std;

class AlgoritmoGenetico {
private:
    int num_generaciones;
    double tasa_mutacion;
    int num_maquinas;
    vector<Trabajo> trabajos;

    vector<Programacion> poblacion; //población de las soluciones
public:
    AlgoritmoGenetico(int num_generaciones, double tasa_mutacion, int num_maquinas);

    Programacion ejecutar(int tamaño_poblacion);
private:
    void generar_poblacion_inicial(int tamaño_poblacion);

    Programacion seleccionar();

    Programacion casamiento(Programacion &madre, Programacion &padre);

    void mutacion(Programacion &hijo);

    int fitness(Programacion &programacion);
};


#endif //JOB_SCHEDULING_ALGORITMOGENETICO_H