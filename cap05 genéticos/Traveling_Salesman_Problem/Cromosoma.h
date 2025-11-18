#ifndef TRAVELING_SALESMAN_PROBLEM_CROMOSOMA_H
#define TRAVELING_SALESMAN_PROBLEM_CROMOSOMA_H
#include <vector>

using namespace std;

class Cromosoma {
private:
    vector<int> tour;
    int costo;
public:
    Cromosoma(vector<int> tour, int costo=0);

    void imprimir();

    void mutacion(double probabilidad);

    vector<int> get_tour() const;

    void set_tour(const vector<int> &tour);

    int get_costo() const;

    void set_costo(int costo);
};

#endif //TRAVELING_SALESMAN_PROBLEM_CROMOSOMA_H