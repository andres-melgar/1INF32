#include <iostream>

#include "Grafo.h"

int main() {
    /*
    //este grafo es dirigido. corregir código al probar
    int numero_vertices = 5;
    Grafo g(numero_vertices);
    g.agregarArista(0, 1, 4); // A-B
    g.agregarArista(0, 2, 2); // A-C
    g.agregarArista(1, 2, 1); // B-C
    g.agregarArista(1, 3, 5); // B-D
    g.agregarArista(2, 3, 8); // C-D
    g.agregarArista(2, 4, 10); // C-E
    g.agregarArista(3, 4, 2); // D-E*/

    /*
     *int numero_vertices = 5;
    Grafo g(numero_vertices);
    g.agregarArista(0, 1, 50);
    g.agregarArista(0, 2, 30);
    g.agregarArista(0, 3, 100);
    g.agregarArista(0, 4, 10);
    g.agregarArista(2, 1, 5);
    g.agregarArista(2, 3, 50);
    g.agregarArista(3, 1, 20);
    g.agregarArista(4, 3, 10);

    g.imprime_grafo();

    int origen = 0, final = 3;
    g.dijkstra(origen);
    g.imprime_ruta_mas_corta(final);
    */

    int numero_vertices = 5;
    Grafo g(numero_vertices);
    g.agregarArista(0, 1, 10);
    g.agregarArista(0, 3, 30);
    g.agregarArista(0, 4, 100);
    g.agregarArista(1, 2, 50);
    g.agregarArista(2, 4, 10);
    g.agregarArista(3, 2, 20);
    g.agregarArista(3, 4, 60);

    g.imprime_grafo();

    /*int origen = 0, final = 4;
    g.dijkstra(origen);
    g.imprime_ruta_mas_corta(final);
    */
    return 0;
}
