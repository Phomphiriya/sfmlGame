#include "Text.h"
Text::Text() 
{
	font.loadFromFile("font/8bitnew.ttf");

}

Text::~Text()
{
}

void Text::text_1(float number, sf::Vector2f position , sf::RenderWindow &window , string message)
{
	sf::Text text1;
	text1.setFont(font);
	stringstream num;
	num << message << number  ;
	text1.setPosition(position);
	text1.setCharacterSize(20);
	text1.Bold;
	text1.setFillColor(sf::Color (224,67,54));
	text1.setString(num.str());
	window.draw(text1);
}

void Text::text_2(float number, sf::Vector2f position, sf::RenderWindow& window, string message , float stop )
{
	text2.setFont(font);

	if (!flag)
	{
		text2.setPosition(position);
		flag = true;
	}
	stringstream num;
	num << message << number;
	text2.move(dx, -dy);
	text2.setCharacterSize(20);
	text2.Bold;
	text2.setFillColor(sf::Color(224, 67, 54));
	text2.setString(num.str());
	if (text2.getPosition().y < stop)
	{
		dy = 0;
	}
	window.draw(text2);
}

void Text::text_3(sf::Vector2f position, sf::RenderWindow& window, string message, float stop)
{
	text3.setFont(font);

	if (!flag)
	{
		text3.setPosition(position);
		flag = true;
	}
	stringstream num;
	num << message;
	text3.move(dx, dy);
	text3.setCharacterSize(70);
	text3.Bold;
	text3.setFillColor(sf::Color(88, 111, 173));
	text3.setString(num.str());
	if (text3.getPosition().y > stop)
	{
		dy = 0;
	}
	window.draw(text3);
}
