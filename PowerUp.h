#ifndef POWERUP_H
#define POWERUP_H

#include "Tank.h"

class PowerUp {
public:
    enum Type { DOUBLE_TURN, MOVE_PRECISION, ATTACK_PRECISION, ATTACK_POWER };

private:
    Type powerUpType;
    bool isActive;
    int remainingTurns;  // Duración del power-up en turnos

public:
    // Constructor que recibe el tipo de power-up y su duración en turnos
    PowerUp(Type type, int turnsDuration);

    // Activa el power-up
    void activate();

    // Aplica el power-up a un tanque
    void applyToTank(Tank& tank);

    // Actualiza la duración del power-up (reduce la cantidad de turnos restantes)
    void update();

    // Desactiva el power-up cuando se agota su duración
    void deactivate();

    // Devuelve si el power-up está activo
    bool isActivePowerUp() const;

    // Obtiene el nombre del power-up
    std::string getPowerUpName() const;
};

#endif
