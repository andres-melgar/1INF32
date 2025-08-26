#include <iostream>
#include "WordSearch.h"

using namespace std;

int main() {
    WordSearch wordSearch;
    wordSearch.mostrar_tablero();
    cout << "¿Existe 'ABCCED'? " << wordSearch.encontrar_solucion("ABCCED") << endl; // true

    wordSearch.inicializar_tablero();
    cout << "¿Existe 'SEE'? " << wordSearch.encontrar_solucion("SEE") << endl;       // true

    wordSearch.inicializar_tablero();
    cout << "¿Existe 'ABCB'? " << wordSearch.encontrar_solucion("ABCB") << endl;     // false

    wordSearch.inicializar_tablero();
    cout << "¿Existe 'SAD'? " << wordSearch.encontrar_solucion("SAD") << endl;     // true
    return 0;
}
