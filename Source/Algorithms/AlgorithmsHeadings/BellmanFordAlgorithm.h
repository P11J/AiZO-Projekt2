#ifndef PROJEKT2_BELLMANFORDALGORITHM_H
#define PROJEKT2_BELLMANFORDALGORITHM_H


#include "Algorithm.h"

class BellmanFordAlgorithm : public Algorithm {
public:
    void execute(Graph& graph) override; // Implementacja algorytmu Bellmana-Forda
};

#endif //PROJEKT2_BELLMANFORDALGORITHM_H
