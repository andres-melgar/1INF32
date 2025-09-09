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
    int n = this->monedas.size();
    if (n==0)
        return 0;
    if (n==1)
        return this->monedas[0];

    this->dp[0] = this->monedas[0];
    this->dp[1] = max(this->monedas[0], this->monedas[1]);

    for (int i =2; i < n; i++) {
        this->dp[i] = max(this->dp[i-1], this->dp[i-2] + this->monedas[i]);
    }
    return this->dp[n-1];
}

void CoinRow::imprimir_dp() {
    cout << "Tabla DP: ";
    for (int valor : dp) {
        cout << valor << " ";
    }
    cout << endl;
}