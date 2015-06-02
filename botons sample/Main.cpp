#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC


#include <SFML/Graphics.hpp>
#include "button.h"

sf::Font font;
Button button(font, { 300.f, 80.f });

void triggered()
{
	button.setPosition(button.getPosition() + sf::Vector2f(10.f, 10.f));
}

int main()
{
	font.loadFromFile("contb.ttf");
	button.setString("ABCDE");
	button.setPosition(200, 200);
	button.setBackgroundColor(sf::Color(59, 134, 134));
	button.setTextColor(sf::Color(11, 72, 107));
	button.setOutlineThickness(1.f);
	button.setOutlineColor(sf::Color(168, 219, 168));

	button.setOverBackgroundColor(sf::Color(121, 189, 154));
	button.setOverTextColor(sf::Color(207, 240, 158));
	button.setOverOutlineColor(sf::Color(168, 219, 168));

	button.setTriggerFunction(triggered);

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			button.events(event);
		}

		button.handler(window);

		window.clear();
		window.draw(button);
		window.display();
	}

}