#include "SolucionCandidata.h"

SolucionCandidata::SolucionCandidata(int n) {
    this->resetear(n);
}

void SolucionCandidata::incluir(int id, int peso_id, long long beneficio_id) {
    this->tomar[id] = true;
    this->peso += peso_id;
    this->beneficio += beneficio_id;
}

void SolucionCandidata::excluir(int id, int peso_id, long long beneficio_id) {
    this->tomar[id] = false;
    this->peso -= peso_id;
    this->beneficio -= beneficio_id;
}

void SolucionCandidata::resetear(int n) {
    this->tomar.assign(n, false);
    this->beneficio = 0;
    this->peso = 0;
}

vector<bool> SolucionCandidata::get_tomar() const {
    return tomar;
}

void SolucionCandidata::set_tomar(const vector<bool> &tomar) {
    this->tomar = tomar;
}

long long SolucionCandidata::get_beneficio() const {
    return beneficio;
}

void SolucionCandidata::set_beneficio(long long beneficio) {
    this->beneficio = beneficio;
}

long long SolucionCandidata::get_peso() const {
    return peso;
}

void SolucionCandidata::set_peso(long long peso) {
    this->peso = peso;
}
