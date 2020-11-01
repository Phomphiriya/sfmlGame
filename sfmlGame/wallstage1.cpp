#include "wallstage1.h"

wallstage1::wallstage1()
{
	tbgstage1.loadFromFile("Wallpaper/wallstage1.png");
	bgstage1.setTexture(tbgstage1);

}

wallstage1::~wallstage1()
{
}

void wallstage1::update(float deltatime)
{
	bgstage1.setTextureRect(sf::IntRect(0, i_bg, 607, 1000));

	offset += deltatime;
	if(offset >= speed)
	{
		offset -= speed;
		i_bg-=3;
	}
	if (i_bg <= 0)
	{
		i_bg = 1803;
	}


}

void wallstage1::draw(sf::RenderWindow& window)
{
	window.draw(bgstage1);
}
