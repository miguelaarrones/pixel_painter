//
// Created by miguelaarrones on 24/09/2024.
//

#include "UI.h"

UI::UI() {
    font.loadFromFile("resources/fonts/arial_narrow_7.ttf");

    infoText = sf::Text("", font);
    infoText.setCharacterSize(30);
    infoText.setOrigin(loadButtonText.getLocalBounds().width / 2, loadButtonText.getLocalBounds().height / 2 );
    infoText.setPosition(sf::Vector2f(410.0f, 755.0f));

    buttons.push_back(Button(
        sf::Vector2f(50.0f, 760.0f),
        sf::Vector2f(100.0f, 30.0f),
        sf::Color::Blue,
        "CLEAR",
        font,
        ButtonType::CLEAR));

    buttons.push_back(Button(
            sf::Vector2f(160.0f, 760.0f),
            sf::Vector2f(100.0f, 30.0f),
            sf::Color::Blue,
            "SAVE",
            font,
            ButtonType::SAVE));

    buttons.push_back(Button(
            sf::Vector2f(270.0f, 760.0f),
            sf::Vector2f(100.0f, 30.0f),
            sf::Color::Blue,
            "LOAD",
            font,
            ButtonType::LOAD));

    std::vector<sf::Color> colors = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Black,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan
    };

    sf::Vector2f position = sf::Vector2f(50.0f, 10.0f);
    for (auto color: colors) {
        buttons.push_back(Button(
        position,
        sf::Vector2f(50.0f, 30.0f),
        color,
        "",
        font,
        ButtonType::COLOR));

        position += sf::Vector2f(60.0f, 00.0f);
    }
}

void UI::draw(sf::RenderWindow &window) {
    window.draw(infoText);

    window.draw(loadButton);
    window.draw(loadButtonText);
    window.draw(saveButton);
    window.draw(saveButtonText);
    window.draw(cleanButton);
    window.draw(cleanButtonText);

    for (auto button: buttons) {
        button.draw(window);
    }
}

sf::RectangleShape UI::getSaveButton() {
    return saveButton;
}

sf::RectangleShape UI::getLoadButton() {
    return loadButton;
}

sf::RectangleShape UI::getCleanButton() {
    return cleanButton;
}

sf::Text &UI::getInfoText() {
    return infoText;
}
