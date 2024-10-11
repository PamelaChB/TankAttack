#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
private:
    float x, y;             // Posición de la bala
    float directionX, directionY;  // Dirección de la bala
    bool isActive;          // Si la bala sigue en movimiento

public:
    Bullet(float startX, float startY, float dirX, float dirY);

    // Actualiza la posición de la bala
    void updatePosition(float deltaTime, const std::vector<std::vector<int>>& map, int mapSize);

    // Rebota la bala al colisionar con un borde
    void bounce();

    // Verifica si la bala ha golpeado un tanque
    bool hitTank(int tankX, int tankY) const;

    // Desactiva la bala cuando golpea algo
    void deactivate();

    // Devuelve si la bala sigue activa
    bool isActiveBullet() const;

    // Dibuja la bala en la ventana de SFML
    void draw(sf::RenderWindow& window);
};

#endif
