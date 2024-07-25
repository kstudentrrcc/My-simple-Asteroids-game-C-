#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

    sf::FloatRect getBounds() const;

protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
};

#endif // ENTITY_H