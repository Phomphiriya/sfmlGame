#pragma once
#include<SFML/Graphics.hpp>
class Comet
{
public:
	Comet(bool SL);
	~Comet();
	sf::RectangleShape HPbar;
	sf::RectangleShape Comet_obj;
	void draw(sf::RenderWindow& window);
	void update();
	int CometHP;
	int CometHPMAX;
	bool dead = false;
private:
	sf::Texture Texture_Comet_big;
	sf::Texture Texture_Comet_small;

};

