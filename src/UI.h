//
// Created by miguelaarrones on 24/09/2024.
//

#ifndef UI_H
#define UI_H
#include "Button.h"
#include "SFML/Graphics.hpp"


class UI {
private:
    sf::Font font;

    sf::Text infoText;

    sf::RectangleShape loadButton;
    sf::Text loadButtonText;

    sf::RectangleShape saveButton;
    sf::Text saveButtonText;

    sf::RectangleShape cleanButton;
    sf::Text cleanButtonText;

    std::vector<Button> buttons;

    sf::RectangleShape whiteColorButton;
    sf::RectangleShape redColorButton;
    sf::RectangleShape greenColorButton;
    sf::RectangleShape blueColorButton;
    sf::RectangleShape blackColorButton;

public:
    UI();

    void draw(sf::RenderWindow &window);

    sf::RectangleShape getSaveButton();
    sf::RectangleShape getLoadButton();
    sf::RectangleShape getCleanButton();

    sf::Text &getInfoText();

    std::vector<Button> getButtons();
};

inline std::vector<Button> UI::getButtons() {
    return buttons;
}


#endif //UI_H
