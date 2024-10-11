#include "Tank.h"
#include <cmath>


Tank::Tank(float startX, float startY, TankType type)
    : x(startX), y(startY), radius(20.0f), type(type) {
    shape.setRadius(radius);
    shape.setPosition(x, y);

    // Asigna el color según el tipo de tanque
    switch (type) {
        case BLUE:
            shape.setFillColor(sf::Color::Blue);
            break;
        case LIGHT_BLUE:
            shape.setFillColor(sf::Color(173, 216, 230));  // Color celeste
            break;
        case RED:
            shape.setFillColor(sf::Color::Red);
            break;
        case YELLOW:
            shape.setFillColor(sf::Color::Yellow);
            break;
    }
}

// Implementación de los métodos para power-ups
void Tank::setDoubleTurn(bool status) {
    doubleTurn = status;
}

void Tank::setMovePrecision(double precision) {
    movePrecision = precision;
}

void Tank::setAttackPrecision(bool status) {
    attackPrecision = status;
}

void Tank::setAttackPower(int power) {
    attackPower = power;
}

// Métodos para obtener los valores de los power-ups
bool Tank::getDoubleTurn() const {
    return doubleTurn;
}

double Tank::getMovePrecision() const {
    return movePrecision;
}

bool Tank::getAttackPrecision() const {
    return attackPrecision;
}

int Tank::getAttackPower() const {
    return attackPower;
}

void Tank::moveWithKeyboard() {
    // Ajuste de la distancia de movimiento
    float movementSpeed = 5.0f;

    // Detecta las teclas y mueve el tanque en la dirección correspondiente
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        y -= movementSpeed;  // Mover hacia arriba
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        y += movementSpeed;  // Mover hacia abajo
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        x -= movementSpeed;  // Mover hacia la izquierda
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        x += movementSpeed;  // Mover hacia la derecha
    }

    // Actualiza la posición de la forma gráfica del tanque
    shape.setPosition(x, y);
}


bool Tank::contains(const sf::Vector2i& mousePosition) const {
    float dx = mousePosition.x - (x + radius);
    float dy = mousePosition.y - (y + radius);
    return std::sqrt(dx * dx + dy * dy) <= radius;
}

void Tank::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

//void Tank::moveTo(float newX, float newY) {
    //x = newX;
    //y = newY;
    //shape.setPosition(x, y);
//}

std::pair<float, float> Tank::getPosition() const {
    return {x, y};
}
