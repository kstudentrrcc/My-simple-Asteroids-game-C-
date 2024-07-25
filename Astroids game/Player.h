#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    virtual ~Player();

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

    void move(float deltaTime);
    void rotate(float deltaTime);
    void shoot();

    int getScore() const;
    int getLives() const;
    bool isAlive() const;

    void respawn();

private:
    int score;
    int lives;
    bool alive;

    sf::Clock shootTimer;
};

#endif // PLAYER_H
