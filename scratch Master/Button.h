#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button {
public:
	Button(sf::Texture*, sf::Texture*, /*std::string,*/sf::Vector2f);
	virtual ~Button();
	void VerificarClick(sf::Vector2i);
	void setEstado(bool);
	void setTexto(sf::Font*,std::string*);
	bool getValorActual();
	void Update(sf::Event&,sf::RenderWindow&);
	sf::Sprite* getSprite();
	sf::Text* getTexto();

private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* SprActual;
	sf::Text texto;
	bool actual;
};
