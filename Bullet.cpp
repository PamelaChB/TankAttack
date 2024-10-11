#include "Bullet.h"
#include <iostream>
#include <cmath>

Bullet::Bullet(float startX, float startY, float dirX, float dirY)
    : x(startX), y(startY), directionX(dirX), directionY(dirY), isActive(true) {}

void Bullet::updatePosition(float deltaTime, const std::vector<std::vector<int>>& map, int mapSize) {
    if (!isActive) return;

    // Mover la bala según su dirección y el tiempo transcurrido
    x += directionX * deltaTime;
    y += directionY * deltaTime;

    // Verificar colisiones con los bordes del mapa
    if (x < 0 || x >= mapSize) bounce();
    if (y < 0 || y >= mapSize) bounce();

    std::cout << "Posición de la bala: (" << x << ", " << y << ")\n";
}

void Bullet::bounce() {
    // Cambia la dirección de la bala
    directionX = -directionX;
    directionY = -directionY;
    std::cout << "¡Rebote de la bala!\n";
}

bool Bullet::hitTank(int tankX, int tankY) const {
    return std::sqrt((x - tankX) * (x - tankX) + (y - tankY) * (y - tankY)) < 20;  // Suponiendo que 20 es el radio del tanque
}

void Bullet::deactivate() {
    isActive = false;
    std::cout << "Bala desactivada.\n";
}

bool Bullet::isActiveBullet() const {
    return isActive;
}

void Bullet::draw(sf::RenderWindow& window) {
    if (!isActive) return;

    sf::CircleShape bulletShape(5);
    bulletShape.setPosition(x, y);
    bulletShape.setFillColor(sf::Color::Yellow);
    window.draw(bulletShape);
}
