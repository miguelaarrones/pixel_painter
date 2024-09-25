//
// Created by miguelaarrones on 24/09/2024.
//

#ifndef GRID_H
#define GRID_H
#include "SFML/Graphics.hpp"


class GridManager {
public:
    GridManager(int gridWidth, int gridHeight, int cellSize);
    ~GridManager();

    sf::RectangleShape **getGrid();
    sf::RectangleShape *getCell(sf::Vector2i screenPosition);
    sf::Color getGridColor(int colorId);
    int getIntValueFromColor(sf::Color color);

    void clearGrid();
    void loadFromFile();
    void saveToFile();

    void draw(sf::RenderWindow &window);

private:
    sf::RectangleShape **grid;
    int height, width, cellSize;
    int offset;
};

#endif //GRID_H
