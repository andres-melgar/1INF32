#ifndef COINCHANGE_H
#define COINCHANGE_H

#include <vector>

using namespace std;

class CoinChange {
private:
    vector<int> denominaciones;
    int valor;
public:
    CoinChange(vector<int> denominaciones, int valor);

    void encontrar_solucion();
};



#endif //COINCHANGE_H
