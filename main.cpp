/**********************************
Window*****************************
**********************************/
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    sf::RectangleShape rect; //private
    float bottom,left,right,top;

    Player(sf::Vector2f position,sf::Vector2f size, sf::Color color)
    {
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(color);
    }

    void update()
    {
        bottom = rect.getPosition().y + rect.getSize().y;
        left = rect.getPosition().x;
        right = rect.getPosition().x+rect.getSize().x;
        top = rect.getPosition().y;
    }

    bool Collision(Player p)
    {
        if(right< p.left||left>p.right ||top>p.bottom || bottom<p.top)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(640,480,32),"SCRATCH IN DEVELOPMENT");

    Player p1(Player(sf::Vector2f(10,10),sf::Vector2f(20,20),sf::Color::Red)),
    p2(Player(sf::Vector2f(100,100),sf::Vector2f(20,20),sf::Color::Blue));

    while(window.isOpen())
    {
        sf::Event Event;
        while(window.pollEvent(Event))
        {
            switch(Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            p1.rect.move(1.0f,0);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            p1.rect.move(-1.0f,0);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            p1.rect.move(0,-1.0f);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            p1.rect.move(0,1.0f);

        p1.update();
        p2.update();

        if(p1.Collision(p2)){
            std::cout<<"Collision"<<endl;
            p1.rect.move(-0.1f,0);
        }
        window.clear(sf::Color(0,240,255));
        window.draw(p1.rect);
        window.draw(p2.rect);
        window.display();
    }
}
