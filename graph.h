#pragma once
#include <vector>
#include <iostream>
using namespace std;
using AdjMatrix = vector<vector<int>>;

void loadGraph(const int& n, const int& m, AdjMatrix& mat) {

    /*
    n := number of nodes
    m := number of conexions in the whole mat
    */
    
    mat.assign(n, {}); // reinitiliazing the vector to n elements (subvectors)

    for (size_t i = 0; i < m; i++) { // read m conexions
        int u, v;
        cout << "\nIngresa el nodo u, y separado por un espacio en blanco, el nodo v al que apunta (u v): ";
        cin >> u >> v;

        mat[u].push_back(v); // adding a conexion to v from node u

    }
}

void printGraph(const int& n, const AdjMatrix& mat) {
    for (size_t u = 0; u < n; u++) {
        cout << u + 1<< ": ";
        for (const int& v : mat[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
}
