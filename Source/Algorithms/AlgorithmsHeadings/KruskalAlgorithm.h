#ifndef PROJEKT2_KRUSKALALGORITHM_H
#define PROJEKT2_KRUSKALALGORITHM_H


#include "Algorithm.h"

class KruskalAlgorithm : public Algorithm {
private:
    // Struktura reprezentująca krawędź grafu
    struct Edge {
        int u, v, weight;
    };

    // Funkcja do znajdowania reprezentanta zbioru
    int find(int* parent, int i);

    // Funkcja do łączenia dwóch zbiorów
    void unionSets(int* parent, int* rank, int x, int y);

public:
    // Implementacja algorytmu Kruskala
    void execute(Graph& graph) override;
};



#endif //PROJEKT2_KRUSKALALGORITHM_H
