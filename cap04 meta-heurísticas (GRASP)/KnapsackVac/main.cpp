#include <iostream>
#include "CasosPrueba.h"

void test(int caso);

int main() {
    cout << "Caso A-1"<<endl;
    CasosPrueba casos(CASO_A_1);
    casos.ejecutar();

    cout << "Caso A-2"<<endl;
    casos = CasosPrueba (CASO_A_2);
    casos.ejecutar();

    cout << "Caso A-3"<<endl;
    casos = CasosPrueba (CASO_A_3);
    casos.ejecutar();

    cout << "Caso B-1"<<endl;
    casos = CasosPrueba (CASO_B_1);
    casos.ejecutar();

    cout << "Caso C-1"<<endl;
    casos = CasosPrueba (CASO_C_1);
    casos.ejecutar();

    cout << "Caso D-1"<<endl;
    test(CASO_D_1);

    cout << "Caso D-2"<<endl;
    test(CASO_D_2);

    cout << "Caso D-3"<<endl;
    test(CASO_D_3);

    cout << "Caso D-4"<<endl;
    test(CASO_D_4);

    cout << "Caso D-5"<<endl;
    test(CASO_D_5);
    return 0;
}

void test(int caso) {
    CasosPrueba casos = CasosPrueba (caso);
    casos.ejecutar();
}