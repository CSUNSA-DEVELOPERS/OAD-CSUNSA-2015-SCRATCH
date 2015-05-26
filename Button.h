#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
	Button(sf::Texture* normal, sf::Texture* clicked, /*std::string,*/sf::Vector2f location);
	virtual ~Button();
	void checkClick(sf::Vector2f);
	void setState(bool);
	void setText(sf::Font*,std::string*);
	bool getVar();
	sf::Sprite* getSprite();
	sf::Text * getText();
private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	sf::Text text;
	bool current;
};
