#include <iostream>
#include <vector>
#include <algorithm>
#include "CoinChange.h"

using namespace std;

CoinChange::CoinChange(vector<int> denominaciones, int valor) {
    this->denominaciones = denominaciones;
    this->valor = valor;
}

void CoinChange::encontrar_solucion() {
    int cantidad_total = 0;
    vector<int> solucion(this->denominaciones.size(), 0);

    cout << "Cambio para el valor " << this->valor << endl;

    sort(this->denominaciones.rbegin(), this->denominaciones.rend());
    for (int i = 0; i < this->denominaciones.size(); i++) {
        int moneda = this->denominaciones[i];
        //estrategia voraz
        int cantidad = this->valor / moneda;
        if (cantidad > 0) {
            solucion[i] = cantidad;
            valor -= cantidad * moneda;
            cantidad_total += cantidad;
        }
    }

    if (valor > 0)
        cout << "No es posible dar el cambio exacto con las denominaciones posibles" << endl;
    cout << "Total de monedas usadas: " << cantidad_total << endl;
    cout << "Monedas usadas: ";
    bool bandera_coma = false;
    for (int i = 0; i < solucion.size(); i++) {
        if (solucion[i] > 0) {
            if (bandera_coma)
                cout << ", ";
            cout << this->denominaciones[i] << "x" << solucion[i];
            bandera_coma = true;
        }
    }
    cout << endl << endl;
}
