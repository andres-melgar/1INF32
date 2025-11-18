#include <iostream>
#include <vector>

#include "AlgoritmoGenetico.h"
#include "Trabajo.h"

using namespace std;

int main() {
    srand(time(nullptr));
    vector <Trabajo> trabajos = {
        Trabajo(1,4), Trabajo(2,3),
        Trabajo(3,2), Trabajo(4,6)
    };

    int num_maquinas = 2;
    AlgoritmoGenetico ag(1000, 0.05, num_maquinas);
    ag.set_trabajos(trabajos);
    int poblacion_inicial = 100;
    Programacion cromosoma = ag.ejecutar(poblacion_inicial);
    cromosoma.mostrar_programacion(trabajos);
    return 0;
}
