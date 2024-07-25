#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity {
public:
    Asteroid();
    virtual ~Asteroid();

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    void respawn();

private:
    void resetPosition();

    int size; // 1, 2, or 3 for small, medium, large
};

#endif // ASTEROID_H
