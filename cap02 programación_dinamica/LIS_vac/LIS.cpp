#include <algorithm>
#include "LIS.h"

LIS::LIS() {
    this->inicializar_secuencia();
}

int LIS::encontrar_solucion() {
    //TODO
    return 0;
}

void LIS::inicializar_secuencia() {
    this->secuencia = {10, 22, 9, 33, 21, 50, 41, 60};
    //this->secuencia = {-7,10,9,2,3,-8,8,1};
    this->dp.resize(this->secuencia.size(), 1);
}
