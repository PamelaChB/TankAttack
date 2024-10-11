#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(Type type, int turnsDuration) : powerUpType(type), isActive(false), remainingTurns(turnsDuration) {}

void PowerUp::activate() {
    isActive = true;
    std::cout << "Power-up activado: " << getPowerUpName() << " por " << remainingTurns << " turnos.\n";
}

void PowerUp::applyToTank(Tank& tank) {
    if (!isActive) return;

    switch (powerUpType) {
        case DOUBLE_TURN:
            tank.setDoubleTurn(true);
            break;
        case MOVE_PRECISION:
            tank.setMovePrecision(0.9);  // 90% de probabilidad de usar BFS o Dijkstra
            break;
        case ATTACK_PRECISION:
            tank.setAttackPrecision(true);
            break;
        case ATTACK_POWER:
            tank.setAttackPower(100);  // Daño de la bala al 100%
            break;
    }
}

void PowerUp::update() {
    if (isActive && remainingTurns > 0) {
        remainingTurns--;
        std::cout << "Turnos restantes para " << getPowerUpName() << ": " << remainingTurns << "\n";
        if (remainingTurns <= 0) {
            deactivate();
        }
    }
}

void PowerUp::deactivate() {
    isActive = false;
    std::cout << "Power-up desactivado: " << getPowerUpName() << "\n";
}

bool PowerUp::isActivePowerUp() const {
    return isActive;
}

std::string PowerUp::getPowerUpName() const {
    switch (powerUpType) {
        case DOUBLE_TURN: return "Doble Turno";
        case MOVE_PRECISION: return "Precisión de Movimiento";
        case ATTACK_PRECISION: return "Precisión de Ataque";
        case ATTACK_POWER: return "Poder de Ataque";
        default: return "Desconocido";
    }
}
