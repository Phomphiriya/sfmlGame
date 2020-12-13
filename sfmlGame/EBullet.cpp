#include "EBullet.h"

EBullet::EBullet()
{
	Redlaser.loadFromFile("Shoot/RedLaser.png");
	ELaser.setTexture(Redlaser);
}

EBullet::~EBullet()
{
}

void EBullet::update(sf::Vector2f Enemyposition)
{
	sf::Vector2f spawnPoint(Enemyposition);
	ELaser.setTextureRect(sf::IntRect(0, 0, Redlaser.getSize().x, Redlaser.getSize().y));
	ELaser.setScale(2, 2);
	ELaser.setPosition(Enemyposition);
}


void EBullet::draw(sf::RenderWindow& window)
{
	window.draw(ELaser);
}
