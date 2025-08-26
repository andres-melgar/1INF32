#include "Knapsack.h"

Knapsack::Knapsack() {
    this->capacidad = 5;
    this->inicializar_items();
}

int Knapsack::encontrar_solucion() {
    //TODO
    return 0;
}

void Knapsack::inicializar_items() {
    this->items = {
        {2, 12},
        {1, 10},
        {3, 20},
        {2, 15}
    };
}
