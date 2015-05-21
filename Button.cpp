#include "Button.h"

Button::Button(sf::Texture* normal, sf::Texture* clicked, std::string words, sf::Vector2f location) {
	this->normal.setTexture(*normal);
	this->clicked.setTexture(*clicked);
	this->currentSpr = &this->normal;
	current = false;
	this->normal.setPosition(location);
	this->clicked.setPosition(location);
	text.setString(words);
	text.setPosition(location.x + 3, location.y + 3);
	text.setCharacterSize(14);	


}

void Button::checkClick(sf::Vector2f mousePos) {
	if (mousePos.x>currentSpr->getPosition().x && mousePos.x<(currentSpr->getPosition().x + currentSpr->getGlobalBounds().width)) {
		if (mousePos.y>currentSpr->getPosition().y && mousePos.y<(currentSpr->getPosition().y + currentSpr->getGlobalBounds().height)) {
			setState(!current);
		}
	}
}

void Button::setState(bool which) {
	current = which;
	if (current) {
		currentSpr = &clicked;
		return;
	}
	currentSpr = &normal;
}
void Button::setText(std::string words) {
	text.setString(words);
}
bool Button::getVar() {
	return current;
}
sf::Sprite* Button::getSprite() {
	return currentSpr;
}

sf::Text * Button::getText() {
	return &text;
}