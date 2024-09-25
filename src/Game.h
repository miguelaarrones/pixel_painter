//
// Created by miguelaarrones on 16/09/2024.
//

#ifndef GAME_H
#define GAME_H

#include "GridManager.h"
#include "UI.h"
#include "Window.h"

class Game {
public:
    Game();
    ~Game();

    bool isMouseOverButton(const sf::RectangleShape &button, sf::Vector2i mousePos);
    void checkButtonClick(const std::vector<Button> & buttons, sf::Vector2i mousePos);

    void HandleInput();
    void Update();
    void Render();

    Window* GetWindow();

private:
    Window window;
    sf::Clock clock;
    sf::Time elapsed;

    GridManager gridManager;

    UI ui;

    sf::Color currentColor = sf::Color::Black;
};
#endif //GAME_H
