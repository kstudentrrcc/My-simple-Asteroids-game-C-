#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Asteroid.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    sf::Clock clock;

    Player player;
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;

    void handlePlayerInput();
    void handleCollisions();
    void spawnAsteroids();
};

#endif // GAME_H
