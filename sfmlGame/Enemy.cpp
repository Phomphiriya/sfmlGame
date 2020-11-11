#include "Enemy.h"
//#include "Enemy.h"

Enemy::Enemy(int EnemyHP):EnemyHP(EnemyHP)
{
	enemyship.loadFromFile("Spaceship/enemyship.png");
	redship.setTexture(enemyship);
	this->enemyshipX = enemyship.getSize().x/3;
	this->enemyshipY = enemyship.getSize().y/1;
	HPbar.setFillColor(sf::Color::Red);
}

Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(redship);
	window.draw(HPbar);
}

void Enemy::update()
{
	HPbar.setSize(sf::Vector2f(15 * EnemyHP, 5));
	HPbar.setPosition(sf::Vector2f(redship.getPosition().x -1, redship.getPosition().y-15));
	redship.setScale(1.25, 1.25);
	redship.setTextureRect(sf::IntRect(enemyshipX * 1, enemyshipY*0, enemyshipX, enemyshipY));
}
