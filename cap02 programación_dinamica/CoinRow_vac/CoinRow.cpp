#include <iostream>
#include "CoinRow.h"

using namespace std;

CoinRow::CoinRow() {
    this->inicializar_monedas();
}

void CoinRow::inicializar_monedas() {
    this->monedas = {5, 1, 2, 10, 6, 2};
    this->dp.resize(this->monedas.size(), 0);
}

int CoinRow::encontrar_solucion() {
    //TODO
    return 0;
}

void CoinRow::imprimir_dp() {
    cout << "Tabla DP: ";
    for (int valor : dp) {
        cout << valor << " ";
    }
    cout << endl;
}