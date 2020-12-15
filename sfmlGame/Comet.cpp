#include "Comet.h"

Comet::Comet( bool SL, float spawnX, sf::Texture* texture1, sf::Texture* texture2)
{
	typecomet = SL;
	if (SL)
	{
		Comet_obj.setTexture(*texture1);
		CometHP = 2;
		this->CometHPMAX = CometHP;
		this->HPbar.setOrigin(HPbar.getSize().x / 2, HPbar.getSize().y / 2);
		Comet_obj.setPosition(spawnX, 0);
		Comet_obj.setOrigin(sf::Vector2f(texture1->getSize().x / 2, texture1->getSize().y / 2));
	}

	else
	{
		Comet_obj.setTexture(*texture2);
		CometHP = 1;
		this->CometHPMAX = CometHP;
		this->HPbar.setOrigin(HPbar.getSize().x / 2, HPbar.getSize().y / 2);
		Comet_obj.setPosition(spawnX, 0);
		Comet_obj.setOrigin(sf::Vector2f(texture2->getSize().x / 2, texture2->getSize().y / 2));

	}


	HPbar.setFillColor(sf::Color::Red);
	Comet_obj.setScale(1.5, 1.5);
}

Comet::~Comet()
{
}

void Comet::draw(sf::RenderWindow& window)
{
	window.draw(Comet_obj);
	window.draw(HPbar);
}

void Comet::update(float deltatime)
{
	HPbar.setSize(sf::Vector2f((45 *CometHP)/CometHPMAX, 5));
	HPbar.setPosition(sf::Vector2f(Comet_obj.getPosition().x-20, Comet_obj.getPosition().y-30));
	Comet_obj.setRotation(rotate);
	offsetrotate += deltatime;
	if (offsetrotate >= 0.05)
	{
		offsetrotate -= 0.05;
		rotate++;
		if (rotate >= 360)
		{
			rotate = 0;
		}
	}
}
