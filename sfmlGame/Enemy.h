#pragma once
#include<SFML/Graphics.hpp>
//#include"PBullet.h"
class Enemy
{
public:
	int enemyshipX;
	int enemyshipY;
	Enemy(int EnemyHP);
	~Enemy();
	sf::RectangleShape HPbar;
	sf::Sprite redship;
	void draw(sf::RenderWindow& window);
	void update();
	int EnemyHP;
private:
	sf::Texture enemyship;
};

