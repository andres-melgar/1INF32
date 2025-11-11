#include "Trabajo.h"

Trabajo::Trabajo(int id, int tiempo) {
    this->id = id;
    this->tiempo = tiempo;
}

int Trabajo::get_id() const {
    return id;
}

void Trabajo::set_id(int id) {
    this->id = id;
}

int Trabajo::get_tiempo() const {
    return tiempo;
}

void Trabajo::set_tiempo(int tiempo) {
    this->tiempo = tiempo;
}
