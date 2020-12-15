#include "item.h"

item::item(int type, float spawnX, sf::Texture* texture1, sf::Texture* texture2, sf::Texture* texture3, sf::Texture* texture4)
{
	typeitems = type;
	if (type == 1)
	{
		item_obj.setTexture(*texture1);
		item_obj.setPosition(spawnX, 0);
		item_obj.setOrigin(sf::Vector2f(texture1->getSize().x / 2, texture1->getSize().y / 2));
	}
	if (type == 2)
	{
		item_obj.setTexture(*texture2);
		item_obj.setPosition(spawnX, 0);
		item_obj.setOrigin(sf::Vector2f(texture2->getSize().x / 2, texture2->getSize().y / 2));
	}
	if (type == 3)
	{
		item_obj.setTexture(*texture3);
		item_obj.setPosition(spawnX, 0);
		item_obj.setOrigin(sf::Vector2f(texture3->getSize().x / 2, texture3->getSize().y / 2));
	}
	if (type == 4)
	{
		item_obj.setTexture(*texture4);
		item_obj.setPosition(spawnX, 0);
		item_obj.setOrigin(sf::Vector2f(texture4->getSize().x / 2, texture4->getSize().y / 2));
	}
	item_obj.setScale(3, 3);
}

item::~item()
{
}

void item::draw(sf::RenderWindow& window)
{
	window.draw(item_obj);
}

void item::update(float deltatime)
{
	item_obj.setRotation(rotate);
	offsetrotate += deltatime;
	if (offsetrotate >= 0.02)
	{
		offsetrotate -= 0.02;
		rotate++;
		if (rotate >= 360)
		{
			rotate = 0;
		}
	}
}
