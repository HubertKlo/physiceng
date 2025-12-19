#include <SFML/Graphics.hpp>
#include "particles.h"
#include <chrono>

int main()
{
    particle p1;
    auto lasttime = std::chrono::steady_clock::now();
    float dt = (1/144.f);
    float t=0;
    float acumulator=0;
    p1.set_pos(0,0);
    p1.set_alc(1.f,1.f);
    sf::Vector2f pos1={p1.get_pos().getx(),p1.get_pos().gety()};
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos1);
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        auto actualtime = std::chrono::steady_clock::now();
        std::chrono::duration<float> drealtime = actualtime - lasttime;
        lasttime = actualtime; 
        acumulator+=drealtime.count();
        while(acumulator>=dt){
            p1.integrate(dt);
            acumulator-=dt;
            t+=dt;
        }
            pos1.x=p1.get_pos().getx();
            pos1.y=p1.get_pos().gety();
            shape.setPosition(pos1);
            window.clear();
            window.draw(shape);
            window.display();
    }
    
}