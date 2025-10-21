#ifndef KNAPSACK_ARTICULO_H
#define KNAPSACK_ARTICULO_H

class Articulo {
private:
    int peso;
    long long beneficio;
    int id;
public:
    Articulo(int peso, long long beneficio, int id);

    int get_peso() const;

    void set_peso(int peso);

    long long get_beneficio() const;

    void set_beneficio(long long beneficio);

    int get_id() const;

    void set_id(int id);
};

#endif //KNAPSACK_ARTICULO_H
