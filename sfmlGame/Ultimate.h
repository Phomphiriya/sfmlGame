#pragma once
#include<SFML/Graphics.hpp>
class Ultimate
{
public:
	Ultimate(sf::Vector2f Playerposition,sf::Texture& texture1);
	~Ultimate();
	sf::Sprite Pball;
	sf::Sprite Pball2;
	sf::Sprite Pball3;
	sf::Sprite Pball4;	
	sf::Sprite Pball5;
	sf::Sprite Pball6;
	sf::Sprite Pball7;

	void update();
	void update2();
	void update3();
	void update4();
	void update5();
	void update6();
	void update7();

	void draw(sf::RenderWindow& window);
private:
	sf::Texture ball;
	sf::Texture ball2;
	sf::Texture ball3;
	sf::Texture ball4;
	sf::Texture ball5;
	sf::Texture ball6;
	sf::Texture ball7;
	sf::Vector2f ballposition;
};