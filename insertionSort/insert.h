#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

class insert
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock* clock;
	sf::Time elapsed;
	sf::Font* font;

	int i, j;
	bool sortLoop;
	int switchesCount;
	int comparisonsCount;

	std::vector<sf::RectangleShape> shapes;

	void initVar();
	void initWindow();
	void initData();
	void drawData();

public:
	insert();
	~insert();
	const bool running() const;
	void update();
	void render();
	void pollEvent();
	void timeHandling();
	std::string passedTime();
	std::string switches();
	std::string comparisons();
	std::string finalString();
	void text(std::string t, int x, int y, int size);
	int randomNumGen(int f, int c);
	void sortLogic();
	std::string closingTime();
	void quit();
};

