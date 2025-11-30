#include "graph.h"

int main() {
    
    size_t n, m;
    cout << "Ingresa el numero de vertices y arcos separados por un espacio en blanco \n";
    cout << "Recuerda seguir el siguiente formato (a b): ";
    
    // inputs for n must be any real number, m must be equal to n-1
    cin >> n >> m;
    AdjList mat;
    
    /*
    inputs in the loadGraph function that returns true
    0 1
    0 2
    2 3
    2 4*/
    loadGraph(n, m, mat);
    isTree ? cout << "true" : cout << "false";

}