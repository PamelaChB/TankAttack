#include "Game.h"
#include <iostream>

Game::Game() : player1(1), player2(2), turnCount(0), gameMap(20) {
    initializeGame();
}

void Game::initializeGame() {
    player1.addTank(Tank(100, 100, Tank::BLUE));
    player1.addTank(Tank(200, 200, Tank::LIGHT_BLUE));
    player2.addTank(Tank(300, 300, Tank::RED));
    player2.addTank(Tank(400, 400, Tank::YELLOW));

    gameMap.generateRandomObstacles(10);
}

void Game::runTurn(sf::RenderWindow& window) {
    if (turnCount % 2 == 0) {
        player1.setTurn(true);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player1.handleMouseClick(window);  // Selecciona el tanque al hacer clic
        }

        player1.moveSelectedTank(window);  // Mueve el tanque seleccionado con las flechas

    
        if (turnCount > 0) {    // Cambia el turno después de 1 movimiento
            player1.setTurn(false);
            turnCount++;
        }
    } else {
        player2.setTurn(true);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player2.handleMouseClick(window);  // Selecciona el tanque al hacer clic
        }

        player2.moveSelectedTank(window);  // Mueve el tanque seleccionado con las flechas

        // Lógica para finalizar el turno
        if (turnCount > 0) {    // Cambia el turno después de 1 movimiento
            player2.setTurn(false);
            turnCount++;
        }
    }
}


void Game::draw(sf::RenderWindow& window) {
    gameMap.drawMap(window);
    player1.drawTanks(window);
    player2.drawTanks(window);
}

void Game::startGame() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tank Attack!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        runTurn(window);
        draw(window);
        window.display();
    }
}
