#include "PBullet.h"

PBullet::PBullet(int W, int H)
{
	laser.loadFromFile("Shoot/Lasersung.png");
	PLaser.setTexture(laser);
	

	
}

PBullet::~PBullet()
{
}

void PBullet::update(sf::Vector2f Playerposition)
{
	sf::Vector2f spawnPoint(Playerposition);
	PLaser.setTextureRect(sf::IntRect(0, 0, laser.getSize().x, laser.getSize().y));
	PLaser.setScale(2, 2);
	PLaser.setPosition(Playerposition);
}

void PBullet::draw(sf::RenderWindow& window)
{
	window.draw(PLaser);
}

void PBullet::move()
{
}

