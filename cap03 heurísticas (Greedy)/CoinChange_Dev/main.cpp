#include <iostream>

#include "CoinChange.h"

int main() {
    vector<int> denominaciones = {25, 10, 5, 1};
    int valor = 63;
    CoinChange coinChange(denominaciones, valor);
    coinChange.encontrar_solucion();

    denominaciones = {10, 6, 1};
    valor = 12;
    coinChange = CoinChange(denominaciones, valor);
    coinChange.encontrar_solucion();

    denominaciones = {200, 1, 2, 20, 5, 50, 10, 100};
    valor = 93;
    coinChange = CoinChange(denominaciones, valor);
    coinChange.encontrar_solucion();

    return 0;
}
