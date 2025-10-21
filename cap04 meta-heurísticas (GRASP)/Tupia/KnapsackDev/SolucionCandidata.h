#ifndef KNAPSACK_SOLUCIONCANDIDATA_H
#define KNAPSACK_SOLUCIONCANDIDATA_H
#include <vector>

using namespace std;

class SolucionCandidata {
private:
    vector<bool> tomar;
    long long beneficio = 0;
    long long peso = 0;
public:
    SolucionCandidata(int n);

    void incluir(int id, int peso_id, long long beneficio_id);

    void excluir(int id, int peso_id, long long beneficio_id);

    void resetear(int n);

    vector<bool> get_tomar() const;

    void set_tomar(const vector<bool> &tomar);

    long long get_beneficio() const;

    void set_beneficio(long long beneficio);

    long long get_peso() const;

    void set_peso(long long peso);
};

#endif //KNAPSACK_SOLUCIONCANDIDATA_H