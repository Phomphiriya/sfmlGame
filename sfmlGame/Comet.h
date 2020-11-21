#pragma once
#include<SFML/Graphics.hpp>
class Comet
{
public:
	Comet(bool SL , float spawnX , sf::Texture *texture1 , sf::Texture* texture2);
	~Comet();
	sf::RectangleShape HPbar;
	sf::Sprite Comet_obj;
	void draw(sf::RenderWindow& window);
	void update(float deltatime);
	int CometHP;
	int CometHPMAX;
	bool dead = false;
private:
	

	float rotate = 0;
	float offsetrotate = 0;

};

