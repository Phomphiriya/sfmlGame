#include "Comet.h"

Comet::Comet( bool SL)
{
	Texture_Comet_big.loadFromFile("Spaceship/BigComet.png");
	Texture_Comet_small.loadFromFile("Spaceship/SmallComet.png");
	if (SL)
	{
		Comet_obj.setTexture(&Texture_Comet_big);
		Comet_obj.setSize(sf::Vector2f(Texture_Comet_big.getSize().x, Texture_Comet_big.getSize().y));
		Comet_obj.setOrigin(sf::Vector2f(Comet_obj.getSize().x / 2, Comet_obj.getSize().y / 2));
		CometHP = 3;
		this->CometHPMAX = CometHP;
		this->HPbar.setOrigin(HPbar.getSize().x / 2, HPbar.getSize().y / 2);
	}

	else
	{
		Comet_obj.setTexture(&Texture_Comet_small);
		Comet_obj.setSize(sf::Vector2f(Texture_Comet_small.getSize().x, Texture_Comet_small.getSize().y));
		Comet_obj.setOrigin(sf::Vector2f(Comet_obj.getSize().x / 2, Comet_obj.getSize().y / 2));
		this->CometHPMAX = CometHP;
		this->HPbar.setOrigin(HPbar.getSize().x / 2, HPbar.getSize().y / 2);
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

void Comet::update()
{
	HPbar.setSize(sf::Vector2f(45 * (CometHP/CometHPMAX), 5));
	HPbar.setPosition(sf::Vector2f(Comet_obj.getPosition().x, Comet_obj.getPosition().y));
}
