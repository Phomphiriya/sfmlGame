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
	sf::Text text4;
	Text();
	~Text();
	void text_1(float number, sf::Vector2f position, sf::RenderWindow& window , string message);
	void text_2(float number, sf::Vector2f position, sf::RenderWindow& window, string message, float stop);
	void text_3(sf::Vector2f position, sf::RenderWindow& window, string message, float stop);
	void text_4(sf::Vector2f position, sf::RenderWindow& window, string message, float stop);
	sf::RectangleShape hitbox_menu;
	sf::Vector2f getscale() { return sf::Vector2f(text3.getScale().x, text3.getScale().y); }
	sf::Vector2f getsize() { return sf::Vector2f(text3.getGlobalBounds().width, text3.getGlobalBounds().height); }

private:
	sf::Font font;
	int dx = 0;
	int dy = 10;
	sf::Vector2f position;
	bool flag = false;
};