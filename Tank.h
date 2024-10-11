#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>

class Tank {
public:
    enum TankType { BLUE, LIGHT_BLUE, RED, YELLOW };

private:
    float x, y;
    float radius;
    TankType type;
    sf::CircleShape shape;

    // Variables para los efectos de los power-ups
    bool doubleTurn;
    double movePrecision;  // Precisión del movimiento (probabilidad)
    bool attackPrecision;  // Precisión en el ataque
    int attackPower;       // Poder de ataque (daño)

public:
    Tank(float startX, float startY, TankType type);

    // Métodos para aplicar los efectos de los power-ups
    void setDoubleTurn(bool status);
    void setMovePrecision(double precision);
    void setAttackPrecision(bool status);
    void setAttackPower(int power);

    void moveWithKeyboard();  // Método para mover el tanque con las teclas de flechas

    bool getDoubleTurn() const;
    double getMovePrecision() const;
    bool getAttackPrecision() const;
    int getAttackPower() const;

    // Otros métodos
    bool contains(const sf::Vector2i& mousePosition) const;
    void draw(sf::RenderWindow& window);
    void moveTo(float newX, float newY);
    std::pair<float, float> getPosition() const;
};

#endif
