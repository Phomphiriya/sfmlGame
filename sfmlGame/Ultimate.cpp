#include "Ultimate.h"

Ultimate::Ultimate(sf::Vector2f Playerposition, sf::Texture &texture1)
{
	Pball.setTexture(texture1);
	Pball.setPosition(Playerposition);
	Pball.setScale(2, 2);

	Pball2.setTexture(texture1);
	Pball2.setPosition(Playerposition);
	Pball2.setScale(2, 2);

	Pball3.setTexture(texture1);
	Pball3.setPosition(Playerposition);
	Pball3.setScale(2, 2);

	Pball4.setTexture(texture1);
	Pball4.setPosition(Playerposition);
	Pball4.setScale(2, 2);

	Pball5.setTexture(texture1);
	Pball5.setPosition(Playerposition);
	Pball5.setScale(2, 2);

	Pball6.setTexture(texture1);
	Pball6.setPosition(Playerposition);
	Pball6.setScale(2, 2);

	Pball7.setTexture(texture1);
	Pball7.setPosition(Playerposition);
	Pball7.setScale(2, 2);
	
}

Ultimate::~Ultimate()
{
}

void Ultimate::update()
{
	Pball.move(0.f, -7.f);
}

void Ultimate::update2()
{
	Pball2.move(1.26f, -7.12f);
}

void Ultimate::update3()
{
	Pball3.move(2.53f, -7.92f);
}

void Ultimate::update4()
{
	Pball4.move(-1.26f, -7.12f);
}

void Ultimate::update5()
{
	Pball5.move(-2.53f, -7.92f);
}

void Ultimate::update6()
{
	Pball6.move(1.86f, -7.5f);
}

void Ultimate::update7()
{
	Pball7.move(-1.86f, -7.5f);
}


void Ultimate::draw(sf::RenderWindow& window)
{
	window.draw(Pball);
	window.draw(Pball2);
	window.draw(Pball3);
	window.draw(Pball4);
	window.draw(Pball5);
	window.draw(Pball6);
	window.draw(Pball7);
}
