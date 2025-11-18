#ifndef TRAVELING_SALESMAN_PROBLEM_ALGORITMOGENERICO_H
#define TRAVELING_SALESMAN_PROBLEM_ALGORITMOGENERICO_H
#include "Cromosoma.h"
#include "TSP.h"

class AlgoritmoGenetico {
private:
    int num_generaciones;
    double tasa_mutacion;
    TSP tsp;

    vector<Cromosoma> poblacion;
public:
    AlgoritmoGenetico(int num_generaciones, double tasa_mutacion, vector<vector<int>> distancias);

    Cromosoma ejecutar(int tamaño_ploblacion);
private:
    void generar_poblacion_inicial(int tamaño_ploblacion);

    Cromosoma seleccionar();

    Cromosoma casamiento(Cromosoma & padre, Cromosoma & madre);
};


#endif //TRAVELING_SALESMAN_PROBLEM_ALGORITMOGENERICO_H