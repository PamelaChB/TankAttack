#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    Player player1;
    Player player2;
    Map gameMap; // Mapa del juego
    int turnCount;

public:
    Game();
    void initializeGame();
    void runTurn(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void startGame();
};

#endif
