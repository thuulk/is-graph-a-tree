#include "graph.h"

int main() {
    
    int n, m;
    cout << "Ingresa el numero de vertices y arcos separados por un espacio en blanco \n";
    cout << "Recuerda seguir el siguiente formato (a b): ";
    cin >> n >> m;
    AdjMatrix mat;
    loadGraph(n, m, mat);
    printGraph(n, mat);

}