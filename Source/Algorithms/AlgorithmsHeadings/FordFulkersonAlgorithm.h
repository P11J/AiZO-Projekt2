#ifndef PROJEKT2_FORDFULKERSONALGORITHM_H
#define PROJEKT2_FORDFULKERSONALGORITHM_H


#include "Algorithm.h"

class FordFulkersonAlgorithm : public Algorithm {
private:
    bool bfs(int** rGraph, int s, int t, int* parent, int vertices);

public:
    void execute(Graph& graph) override; // Implementacja algorytmu Forda-Fulkersona
};

#endif //PROJEKT2_FORDFULKERSONALGORITHM_H
