#include "Enemy.h"
//#include "Enemy.h"

Enemy::Enemy(int EnemyHP) :EnemyHP(EnemyHP)
{
	enemyship.loadFromFile("Spaceship/newenemy.png");
	redship.setTexture(enemyship);
	this->enemyshipX = enemyship.getSize().x/3;
	this->enemyshipY = enemyship.getSize().y/1;
	HPbar.setFillColor(sf::Color::Red);
	//explosion.loadFromFile("Explosion/KillEffect.png");
	redship.setScale(2, 2);
	HPbar.setOrigin(sf::Vector2f(redship.getPosition().x / 2, redship.getPosition().y / 2 ));
}

Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderWindow &window)
{
	window.draw(redship);
	window.draw(HPbar);
}

void Enemy::update(const float &deltatime)
{
	HPbar.setSize(sf::Vector2f(15 * EnemyHP, 5));
	HPbar.setPosition(sf::Vector2f(redship.getPosition().x+1, redship.getPosition().y-5));
	redship.setTextureRect(sf::IntRect(enemyshipX * dx, enemyshipY*0, enemyshipX, enemyshipY));
	
	offsetBullet++;
}
//*
const sf::Vector2f Enemy::enemyship_position()
{
	return sf::Vector2f(redship.getPosition());
}
void Enemy::setPosition(float x) {
	return redship.setPosition(0,0);
}
