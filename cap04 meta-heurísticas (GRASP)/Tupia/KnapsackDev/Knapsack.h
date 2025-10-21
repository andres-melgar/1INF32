#ifndef KNAPSACK_KNAPSACK_H
#define KNAPSACK_KNAPSACK_H
#include <random>
#include <vector>

#include "Articulo.h"
#include "SolucionCandidata.h"

using namespace std;

class Knapsack {
private:
    // Datos de la instancia
    vector<Articulo> articulos;
    long long capacidad;

    // Parámetros GRASP
    double alpha;    // umbral por valor (0: solo el mejor, 1: todos los factibles)
    int beta;      // top-k después de filtrar por alpha (<=0 => sin límite)
    double tau;    // puntaje: tau*(v/w) + (1-tau)*v
    int iteraciones;

    // Solución final
    vector<bool> tomar;
    long long beneficio;
    long long peso;
public:
    Knapsack(const vector<Articulo>& articulos, long long capacidad, double alpha, int beta, double tau, int iteraciones);

    void GRASP();
private:
    void resetar_solucion_final();

    SolucionCandidata construir(mt19937_64 rng);

    vector<int> construir_candidatos_no_elegidos(int n);

    vector<int> construir_candidatos_factibles(const SolucionCandidata &solucionCandidata, const vector<int> &no_elegidos);

    vector<pair<double, int>> construir_puntajes_de_candidatos(const vector<int> &candidatos, double &smin, double &smax);

    vector<pair<double, int>> formacion_de_la_RCL(const vector<pair<double, int>> &puntajes, double smin, double smax);

    void formacion_de_la_RCL_por_umbral(vector<pair<double, int>> &RCL, const vector<pair<double, int>> &puntajes, double smin, double smax);

    void formacion_de_la_RCL_por_cardinalidad(vector<pair<double, int>> &RCL);

    int eleccion_de_item_aleatorio(const vector<pair<double, int>> &RCL, mt19937_64 rng);

    void retirar_elegido_de_los_no_elegidos(int elegido, vector<int> & vector);

    void mejorar(SolucionCandidata &solucionCandidata);

    void retornar();
};

#endif //KNAPSACK_KNAPSACK_H