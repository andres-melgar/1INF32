//
//

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>

using namespace std;

class Knapsack {
private:
    int capacidad;
    //par de peso, valor. El peso debe ser entero pues será un índice
    vector<pair<int, double>> items;
public:
    Knapsack();

    int encontrar_solucion();
private:
    void inicializar_items();
};


#endif //KNAPSACK_H
