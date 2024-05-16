cmake_minimum_required(VERSION 3.27)
project(Projekt2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Projekt2 main.cpp
        Source/Graphs/GraphCpp/Graph.cpp
        Source/Graphs/GraphHeadings/Graph.h
        Source/Graphs/GraphCpp/MatrixGraph.cpp
        Source/Graphs/GraphHeadings/MatrixGraph.h
        Source/Graphs/GraphCpp/ListGraph.cpp
        Source/Graphs/GraphHeadings/ListGraph.h
        Source/Algorithms/AlgorithmsHeadings/Algorithm.h
        Source/Algorithms/AlgorithmsCpp/PrimAlgorithm.cpp
        Source/Algorithms/AlgorithmsHeadings/PrimAlgorithm.h
        Source/Algorithms/AlgorithmsCpp/KruskalAlgorithm.cpp
        Source/Algorithms/AlgorithmsHeadings/KruskalAlgorithm.h
        Source/Algorithms/AlgorithmsCpp/DijkstraAlgorithm.cpp
        Source/Algorithms/AlgorithmsHeadings/DijkstraAlgorithm.h
        Source/Algorithms/AlgorithmsCpp/BellmanFordAlgorithm.cpp
        Source/Algorithms/AlgorithmsHeadings/BellmanFordAlgorithm.h
        Source/Algorithms/FordFulkersonAlgorithm.cpp
        Source/Algorithms/FordFulkersonAlgorithm.h)
