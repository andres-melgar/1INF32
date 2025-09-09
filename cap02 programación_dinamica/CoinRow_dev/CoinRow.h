#ifndef COINROW_H
#define COINROW_H

#include <vector>

using namespace  std;

class CoinRow {
private:
    vector<int> monedas;
    vector<int> dp;
public:
    CoinRow();

    int encontrar_solucion();

    void imprimir_dp();
private:
    void inicializar_monedas();
};



#endif //COINROW_H
