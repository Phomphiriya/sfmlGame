#pragma once
#include<SFML/Graphics.hpp>
class wallstage1
{
public:
	wallstage1();
	~wallstage1();
	sf::Sprite bgstage1;
	void update(float deltatime);
	void draw(sf::RenderWindow& window);

private:
	sf::Texture tbgstage1;
	float i_bg = 5000;
	float offset = 0;
	float speed = 0.01;
};