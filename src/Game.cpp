//
// Created by miguelaarrones on 16/09/2024.
//

#include "Game.h"

Game::Game() : window("Pixel Painter", sf::Vector2u(800, 800)),
               gridManager(700, 700, 20) {}

Game::~Game() {

}

bool Game::isMouseOverButton(const sf::RectangleShape &button, sf::Vector2i mousePos) {
    return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Game::checkButtonClick(const std::vector<Button> &buttons, sf::Vector2i mousePos) {
    for (auto button: buttons) {
        if (isMouseOverButton(button.getRectangleShape(), mousePos)) {
            switch (button.getButtonType()) {
                case ButtonType::COLOR:
                    currentColor = button.getRectangleShape().getFillColor();
                    break;
                case ButtonType::CLEAR:
                    gridManager.clearGrid();
                    break;
                case ButtonType::LOAD:
                    ui.getInfoText().setString("File loaded successfully");
                    gridManager.loadFromFile();
                    break;
                case ButtonType::SAVE:
                    ui.getInfoText().setString("File saved successfully");
                    gridManager.saveToFile();
                    break;
            }
        }
    }
}

void Game::HandleInput() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window.GetRenderWindow());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        // Check if a button is being pressed.
        checkButtonClick(ui.getButtons(), mousePos);

        // Check if painting inside the grid.
        if (mousePos.x >= 50 && mousePos.x <= 750 && mousePos.y >= 50 && mousePos.y <= 750) {
            sf::RectangleShape *c = gridManager.getCell(mousePos);
            c->setFillColor(currentColor);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if (mousePos.x >= 50 && mousePos.x <= 750 && mousePos.y >= 50 && mousePos.y <= 750) {
            sf::RectangleShape *c = gridManager.getCell(sf::Mouse::getPosition(window.GetRenderWindow()));
            c->setFillColor(sf::Color::White);
        }
    }
}

void Game::Update() {
    window.Update();
}

void Game::Render() {
    window.BeginDraw();

    gridManager.draw(window.GetRenderWindow());
    ui.draw(window.GetRenderWindow());

    window.EndDraw();
}

Window *Game::GetWindow() {
    return &window;
}





