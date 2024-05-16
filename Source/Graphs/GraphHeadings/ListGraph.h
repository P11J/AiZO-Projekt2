#ifndef PROJEKT2_LISTGRAPH_H
#define PROJEKT2_LISTGRAPH_H


#include "Graph.h"

class ListGraph : public Graph {
private:
    pair<int, int>** adjList; // Tablica dynamiczna par reprezentujących sąsiednie wierzchołki i wagi krawędzi
    int* listSizes;           // Tablica dynamiczna przechowująca rozmiar każdej listy sąsiedztwa

    void initializeList(); // Inicjalizacja listy sąsiedztwa
    void clearList();      // Czyszczenie listy sąsiedztwa

public:
    ListGraph(int v, bool d);
    ~ListGraph();

    // Metody specyficzne dla reprezentacji listowej
    void addEdge(int u, int v, int weight) override;
    void display() override;
};


#endif //PROJEKT2_LISTGRAPH_H
