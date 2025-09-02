#include "Hangover.h"

using namespace std;

Hangover::Hangover() {
    this->inicializar_arreglo();
}

int Hangover::retorna_distancia(double n) {
    for (int i = 0; i < this->dp.size(); i++) {
        if (this->dp[i] >= n) {
            return i+1;
        }
    }
    return 0;
}

void Hangover::inicializar_arreglo() {
    this->dp.resize(300, 0);
    this->dp[0] = 0.5;
    for (int i = 1; i < 300; i++) {
        this->dp[i] = this->dp[i - 1] + (double) 1 / (i + 2);
    }
}
