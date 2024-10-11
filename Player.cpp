#include "Player.h"
#include <iostream>

Player::Player(int id) : playerID(id), isTurn(false) {}

void Player::addTank(const Tank& tank) {
    tanks.push_back(tank);
}

void Player::drawTanks(sf::RenderWindow& window) {
    for (Tank& tank : tanks) {
        tank.draw(window);
    }
}

bool Player::handleMouseClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    // Verifica si se ha hecho clic en algún tanque
    for (Tank& tank : tanks) {
        if (tank.contains(mousePos)) {
            selectedTank = &tank;  // Selecciona este tanque
            std::cout << "Jugador " << playerID << " ha seleccionado un tanque.\n";
            return true;
        }
    }
    return false;
}


void Player::moveSelectedTank(sf::RenderWindow &window) {
    if (selectedTank) {
        selectedTank->moveWithKeyboard();  // Mueve el tanque seleccionado con las flechas
    }
}

void Player::moveTankWithKeyboard() {
    for (Tank& tank : tanks) {
        tank.moveWithKeyboard();  // Mueve el tanque con las teclas de flechas
    }
}

bool Player::isPlayerTurn() const {
    return isTurn;
}

void Player::setTurn(bool status) {
    isTurn = status;
}
