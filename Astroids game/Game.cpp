#include "Game.h"
#include "Constants.h"

Game::Game()
    : window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Asteroids Game"),
      player(),
      bullets(),
      asteroids() {
    window.setFramerateLimit(60); // Limit to 60 frames per second
    spawnAsteroids();
}

Game::~Game() {}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(float deltaTime) {
    handlePlayerInput();
    player.update(deltaTime);

    for (auto& bullet : bullets) {
        bullet.update(deltaTime);
    }

    for (auto& asteroid : asteroids) {
        asteroid.update(deltaTime);
    }

    handleCollisions();
}

void Game::render() {
    window.clear();

    player.render(window);

    for (auto& bullet : bullets) {
        bullet.render(window);
    }

    for (auto& asteroid : asteroids) {
        asteroid.render(window);
    }

    window.display();
}

void Game::handlePlayerInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(PLAYER_SPEED);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.rotate(-PLAYER_ROTATION_SPEED);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.rotate(PLAYER_ROTATION_SPEED);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.shoot();
    }
}

void Game::handleCollisions() {
    // Collision detection logic goes here
    // Example: bullet-asteroid collision
}

void Game::spawnAsteroids() {
    // Initialize asteroids and add them to the vector
}
