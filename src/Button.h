//
// Created by miguelaarrones on 24/09/2024.
//

#ifndef BUTTONBASE_H
#define BUTTONBASE_H
#include <string>

#include "ButtonType.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

class Button {
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color color, std::string text, sf::Font &font, ButtonType type);
    ~Button();

    ButtonType getButtonType();
    sf::RectangleShape &getRectangleShape();

    void draw(sf::RenderWindow &window);
private:
    ButtonType type;

    sf::RectangleShape rect;
    sf::Text text;
};




#endif //BUTTONBASE_H
