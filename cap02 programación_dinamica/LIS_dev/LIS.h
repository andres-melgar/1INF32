//
// Created by amelgar on 31/07/2025.
//

#ifndef LIS_H
#define LIS_H

#include <vector>

using namespace std;

class LIS {
private:
    vector<int> secuencia;
    vector<int> dp;
public:
    LIS();

    int encontrar_solucion();
private:
    void inicializar_secuencia();
};



#endif //LIS_H
