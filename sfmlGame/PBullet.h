#pragma once
#include<SFML/Graphics.hpp>
class PBullet
{
public:
	sf::Sprite PLaser;
	PBullet();
	~PBullet();

	void update(sf::Vector2f Playerposition);
	void draw(sf::RenderWindow& window);
	

private:
	sf::Texture laser;
	sf::Vector2f laserposition;
};

