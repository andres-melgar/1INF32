#ifndef JOB_SCHEDULING_PROGRAMACION_H
#define JOB_SCHEDULING_PROGRAMACION_H
#include <vector>
#include "Trabajo.h"

using namespace std;

//Esta clase representa el cromosoma
class Programacion {
private:
    int n; //cantida de trabajos
    vector<int> asignaciones; //asignaciones a las máquinas
    int makespan;
public:
    Programacion(int n);

    void calcular_makespan(const vector<Trabajo> &trabajo, int num_maquinas);

    void mostrar_programacion(const vector<Trabajo> &trabajo);

    void set_asignacion(int indice, int valor);

    int get_asignacion(int indice);

    int get_n();

    int get_makespan();
};


#endif //JOB_SCHEDULING_PROGRAMACION_H