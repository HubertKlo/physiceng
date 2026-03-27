#include <SFML/Graphics.hpp>
#include "particles.h"
#include <chrono>
#include <iostream>

//Types of collisons

struct circle{
    float r;
    point s;
    circle(particle &p1){
        s = p1.get_pos();
    }
};
struct AABB{
    point minx,miny;
};
bool IsColliding(circle &c1,circle &c2){
    vector dis(&c1.s,&c2.s);
    return(dis.magintude()<=(c1.r+c2.r));
}

int main()
{   
    float World_Scale = 100.f;
    particle p1;
    particle p2;
    auto lasttime = std::chrono::steady_clock::now();
    float dt = (1/144.f);
    float t=0;
    float acumulator=0;
    
    p1.set_pos(0,0);
    p1.set_alc(10.f,0.f);

    p2.set_pos(5,0);
    p2.set_alc(-10.f,0.f);

    sf::Vector2f pos1={p1.get_pos().getx(),p1.get_pos().gety()};
    sf::Vector2f pos2={p2.get_pos().getx(),p2.get_pos().gety()};

    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Window");
    sf::CircleShape Circ(0.5f*World_Scale);
    sf::CircleShape Rect(0.5f*World_Scale);

    circle c1(p1); 
    circle c2(p2); 

    c1.r=0.5f;
    c2.r=0.5f;

    Circ.setFillColor(sf::Color::Green);
    Circ.setPosition(pos1);
    
    Circ.setFillColor(sf::Color::Red);
    Circ.setPosition(pos2);

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
            p2.integrate(dt);
            acumulator-=dt;
            t+=dt;
        }

        circle c1(p1);   
        circle c2(p2);  

        c1.r=0.5f;  
        c2.r=0.5f;
        
        if(IsColliding(c1,c2)){
            //rebounce
              p2.set_vel(-p2.get_vel().get_x(),-p2.get_vel().get_y());
              p1.set_vel(-p1.get_vel().get_x(),-p1.get_vel().get_y());
              p2.set_alc(-p2.get_alc().get_x(),-p2.get_alc().get_y());
              p1.set_alc(-p1.get_alc().get_x(),-p1.get_alc().get_y());
        } 
        ////penetration
        vector dif(&c1.s,&c2.s);
        float overlap = (c1.r+c2.r)-dif.magintude();
        if(overlap > 0){
            dif.normalize();
            p1.set_pos(p1.get_pos().getx() + dif.get_x() * overlap * 0.5f,p1.get_pos().gety() + dif.get_y() * overlap * 0.5f);
            p2.set_pos(p2.get_pos().getx() - dif.get_x() * overlap * 0.5f, p2.get_pos().gety() - dif.get_y() * overlap * 0.5f);
        }

            pos1.x=p1.get_pos().getx()*World_Scale;
            pos1.y=p1.get_pos().gety()*World_Scale;
            Circ.setPosition(pos1);
            pos2.x=p2.get_pos().getx()*World_Scale;
            pos2.y=p2.get_pos().gety()*World_Scale;
            Rect.setPosition(pos2);
            window.clear();
            window.draw(Circ);
            window.draw(Rect);
            window.display();

    }
    
}