

#include "../GraphHeadings/ListGraph.h"

// Konstruktor klasy ListGraph
ListGraph::ListGraph(int v, bool d) : Graph(v, d) {
    initializeList();
}

// Destruktor klasy ListGraph
ListGraph::~ListGraph() {
    clearList();
}

// Inicjalizacja listy sąsiedztwa
void ListGraph::initializeList() {
    adjList = new pair<int, int>*[vertices];
    listSizes = new int[vertices]();
}

// Czyszczenie listy sąsiedztwa
void ListGraph::clearList() {
    for (int i = 0; i < vertices; ++i) {
        delete[] adjList[i];
    }
    delete[] adjList;
    delete[] listSizes;
}

// Dodawanie krawędzi w liście sąsiedztwa
void ListGraph::addEdge(int u, int v, int weight) {
    pair<int, int>* newEdge = new pair<int, int>[listSizes[u] + 1];
    for (int i = 0; i < listSizes[u]; ++i) {
        newEdge[i] = adjList[u][i];
    }
    newEdge[listSizes[u]] = make_pair(v, weight);
    delete[] adjList[u];
    adjList[u] = newEdge;
    listSizes[u]++;

    if (!directed) {
        newEdge = new pair<int, int>[listSizes[v] + 1];
        for (int i = 0; i < listSizes[v]; ++i) {
            newEdge[i] = adjList[v][i];
        }
        newEdge[listSizes[v]] = make_pair(u, weight);
        delete[] adjList[v];
        adjList[v] = newEdge;
        listSizes[v]++;
    }
}

// Wyświetlanie listy sąsiedztwa
void ListGraph::display() {
    for (int i = 0; i < vertices; ++i) {
        cout << i << ": ";
        for (int j = 0; j < listSizes[i]; ++j) {
            cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
        }
        cout << endl;
    }
}
