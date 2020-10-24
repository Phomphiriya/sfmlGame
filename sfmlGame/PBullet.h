#pragma once
#include<SFML/Graphics.hpp>
class PBullet
{
public:
	sf::Sprite PLaser;
	PBullet(int W, int H);
	~PBullet();

	void update(sf::Vector2f Playerposition);
	void draw(sf::RenderWindow& window);
	void move();

private:
	sf::Texture laser;
	sf::Vector2f laserposition;
	int W;
	int H;
};

