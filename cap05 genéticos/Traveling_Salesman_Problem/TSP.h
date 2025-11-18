#ifndef TRAVELING_SALESMAN_PROBLEM_TSP_H
#define TRAVELING_SALESMAN_PROBLEM_TSP_H
#include <vector>

using namespace std;

class TSP {
private:
    vector<vector<int>> distancias;
    int n;
public:
    TSP();

    TSP(vector<vector<int>> distancias);

    int costo_tour(const vector<int> &tour);

    vector<vector<int>> get_distancias() const;

    void set_distancias(const vector<vector<int>> &distancias);

    int get_n() const;

    void set_n(int n);
};


#endif //TRAVELING_SALESMAN_PROBLEM_TSP_H