/*#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")
#endif // SFML_STATIC*/

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Scrutch");

	std::string x = "avanza x pasos";
	sf::Vector2f positionI(50, 50),positionj(150,150),positionk(300,300);

	sf::Texture buttonTexture,buttonClickedTexture;
	if (!buttonTexture.loadFromFile("button.png") || !buttonClickedTexture.loadFromFile("specials-button.png"))
	{
		std::cout << "couldn't open the file" << std::endl;
	}


	Button adelante(&buttonTexture,&buttonClickedTexture,x,positionI);
    Button arriba(&buttonTexture,&buttonClickedTexture,x,positionj);
    Button abajo(&buttonTexture,&buttonClickedTexture,x,positionk);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(*adelante.getSprite());
		window.draw(*abajo.getSprite());
		window.draw(*arriba.getSprite());
		window.display();
	}

	return 0;
}
