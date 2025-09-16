#include <iostream>
#include <vector>
#include "ActivitySelection.h"

using namespace std;

int main() {
    ActivitySelection activitySelection;

    vector<pair<int, int>> resultado = activitySelection.encontrar_solucion();

    cout << "Actividades seleccionadas (inicio, fin):" << endl;;
    for (const auto &actividad : resultado) {
        cout << "(" << actividad.first << ", " << actividad.second << ")\n";
    }
    return 0;
}
