#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Tank.h"
#include <SFML/Graphics.hpp>

class Player {
private:
    std::vector<Tank> tanks;
    Tank* selectedTank;       // El tanque seleccionado por el jugador
    int playerID;
    bool isTurn;

public:
    Player(int id);
    void addTank(const Tank& tank);
    void moveTankWithKeyboard();  // Mueve el tanque seleccionado con las flechas del teclado
    void drawTanks(sf::RenderWindow& window);
    bool handleMouseClick(sf::RenderWindow& window);
    void moveSelectedTank(sf::RenderWindow& window);
    bool isPlayerTurn() const;
    void setTurn(bool status);
};

#endif
