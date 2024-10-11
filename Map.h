#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SFML/Graphics.hpp>

class Map {
private:
    int size;  // Tamaño del mapa (n x n)
    std::vector<std::vector<int>> adjMatrix;  // Matriz de adyacencia para modelar el grafo
    std::vector<std::vector<int>> grid;  // Representación del mapa (0: libre, 1: obstáculo)

public:
    Map(int n);

    // Genera el mapa con obstáculos aleatorios
    void generateRandomObstacles(int obstacleCount);

    // Agrega una arista entre dos nodos
    void addEdge(int node1, int node2);

    // Verifica si hay una arista entre dos nodos
    bool hasEdge(int node1, int node2) const;

    // Dibuja el mapa en la ventana
    void drawMap(sf::RenderWindow& window);

    // Convierte coordenadas (x, y) a un índice de nodo
    int coordToNode(int x, int y) const;

    // Convierte un índice de nodo a coordenadas (x, y)
    std::pair<int, int> nodeToCoord(int node) const;

    // Retorna el tamaño del mapa
    int getSize() const { return size; }
};

#endif
