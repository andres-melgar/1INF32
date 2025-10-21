#include "Articulo.h"

Articulo::Articulo(int peso, long long beneficio, int id) {
    this->peso = peso;
    this->beneficio = beneficio;
    this->id = id;
}

int Articulo::get_peso() const {
    return peso;
}

void Articulo::set_peso(int peso) {
    this->peso = peso;
}

long long Articulo::get_beneficio() const {
    return beneficio;
}

void Articulo::set_beneficio(long long beneficio) {
    this->beneficio = beneficio;
}

int Articulo::get_id() const {
    return id;
}

void Articulo::set_id(int id) {
    this->id = id;
}
