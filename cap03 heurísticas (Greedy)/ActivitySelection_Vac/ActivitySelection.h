
#ifndef ACTIVITYSELECTION_H
#define ACTIVITYSELECTION_H

#include <vector>

using namespace std;

class ActivitySelection {
private:
    vector<pair<int, int>> actividades;
public:
    ActivitySelection();

    vector<pair<int, int>> encontrar_solucion();
private:
    void inicializar_actividades();
};


#endif //ACTIVITYSELECTION_H
