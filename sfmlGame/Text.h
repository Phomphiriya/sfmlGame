#pragma once
#include<SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "Player.h"
using namespace std;
class Text
{
public:
	sf::Text text2;
	sf::Text text3;
	Text();
	~Text();
	void text_1(float number, sf::Vector2f position, sf::RenderWindow& window , string message);
	void text_2(float number, sf::Vector2f position, sf::RenderWindow& window, string message, float stop);
	void text_3(sf::Vector2f position, sf::RenderWindow& window, string message, float stop);
private:
	sf::Font font;
	int dx = 0;
	int dy = 10;
	sf::Vector2f position;
	bool flag = false;
};