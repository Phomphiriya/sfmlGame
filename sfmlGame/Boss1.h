#pragma once
#include<SFML/Graphics.hpp>
class Boss1
{
public:
	Boss1(int BossHP);
	~Boss1();
	sf::Sprite UFO;

private:
	float rotate = 0;
	sf::Texture bossship;
};

