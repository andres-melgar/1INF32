#include <iostream>
#include "Knapsack.h"

using namespace std;

int main() {
    Knapsack knapsack;
    int valorMaximo = knapsack.encontrar_solucion();
    cout << "Valor máximo que se puede obtener: " << valorMaximo << endl;
    return 0;
}
