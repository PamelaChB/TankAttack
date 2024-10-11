#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Map::Map(int n) : size(n) {
    adjMatrix.resize(size * size, std::vector<int>(size * size, 0));
    grid.resize(size, std::vector<int>(size, 0));  // Inicializa el mapa sin obstáculos
}

void Map::generateRandomObstacles(int obstacleCount) {
    srand(time(0));
    for (int i = 0; i < obstacleCount; ++i) {
        int x = rand() % size;
        int y = rand() % size;
        grid[x][y] = 1;  // Coloca un obstáculo en la celda
    }

    // Genera las conexiones en la matriz de adyacencia para celdas no bloqueadas
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 0) {  // Solo se conectan las celdas libres
                int node = coordToNode(i, j);

                // Conectar con celdas vecinas
                if (i > 0 && grid[i-1][j] == 0) addEdge(node, coordToNode(i-1, j));  // Arriba
                if (i < size-1 && grid[i+1][j] == 0) addEdge(node, coordToNode(i+1, j));  // Abajo
                if (j > 0 && grid[i][j-1] == 0) addEdge(node, coordToNode(i, j-1));  // Izquierda
                if (j < size-1 && grid[i][j+1] == 0) addEdge(node, coordToNode(i, j+1));  // Derecha
            }
        }
    }
}

void Map::addEdge(int node1, int node2) {
    adjMatrix[node1][node2] = 1;
    adjMatrix[node2][node1] = 1;  // Grafo no dirigido
}

bool Map::hasEdge(int node1, int node2) const {
    return adjMatrix[node1][node2] == 1;
}

void Map::drawMap(sf::RenderWindow& window) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sf::RectangleShape cell(sf::Vector2f(40, 40));
            cell.setPosition(i * 40, j * 40);

            if (grid[i][j] == 1) {
                cell.setFillColor(sf::Color::Black);  // Obstáculo
            } else {
                cell.setFillColor(sf::Color::White);  // Celda libre
            }

            cell.setOutlineColor(sf::Color::Black);
            cell.setOutlineThickness(1);
            window.draw(cell);
        }
    }
}

int Map::coordToNode(int x, int y) const {
    return x * size + y;  // Convertir coordenadas (x, y) a índice del nodo
}

std::pair<int, int> Map::nodeToCoord(int node) const {
    return {node / size, node % size};  // Convertir índice del nodo a coordenadas (x, y)
}
