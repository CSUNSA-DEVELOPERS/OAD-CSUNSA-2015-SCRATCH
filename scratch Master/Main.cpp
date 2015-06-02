#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/Graphics.hpp>
#include "Button.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef sf::Vector2i Mouse_Posicion;
typedef sf::Vector2f Boton_Posicion;
typedef std::string Boton_Texto;

int main()
{
	/*Nueva ventana*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "Scratch in development", sf::Style::Default);

	/*cadena de texto que llevara un boton*/
	Boton_Texto texto = "boton";

	/*Vectores de posiciones*/
	Boton_Posicion PosicionBotones(50, 50);
	Mouse_Posicion PosicionMouse;

	/*Carga las texturas que usaran los botones*/
	sf::Texture TexturaBoton, TexturaBotonClickeado;
	if (!TexturaBoton.loadFromFile("buttonwhite.png") || !TexturaBotonClickeado.loadFromFile("buttonwhite2.png"))
	{
		std::cout << "couldn't open the file" << std::endl;
	}

	/*Fuente que usara el Text del Boton*/
	sf::Font FuenteDelBoton;
	if (!FuenteDelBoton.loadFromFile("ethnocen.ttf"))
	{
		std::cout << "Couln't open the font" << std::endl;
	}

	std::vector<Button*> Botones; //Nuevo vector de punteros de tipo Button

	/*Agrega '5' nuevos objetos del tipo boton con tres parametros del constructor y actualiza la posicion del siguiente boton*/
	for (int i = 0; i < 5; i++)
	{
		Botones.push_back(new Button(&TexturaBoton, &TexturaBotonClickeado, PosicionBotones));
		PosicionBotones.y += 100;
	}

	/*Establece el texto que llevara cada boton i dentro del vector*/
	for (int i = 0; i < 5; i++)
	{
		Botones[i]->setTexto(&FuenteDelBoton, &texto);
	}

	while (window.isOpen()) //Loop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //Detecta el evento de cierre de la ventana
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) //Detecta el evento click presionado
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "El click izquierdo fue presionado" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					PosicionMouse.x = event.mouseButton.x;
					PosicionMouse.y = event.mouseButton.y;
		
					//Verifica si se hace click dentro del boton i si lo hace cambia de textura*/
					for (int i = 0; i < 5; i++)
					{
						Botones[i]->VerificarClick(PosicionMouse);
					}
				}
			}
			if (event.type == sf::Event::MouseMoved)  //Detecta el movimiento del mouse
			{
			std::cout << "Mouse x: " << event.mouseMove.x << std::endl;
			std::cout << "Mouse y: " << event.mouseMove.y << std::endl;
			PosicionMouse.x = event.mouseMove.x;
			PosicionMouse.y = event.mouseMove.y;
			}
		}

		/*for (int i = 0; i < 5; i++)
		{
			Botones[i]->Update(event, window);
		}*/
		

		window.clear(sf::Color(200, 0, 0)); //Limpia la ventana y le asigna el color ROJO(200)

		for (int i = 0; i < 5; i++)
		{
			window.draw(*Botones[i]->getSprite()); //Obtiene el sprite y lo dibuja en la ventana
			window.draw(*Botones[i]->getTexto()); //Obtiene el texto y lo dibuja en la ventana
		}

		window.display();
	} //Fin de la ventana

	/*Eliminando los punteros a objetos Button con un iterador*/
	for (std::vector<Button*>::iterator iterador = Botones.begin(); iterador != Botones.end(); ++iterador)
	{
		delete *iterador;
	}

	/*Limpiando el contenido del vector botones*/
	Botones.clear();

	return 0;
}