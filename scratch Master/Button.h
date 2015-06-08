#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
typedef void(*funcion)(); //puntero a función
typedef sf::Color NormalBotonColor;	//colores para botones normales
typedef sf::Color SobreBotonColor;	//colores para botones con el puntero encima

class Boton: public sf::Drawable,public sf::Transformable //hereda de las clases de la biblioteca para sobreescribir el metodo draw
{
public:
	Boton();
	Boton(sf::Font& fuente, const sf::Vector2f tamaño = sf::Vector2f(0, 0)); //recibe una referencia a una fuente y un vector de 2float (default0)
	void setTamaño(const sf::Vector2f tam);	// Establece el tamaño del boton
	void setFuente(sf::Font& fuent);	// Establece la fuente del texto del boton
	void setCadena_Texto(const std::string cadena);	//Establece la cadena de texto que tendra es constante
	void setColor_Fondo(const NormalBotonColor &NB_color);	//Establece el color del fondo del boton NB: boton normal
	void setColor_Texto(const NormalBotonColor &NB_color);	// Establece el color del texto
	void setAncho_Borde(float espesor);	//Establece el espesor de la linea del borde
	void setColor_Borde(const NormalBotonColor &NB_color);	//Establece el color del borde
	
	void setAccionSobreBot(bool activo = true);	// Establece el estado actual del boton
	void setColor_FondoRatonSobreBoton(const SobreBotonColor &RSB_color);	//Establece el color del boton cuando esta el cursor dentro
	void setColor_TextoRSB(const SobreBotonColor &RSB_color); // Establece el color del texto
	void setColor_BordeRSB(const SobreBotonColor &RSB_color);	//Establece el color del Borde

	void manejadorE(sf::RenderWindow &ventana);	//	Establece los nuevos colores de boton cada ves que el mouse pasa sobre uno
	void eventos(sf::Event &event);	// verifica si el evento MouseButtomClick se cumple en boton

	void setFuncion(funcion FuncionActual);	// Establece la funcion a la que apunta este Boton cuando se hace click

private:

	void actualizar();	//	actualiza miembros de la clase boton
	virtual void draw(sf::RenderTarget& seleccionado, sf::RenderStates estados) const; //	Sobreescribe draw ya que hereda de drawable


	sf::Vector2f b_tamaño;
	sf::RectangleShape b_cuerpo;	// la forma del boton

	sf::Font* m_fuente;
	sf::Text m_texto;

	sf::Color b_ColorFondo;
	sf::Color b_ColorTexto;
	sf::Color b_ColorBorde;

	sf::Color sobreB_ColorFondo;
	sf::Color sobreB_ColorTexto;
	sf::Color sobreB_ColorBorde;

	bool m_sobreBotonActivo;	// verdadero si el mouse ya no sigue sobre el boton

	bool m_mouseEncimaBoton;	// verdadero si el mouse esta sobre el boton
	bool m_botonPresionado;		//verdadero si el boton es presionado
	funcion m_FuncionDesencadenante;		//	Funcion que desencadena este boton
};

