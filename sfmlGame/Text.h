#pragma once
#include<SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Player.h"
using namespace std;
class Text
{
public:
	Text();
	~Text();
	void text_1(float number, sf::Vector2f position, sf::RenderWindow& window);
private:
	sf::Font font;
};

