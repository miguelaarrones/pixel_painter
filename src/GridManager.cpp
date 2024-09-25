//
// Created by miguelaarrones on 24/09/2024.
//

#include "GridManager.h"

#include <fstream>
#include <iostream>

GridManager::GridManager(int gridWidth, int gridHeight, int cellSize) {
    this->offset = 50;
    this->width = gridWidth / cellSize;
    this->height = gridHeight / cellSize;
    this->cellSize = cellSize;

    grid = new sf::RectangleShape*[width];
    for (int x = 0; x < width; x++) {
        grid[x] = new sf::RectangleShape[height];
        for (int y = 0; y < height; y++) {
            grid[x][y] = sf::RectangleShape();
            grid[x][y].setSize(sf::Vector2f(cellSize, cellSize));
            grid[x][y].setPosition(sf::Vector2f((x * cellSize) + offset, (y * cellSize) + offset));
            grid[x][y].setFillColor(sf::Color::White);
            grid[x][y].setOutlineColor(sf::Color::Black);
            grid[x][y].setOutlineThickness(1);
        }
    }
}

GridManager::~GridManager() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            delete grid[y];
        }
        delete grid[x];
    }
    delete grid;
}

sf::RectangleShape **GridManager::getGrid() {
    return grid;
}

sf::RectangleShape *GridManager::getCell(sf::Vector2i screenPosition) {
    int x = (screenPosition.x - offset) / cellSize;
    int y = (screenPosition.y - offset) / cellSize;

    // Check if the position is within the grid bounds
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &grid[x][y];
    }

    return nullptr;
}

sf::Color GridManager::getGridColor(int colorId) {
    switch (colorId) {
        case 0:
            return sf::Color::White;
        case 1:
            return sf::Color::Red;
        case 2:
            return sf::Color::Green;
        case 3:
            return sf::Color::Blue;
        case 4:
            return sf::Color::Black;
        case 5:
            return sf::Color::Yellow;
        case 6:
            return sf::Color::Magenta;
        case 7:
            return sf::Color::Cyan;
    }
    return sf::Color::White;
}

int GridManager::getIntValueFromColor(sf::Color color) {
    if (color == sf::Color::White) {
        return 0;
    }
    if (color == sf::Color::Red) {
        return 1;
    }
    if (color == sf::Color::Green) {
        return 2;
    }
    if (color == sf::Color::Blue) {
        return 3;
    }
    if (color == sf::Color::Black) {
        return 4;
    }
    if (color == sf::Color::Yellow) {
        return 5;
    }
    if (color == sf::Color::Magenta) {
        return 6;
    }
    if (color == sf::Color::Cyan) {
        return 7;
    }

    return 0;
}

void GridManager::clearGrid() {
    for (size_t x = 0; x < width; x++) {
        for (size_t y = 0; y < height; y++) {
            grid[x][y].setFillColor(sf::Color::White);
        }
    }
}

void GridManager::loadFromFile() {
    clearGrid();

    std::string line;
    std::ifstream file("resources/drawings/draw.txt");
    if (file.is_open()) {
        int x = 0;
        while (file) {
            std::getline (file, line);

            if (line.empty())
                continue;

            int y = 0;
            for (auto c: line) {
                grid[x][y].setFillColor(getGridColor(c - '0'));
                ++y;
            }
            ++x;
        }
    }
}

void GridManager::saveToFile() {
    std::ofstream file;
    file.open("resources/drawings/draw.txt");

    for (int x = 0; x < width; x++) {
        std::string line;
        for (int y = 0; y < height; y++) {
            int value = getIntValueFromColor(grid[x][y].getFillColor());
            line.append(std::to_string(value));
        }
        file << line << "\n";
    }

    file.close();
}

void GridManager::draw(sf::RenderWindow &window) {
    for (size_t x = 0; x < width; x++) {
        for (size_t y = 0; y < height; y++) {
            window.draw(grid[x][y]);
        }
    }
}
