#pragma once
#include<SFML/Graphics.hpp>
class item
{
public:
	item(int type, float spawnX, sf::Texture* texture1, sf::Texture* texture2, sf::Texture* texture3, sf::Texture* texture4);
	~item();
	sf::Sprite item_obj;
	int typeitems;
	void draw(sf::RenderWindow& window);
	void update(float deltatime);
private:
	float rotate = 0;
	float offsetrotate = 0;
};

