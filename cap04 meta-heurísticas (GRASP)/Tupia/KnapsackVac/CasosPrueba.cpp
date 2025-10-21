#include "CasosPrueba.h"
#include "Knapsack.h"

CasosPrueba::CasosPrueba(int caso) {
    switch (caso) {
        case CASO_A_1:
            this->cargar_articulos_caso_A();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_1();
            break;
        case CASO_A_2:
            this->cargar_articulos_caso_A();
            this->cargar_parametros_GRASP_2();
            this->cargar_iteraciones_1();
            break;
        case CASO_A_3:
            this->cargar_articulos_caso_A();
            this->cargar_parametros_GRASP_3();
            this->cargar_iteraciones_1();
            break;
        case CASO_B_1:
            this->cargar_articulos_caso_B();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_1();
            break;
        case CASO_C_1:
            this->cargar_articulos_caso_C();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_1();
            break;
        case CASO_D_1:
            this->cargar_articulos_caso_D();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_1();
            break;
        case CASO_D_2:
            this->cargar_articulos_caso_D();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_2();
            break;
        case CASO_D_3:
            this->cargar_articulos_caso_D();
            this->cargar_parametros_GRASP_1();
            this->cargar_iteraciones_3();
            break;
        case CASO_D_4:
            this->cargar_articulos_caso_D();
            this->cargar_parametros_GRASP_2();
            this->cargar_iteraciones_1();
            break;
        case CASO_D_5:
            this->cargar_articulos_caso_D();
            this->cargar_parametros_GRASP_3();
            this->cargar_iteraciones_1();
            break;
    }
}

void CasosPrueba::ejecutar() {
    Knapsack knapsack(this->articulos,
        this->capacidad,
        this->alpha,
        this->beta,
        this->tau,
        this->iteraciones);
    knapsack.GRASP();
}

void CasosPrueba::cargar_articulos_caso_A() {
    this->capacidad = 15;
    this->articulos = {
            {12,  4, 1},
            { 2,  2, 2},
            { 1,  1, 3},
            { 1,  2, 4},
            { 4, 10, 5},
            { 2,  2, 6}
    };
}

void CasosPrueba::cargar_articulos_caso_B() {
    this->capacidad = 100;
    this->articulos = {
            {10,  60,  1},
            {20, 100,  2},
            {30, 120,  3},
            {40, 240,  4},
            {50, 150,  5},
            { 5,  30,  6},
            {25,  90,  7},
            {35, 140,  8},
            {45, 200,  9},
            { 7,  28, 10}
    };
}

void CasosPrueba::cargar_articulos_caso_C() {
    this->capacidad = 25;
    this->articulos = {
           {5, 10, 1},
           {10, 20, 2},
           {15, 30, 3},
           {20, 40, 4}
    };
}

void CasosPrueba::cargar_articulos_caso_D() {
    this->capacidad = 50;
    this->articulos = {
        { 9,  20,  1}, {11,  26,  2}, {13,  29,  3}, {15,  35,  4},
        {16,  36,  5}, {17,  39,  6}, {19,  40,  7}, {21,  44,  8},
        { 5,  12,  9}, { 6,  13, 10}, { 7,  15, 11}, { 8,  17, 12},
        {10,  19, 13}, {12,  22, 14}
    };
}

void CasosPrueba::cargar_parametros_GRASP_1() {
    this->alpha = 0.2;
    this->beta = 3;
    this->tau = 0.7;
}

void CasosPrueba::cargar_parametros_GRASP_2() {
    this->alpha = 0.5;
    this->beta = 5;
    this->tau = 0.5;
}

void CasosPrueba::cargar_parametros_GRASP_3() {
    this->alpha = 0.8;
    this->beta = 7;
    this->tau = 0.3;
}

void CasosPrueba::cargar_iteraciones_1() {
    this->iteraciones = 10;
}

void CasosPrueba::cargar_iteraciones_2() {
    this->iteraciones = 500;
}

void CasosPrueba::cargar_iteraciones_3() {
    this->iteraciones = 1000;
}
