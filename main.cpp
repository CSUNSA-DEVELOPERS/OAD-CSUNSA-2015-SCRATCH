#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

/**********************************
Window*****************************
**********************************/
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Player
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
};*/

/*int main()
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
}*/
typedef sf::Vector2f MousePosition;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Scratch in development");

	std::string x = "boton",y="for",z="atras";

	sf::Vector2f positionI(50, 50)/*, positionj(50, 150), positionk(50, 250)*/;
	MousePosition mousePosition;

	sf::Texture buttonTexture, buttonClickedTexture;

	if (!buttonTexture.loadFromFile("buttonwhite.png") || !buttonClickedTexture.loadFromFile("buttonwhite2.png"))
	{
		std::cout << "couldn't open the file" << std::endl;
	}

	std::vector<Button*> Botones;
	/*Button adelante(&buttonTexture, &buttonClickedTexture, positionI);
	Button arriba(&buttonTexture, &buttonClickedTexture,  positionj);
	Button abajo(&buttonTexture, &buttonClickedTexture,  positionk);*/

	for (int i = 0; i < 5; i++)
	{
		Botones.push_back(new Button(&buttonTexture, &buttonClickedTexture, positionI));
		positionI.y += 100;
	}

	sf::Font buttonText;
	if (!buttonText.loadFromFile("ethnocen.ttf"))
	{
		std::cout << "Couln't open the font" << std::endl;
	}

	/*adelante.setText(&buttonText, &x);
	arriba.setText(&buttonText, &y);
	abajo.setText(&buttonText, &z);*/
	for (int i = 0; i < 5; i++)
	{
		Botones[i]->setText(&buttonText, &x);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) //DETECTA CUANDO EL MOUSE HACE CLICK EN EL CUADRO
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					mousePosition.x = event.mouseButton.x;
					mousePosition.y = event.mouseButton.y;
					/*adelante.checkClick(mousePosition);
					arriba.checkClick(mousePosition);
					abajo.checkClick(mousePosition);*/
					for (int i = 0; i < 5; i++)
					{
						Botones[i]->checkClick(mousePosition);
					}
				}
			}
			if (event.type == sf::Event::MouseMoved)  //DETECTA CUANDO EL MOUSE PASA POR EL CUADRO
			{
			std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
			std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
			mousePosition.x=event.mouseMove.x;
			mousePosition.y=event.mouseMove.y;
			/*adelante.checkClick(mousePosition);
			arriba.checkClick(mousePosition);
			abajo.checkClick(mousePosition);*/
			}
		}

		window.clear(sf::Color(200, 0, 0));
		/*window.draw(*adelante.getSprite());
		window.draw(*abajo.getSprite());
		window.draw(*arriba.getSprite());
		window.draw(*adelante.getText());
		window.draw(*abajo.getText());
		window.draw(*arriba.getText());*/

		for (int i = 0; i < 5; i++)
		{
			window.draw(*Botones[i]->getSprite());
			window.draw(*Botones[i]->getText());
		}

		window.display();
	}

	for (std::vector<Button*>::iterator iterador = Botones.begin(); iterador != Botones.end(); ++iterador)
	{
		delete *iterador;
	}

	Botones.clear();

	return 0;
}