//
// Created by miguelaarrones on 24/09/2024.
//

#include "Button.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text, sf::Font &font, ButtonType type) {
    this->rect = sf::RectangleShape(size);
    this->rect.setPosition(position);
    this->rect.setFillColor(color);
    this->rect.setOutlineColor(sf::Color::White);
    this->rect.setOutlineThickness(0.8f);

    this->text = sf::Text(text, font);
    this->text.setCharacterSize(30);
    this->text.setOrigin(this->text.getLocalBounds().width / 2, this->text.getLocalBounds().height / 2 );
    this->text.setPosition(sf::Vector2f(position.x + 50, position.y + 5));

    this->type = type;
}

Button::~Button() {
}

sf::RectangleShape &Button::getRectangleShape() {
    return this->rect;
}

ButtonType Button::getButtonType() {
    return type;
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(this->rect);
    window.draw(this->text);
}
