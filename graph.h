#pragma once
#include <vector>
#include <iostream>
using namespace std;
using AdjList = vector<vector<int>>;

void loadGraph(const size_t& n, const size_t& m, AdjList& mat) {

    /*
    n := number of nodes
    m := number of conexions in the whole mat
    */
    
    mat.assign(n, {}); // reinitiliazing the vector to n elements (subvectors)

    for (size_t i = 0; i < m; i++) { // read m conexions
        int u, v;
        cout << "\nIngresa el nodo u, y separado por un espacio en blanco, el nodo v al que apunta (u v): ";
        cin >> u >> v;

        // Verificamos que los nodos estén dentro del rango
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Arco ignorado: (" << u << ", " << v
                 << ") está fuera del rango [0, " << n - 1 << "]\n";
            continue;
        }

        mat[u].push_back(v); // adding a conexion to v from node u

    }
}

void printGraph(const size_t& n, const AdjList& mat) {
    for (size_t u = 0; u < n; u++) {
        cout << u + 1<< ": ";
        for (const int& v : mat[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
}

/*
 * Conditions a tree must seize
 * 1: graph must have n-1 arists; edgeCount = n-1
 * 2: just a vertex must have in-degree = 0 (0 fathers)
 * 3: the rest of vertex must have in-degree = 1 (one father)
 * 4: graph must be fully conected without falling in cycling
 *      from root we must reach all nodes
 *      there must not be a way to go back once we reallocate into a child node
 */
bool isTree(const size_t& n, const AdjList& mat) {

    // ====== Trivial case ======
    if (n <= 0) return false;

    // ====== calculating in-degree and number of arists
    vector<size_t> inDegree(n, 0); // inDegree[v] := numero de aristas (padres) que llegan a v
    size_t edgeCount = 0;          // total num of arists in the graph

    for (size_t u = 0; u < n; u++) {
        for (size_t v : mat[u]) {
            ++inDegree[v];                     // we sum one father v node
            if (inDegree[v] > 1) return false; // as node has more than 1 father, graph is not a tree
            ++edgeCount;                       // counting the arist u -> v
        }
    }

    // ====== n-1 arists condition ======
    if (edgeCount != n-1) return false;

    // ====== Finding the tree root ======
    int root = -1;
    for (size_t i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            if (root != -1) return false;  // another root was found before, hence, graph is not a tree
            root = static_cast<size_t>(i); // converting int value into a size_t value safely
        }
    }

    // ====== No root found ======
    if (root == -1) return false;

    // ====== DFS implementation to verify conectivity and cycles ======
    vector<bool> visited(n, false);    // visited[v] to check if every node is reachable from root
    vector<size_t> stack;            
    
    stack.push_back(root); // Init DFS from root
    visited[root] = true;
    size_t visitedCount = 0; // number of nodes reached and processed

    while(!stack.empty()) {
        size_t u = stack.back();
        stack.pop_back();
        ++visitedCount;

        for (size_t v : mat[u]) {
            if (visited[v]) return false; // ciclying routes, not a tree
            else visited[v] = true;
            stack.push_back(v);
        }
    }

    return visitedCount == n; // if the condition is true, true is to be returned
}
