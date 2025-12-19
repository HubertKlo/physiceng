#include <SFML/Graphics.hpp>
//#include "vectors.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Vector2f v1 = {0.01,0.01};
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        window.draw(shape);
        shape.move(v1);
        window.display();
    }
    
}