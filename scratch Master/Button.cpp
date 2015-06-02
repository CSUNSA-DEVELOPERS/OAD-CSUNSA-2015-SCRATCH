#include "Button.h"

Button::Button(sf::Texture* normal, sf::Texture* clicked, /*std::string words,*/ sf::Vector2f posicion) {
	this->normal.setTexture(*normal);
	this->clicked.setTexture(*clicked);
	this->SprActual = &this->normal;
	actual = false;
	this->normal.setPosition(posicion);
	this->clicked.setPosition(posicion);
	/*text.setString(words);
	text.setPosition(location.x + 3, location.y + 3);
	text.setCharacterSize(14);*/
}

Button::~Button()
{
	//delete SprActual;
}

void Button::VerificarClick(sf::Vector2i mousePos) {
	if (mousePos.x>SprActual->getPosition().x && mousePos.x<(SprActual->getPosition().x + SprActual->getGlobalBounds().width)) {
		if (mousePos.y>SprActual->getPosition().y && mousePos.y<(SprActual->getPosition().y + SprActual->getGlobalBounds().height)) {
			setEstado(!actual);
		}
		/*else{
			actual = false;
			setEstado(actual);
		}*/
	}
}

void Button::setEstado(bool click) {
	actual = click;
	if (actual) {
		SprActual = &clicked;
		return;
	}
	SprActual = &normal;
}

void Button::setTexto(sf::Font *x, std::string *words) {
	texto.setFont(*x);
	texto.setString(*words);
	texto.setPosition((SprActual->getGlobalBounds().width + SprActual->getPosition().x)-(SprActual->getGlobalBounds().width/2), 
	(SprActual->getGlobalBounds().height + SprActual->getPosition().y) - (SprActual->getGlobalBounds().height-7));
	texto.setCharacterSize(14);
	texto.setColor(sf::Color::Black);
}

bool Button::getValorActual() {
	return actual;
}

sf::Sprite* Button::getSprite() {
	return SprActual;
}

sf::Text* Button::getTexto() {
	return &texto;
}

/*void Button::Update(sf::Event &e, sf::RenderWindow &window)
{
	sf::Vector2i m_mousePosition = sf::Mouse::getPosition(window);*/

	/*bool mouseInButton = m_mousePosition.x >= SprActual->getPosition().x - SprActual->getGlobalBounds().width / 2
		&& m_mousePosition.x <= SprActual->getPosition().x + SprActual->getGlobalBounds().width / 2
		&& m_mousePosition.y >= SprActual->getPosition().y - SprActual->getGlobalBounds().height / 2
		&& m_mousePosition.y <= SprActual->getPosition().y + SprActual->getGlobalBounds().height / 2;*/
	/*bool mouseInButton = m_mousePosition.x > SprActual->getPosition().x && m_mousePosition.x<(SprActual->getPosition().x + SprActual->getGlobalBounds().width) && 
		m_mousePosition.y>SprActual->getPosition().y && m_mousePosition.y < (SprActual->getPosition().y + SprActual->getGlobalBounds().height);*/

	/*if (e.type == sf::Event::Moved)
	{
		if (mouseInButton)
		{
			setEstado(!actual);
		}

		else
		{
			actual = false;
			setEstado(actual);
		}
	}*/

	/*if (e.type == sf::Event::MouseButtonPressed)
	{
		std::cout << "detecto" << std::endl;
		switch (e.mouseButton.button)
		{
		case sf::Mouse::Left:
		{
			if (mouseInButton)
			{
				setEstado(!actual);
				std::cout << "set estado !actual click" << std::endl;
			}

			else
			{
				//actual = false;
				std::cout << "set estado acual = false click" << std::endl;
				setEstado(actual);
			}
			break;
		}
		}
	}

	if (e.type == sf::Event::MouseButtonReleased)
	{
		std::cout << "detecto release" << std::endl;
		switch (e.mouseButton.button)
		{
		case sf::Mouse::Left:
		{
				if (mouseInButton)
				{
					setEstado(!actual);
					std::cout << "set estado !actual release" << std::endl;
				}

				else
				{
					//actual = false;
					std::cout << "set estado acual = false release" << std::endl;
					setEstado(actual);
				}
				break;
		}
		}
	}
}*/