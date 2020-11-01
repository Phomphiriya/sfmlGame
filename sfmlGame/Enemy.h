#pragma once
#include<SFML/Graphics.hpp>
#include"PBullet.h"
class Enemy
{
public:
	int enemyshipX;
	int enemyshipY;
	Enemy();
	~Enemy();

	sf::Sprite redship;
	void draw(sf::RenderWindow& window);
	void update();
private:
	sf::Texture enemyship;
};

