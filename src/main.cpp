#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(5.f);
    shape.setOutlineColor(sf::Color(255, 0, 0));

    sf::Clock clock;
    float speed = 5.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float deltaTime = clock.restart().asMilliseconds();
        // update
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            shape.setPosition(
                shape.getPosition().x + speed * deltaTime, 
                shape.getPosition().y
            );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            shape.setPosition(
                shape.getPosition().x - speed * deltaTime,
                shape.getPosition().y
            );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            shape.setPosition(
                shape.getPosition().x,
                shape.getPosition().y - speed * deltaTime
            );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            shape.setPosition(
                shape.getPosition().x,
                shape.getPosition().y + speed * deltaTime
            );
        }

        // render (draw)
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}