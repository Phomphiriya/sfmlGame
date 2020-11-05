#include "Text.h"
Text::Text() 
{
	font.loadFromFile("font.ttf");
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
	text1.setCharacterSize(25);
	text1.setString(num.str());
	window.draw(text1);
}
