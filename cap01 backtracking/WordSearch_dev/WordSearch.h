#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <vector>
#include <list>
#define VISITADO '#'

using namespace std;

class WordSearch {
private:
    vector<vector<char>> tablero;
    list<pair<int, int>> movimientos;
public:
    WordSearch();

    void mostrar_tablero() const;

    void inicializar_tablero();

    bool buscar_palabra(const string & palabra, int fil, int col, int indice);

    bool encontrar_solucion(string palabra);
private:
    void cargar_lista_movimientos();
};

#endif //WORDSEARCH_H
