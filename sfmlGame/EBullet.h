#pragma once
#include<SFML/Graphics.hpp>
class EBullet
{
public:
	sf::Sprite ELaser;
	EBullet();
	~EBullet();

	void update(sf::Vector2f Enemyposition);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture Redlaser;
	sf::Vector2f Redlaserposition;
};

