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
	text1.setCharacterSize(15);
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
	text3.setCharacterSize(40);
	text3.Bold;
	stringstream num;
	num << message;
	text3.setString(num.str());
	
	if (!flag)
	{	
		text3.setPosition(position);
		text3.setOrigin(getsize().x / 2, getsize().y / 2);
		hitbox_menu.setOrigin(getsize().x / 2, getsize().y / 2);
		flag = true;
	}
	text3.move(dx, dy);
	if (text3.getPosition().y > stop)
	{
		dy = 0;
	}
	window.draw(text3);
	window.draw(hitbox_menu);
}
void Text::text_4(sf::Vector2f position, sf::RenderWindow& window, string message, float stop)
{
	text4.setFont(font);
	text4.setCharacterSize(65);
	text4.setFillColor(sf::Color(88, 111, 173));
	text4.Bold;
	stringstream num;
	num << message;
	text4.setString(num.str());
	text4.move(dx, dy);
	if (text4.getPosition().y > stop)
	{
		dy = 0;
	}
	window.draw(text4);
}

void Text::text_5(sf::Vector2f position, sf::RenderWindow& window, string message)
{
	text5.setFont(font);
	text5.setCharacterSize(30);
	text5.Bold;
	stringstream num;
	num << message;
	text5.setString(num.str());

	if (!flag)
	{
		text5.setPosition(position);
		text5.setOrigin(getsize().x / 2, getsize().y / 2);
		hitbox_menu.setOrigin(getsize().x / 2, getsize().y / 2);
		flag = true;
	}
	window.draw(hitbox_menu);
	window.draw(text5);
}

void Text::text_6(sf::Vector2f position, sf::RenderWindow& window, string message)
{
	text6.setFont(font);
	text6.setCharacterSize(30);
	text6.Bold;
	int R = rand() % 200;
	int G = rand() % 150;
	int B = rand() % 100;
	text6.setFillColor(sf::Color(R, G, B));
	stringstream num;
	num << message;
	text6.setString(num.str());
	text6.setOrigin(sf::Vector2f(text6.getGlobalBounds().width / 2, text6.getGlobalBounds().height / 2));
	text6.setPosition(position);
	window.draw(text6);
}

void Text::text_7(sf::Vector2f position, sf::RenderWindow& window, string message)
{
	text7.setFont(font);
	text7.setCharacterSize(30);
	text7.Bold;
	stringstream num;
	num << message;
	text7.setString(num.str());
	text7.setOrigin(sf::Vector2f(text7.getGlobalBounds().width / 2, text7.getGlobalBounds().height / 2));

	if (!flag)
	{
		text7.setPosition(position);
		text7.setOrigin(getsize().x / 2, getsize().y / 2);
		hitbox_menu.setOrigin(getsize().x / 2, getsize().y / 2);
		flag = true;
	}
	window.draw(hitbox_menu);
	window.draw(text7);
}

void Text::text_8(float number, sf::Vector2f position, sf::RenderWindow& window, string message ,sf::Vector3i color)
{
	sf::Text text8;
	text8.setFont(font);
	stringstream num;
	num << message << number;
	text8.setFillColor(sf::Color(color.x,color.y,color.z));
	text8.setPosition(position);
	text8.setCharacterSize(10);
	text8.Bold;
	text8.setString(num.str());
	window.draw(text8);
}
