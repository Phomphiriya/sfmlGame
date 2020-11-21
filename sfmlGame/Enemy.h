#pragma once
#include<SFML/Graphics.hpp>
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
	float dx = 1;
	float dy = 0;
	bool dead = false;
private:
	sf::Texture enemyship;
	sf::Texture explosion;
};

