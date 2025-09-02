#include <iostream>
#include "Hangover.h"

using namespace std;

int main() {
    Hangover hangover;

    double n = 1.0;
    int num = hangover.retorna_distancia(n);
    cout << num << " carta(s)" << endl;

    n = 3.71;
    num = hangover.retorna_distancia(n);
    cout << num << " carta(s)" << endl;

    n = 0.04;
    num = hangover.retorna_distancia(n);
    cout << num << " carta(s)" << endl;

    n = 5.19;
    num = hangover.retorna_distancia(n);
    cout << num << " carta(s)" << endl;
    return 0;
}
