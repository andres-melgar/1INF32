#ifndef KNAPSACK_CASOSPRUEBA_H
#define KNAPSACK_CASOSPRUEBA_H
#include <vector>
#include "Articulo.h"
#define CASO_A_1 1
#define CASO_A_2 2
#define CASO_A_3 3
#define CASO_B_1 4
#define CASO_B_2 5
#define CASO_B_3 6
#define CASO_C_1 7
#define CASO_C_2 8
#define CASO_C_3 9
#define CASO_D_1 10
#define CASO_D_2 11
#define CASO_D_3 12
#define CASO_D_4 13
#define CASO_D_5 14
#define CASO_D_6 15

using namespace std;

class CasosPrueba {
private:
    vector<Articulo> articulos;
    long long capacidad;
    double alpha;
    int beta;
    double tau;
    int iteraciones;
public:
    CasosPrueba(int caso);

    void ejecutar();
private:
    void cargar_articulos_caso_A();

    void cargar_articulos_caso_B();

    void cargar_articulos_caso_C();

    void cargar_articulos_caso_D();

    void cargar_parametros_GRASP_1();

    void cargar_parametros_GRASP_2();

    void cargar_parametros_GRASP_3();

    void cargar_iteraciones_1();

    void cargar_iteraciones_2();

    void cargar_iteraciones_3();
};


#endif //KNAPSACK_CASOSPRUEBA_H