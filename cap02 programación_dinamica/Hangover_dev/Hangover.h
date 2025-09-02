#ifndef HANGOVER_H
#define HANGOVER_H

#include <vector>

using namespace std;

class Hangover {
private:
    vector<double> dp;
public:
    Hangover();

    int retorna_distancia(double n);
private:
    void inicializar_arreglo();
};



#endif //HANGOVER_H
