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

typedef std::string Boton_Texto;

int n=10,x=20,y=20;	//numero de botones

/********PRUEBA de FUNCION***************/
sf::Vector2f medidas(50, 50);
sf::RectangleShape rect(medidas);

void myFunction()
{
	rect.move(9, 5);
}
/*****************************/


int main()
{
	/*Nueva ventana*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "Scratch in development", sf::Style::Default);

	/*cadena de texto que llevara un boton*/
	Boton_Texto texto = "Mover";

	/*Fuente que usara el Text del Boton*/
	sf::Font FuenteDelBoton;
	if (!FuenteDelBoton.loadFromFile("contb.ttf"))
	{
		std::cout << "Couln't open the font" << std::endl;
	}

	std::vector<Boton*> Botones; //Nuevo vector de punteros de tipo Button

	/*Agrega 'n' nuevos objetos del tipo boton con dos parametros del constructor */
	for (int i = 0; i < n; i++)
	{
		Botones.push_back(new Boton(FuenteDelBoton, { 100.f, 40.f }));
	}

	/*Establece los parametros que llevaran cada boton i dentro del vector*/
	for (int i = 0; i < n; i++)
	{
		
		Botones[i]->setCadena_Texto(texto);
		Botones[i]->setPosition(x, y);
		Botones[i]->setColor_Fondo(sf::Color(59, 134, 134));
		Botones[i]->setColor_Texto(sf::Color(11, 72, 107));
		Botones[i]->setAncho_Borde(1.f);
		Botones[i]->setColor_Borde(sf::Color(168, 219, 168));

		Botones[i]->setColor_FondoRatonSobreBoton(sf::Color(121, 189, 154));
		Botones[i]->setColor_TextoRSB(sf::Color(207, 240, 158));
		Botones[i]->setColor_BordeRSB(sf::Color(168, 219, 168));

		Botones[i]->setFuncion(myFunction);
		y += 50;
	}

	while (window.isOpen()) //Loop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) //Detecta el evento de cierre de la ventana
				window.close();
			for (int i = 0; i < n; i++)
			{
				Botones[i]->eventos(event);
			}
		}

		for (int i = 0; i < n; i++)
		{
			Botones[i]->manejadorE(window);
		}

		window.clear(); //Limpia la ventana

		for (int i = 0; i < n; i++)
		{
			window.draw(*Botones[i]); //Dibuja los botones con la funcion sobreescrita en la clase
			
		}

		window.draw(rect);
		window.display();
	} //Fin de la ventana

	/*Eliminando los punteros a objetos Button con un iterador*/
	for (std::vector<Boton*>::iterator iterador = Botones.begin(); iterador != Botones.end(); ++iterador)
	{
		delete *iterador;
	}

	/*Limpiando el contenido del vector botones*/
	Botones.clear();

	return 0;
}