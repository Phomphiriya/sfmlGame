#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
public:
	Enemy(int hi);
	~Enemy();
	void draw(sf::RenderWindow& window);
	void update();
private:
	sf::Texture enemyship;
	sf::Sprite redship;
};

