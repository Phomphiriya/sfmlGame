#include "Enemy.h"
//#include "Enemy.h"

Enemy::Enemy(int hi)
{
	enemyship.loadFromFile("Spaceship/enemyship.png");
	redship.setTexture(enemyship);
	int enemyshipX = enemyship.getSize().x/3;
	int enemyshipY = enemyship.getSize().y/1;
}

Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(redship);
}

void Enemy::update()
{
	redship.setScale(1.2, 1.2);
	//redship.setTextureRect(sf::IntRect(enemyshipX, enemyshipY, enemyshipX, enemyshipY));
}
