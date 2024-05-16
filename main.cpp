#include <iostream>
#include "Graphs/GraphHeadings/MatrixGraph.h"
#include "Source/Graphs/GraphHeadings/ListGraph.h"
#include "Source/Algorithms/AlgorithmsHeadings/PrimAlgorithm.h"
#include "Source/Algorithms/AlgorithmsHeadings/KruskalAlgorithm.h"
#include "Source/Algorithms/AlgorithmsHeadings/DijkstraAlgorithm.h"
#include "Source/Algorithms/AlgorithmsHeadings/BellmanFordAlgorithm.h"
#include "Source/Algorithms/FordFulkersonAlgorithm.h"

using namespace std;

// Funkcja wyświetlająca menu programu
void displayMenu() {
    cout << "1. Wczytaj dane z pliku\n";
    cout << "2. Wygeneruj graf losowo\n";
    cout << "3. Wyświetl graf listowo i macierzowo na ekranie\n";
    cout << "4. Algorytm Prima\n";
    cout << "5. Algorytm Kruskala\n";
    cout << "6. Algorytm Dijkstry\n";
    cout << "7. Algorytm Forda-Bellmana\n";
    cout << "8. Algorytm Forda-Fulkersona\n";
    cout << "0. Wyjście\n";
}

// Główna funkcja programu
int main() {
    MatrixGraph* matrixGraph = nullptr;
    ListGraph* listGraph = nullptr;
    PrimAlgorithm prim;
    KruskalAlgorithm kruskal;
    DijkstraAlgorithm dijkstra;
    BellmanFordAlgorithm bellmanFord;
    FordFulkersonAlgorithm fordFulkerson;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string filename;
                cout << "Podaj nazwę pliku: ";
                cin >> filename;
                matrixGraph->loadFromFile(filename);
                listGraph->loadFromFile(filename);
                break;
            }
            case 2: {
                int vertices, density;
                cout << "Liczba wierzchołków: ";
                cin >> vertices;
                cout << "Gęstość grafu (%): ";
                cin >> density;
                matrixGraph = new MatrixGraph(vertices, false);
                listGraph = new ListGraph(vertices, false);
                matrixGraph->generateRandomGraph(vertices, density);
                listGraph->generateRandomGraph(vertices, density);
                break;
            }
            case 3:
                if (matrixGraph) {
                    cout << "Reprezentacja macierzowa:" << endl;
                    matrixGraph->display();
                }
                if (listGraph) {
                    cout << "Reprezentacja listowa:" << endl;
                    listGraph->display();
                }
                break;
            case 4:
                if (matrixGraph) {
                    cout << "Algorytm Prima dla reprezentacji macierzowej:" << endl;
                    prim.execute(*matrixGraph);
                }
                if (listGraph) {
                    cout << "Algorytm Prima dla reprezentacji listowej:" << endl;
                    prim.execute(*listGraph);
                }
                break;
            case 5:
                if (matrixGraph) {
                    cout << "Algorytm Kruskala dla reprezentacji macierzowej:" << endl;
                    kruskal.execute(*matrixGraph);
                }
                if (listGraph) {
                    cout << "Algorytm Kruskala dla reprezentacji listowej:" << endl;
                    kruskal.execute(*listGraph);
                }
                break;
            case 6:
                if (matrixGraph) {
                    cout << "Algorytm Dijkstry dla reprezentacji macierzowej:" << endl;
                    dijkstra.execute(*matrixGraph);
                }
                if (listGraph) {
                    cout << "Algorytm Dijkstry dla reprezentacji listowej:" << endl;
                    dijkstra.execute(*listGraph);
                }
                break;
            case 7:
                if (matrixGraph) {
                    cout << "Algorytm Forda-Bellmana dla reprezentacji macierzowej:" << endl;
                    bellmanFord.execute(*matrixGraph);
                }
                if (listGraph) {
                    cout << "Algorytm Forda-Bellmana dla reprezentacji listowej:" << endl;
                    bellmanFord.execute(*listGraph);
                }
                break;
            case 8:
                if (matrixGraph) {
                    cout << "Algorytm Forda-Fulkersona dla reprezentacji macierzowej:" << endl;
                    fordFulkerson.execute(*matrixGraph);
                }
                if (listGraph) {
                    cout << "Algorytm Forda-Fulkersona dla reprezentacji listowej:" << endl;
                    fordFulkerson.execute(*listGraph);
                }
                break;
            case 0:
                cout << "Zakończenie programu." << endl;
                break;
            default:
                cout << "Nieprawidłowa opcja. Spróbuj ponownie." << endl;
        }
    } while (choice != 0);

    delete matrixGraph;
    delete listGraph;

    return 0;
}
