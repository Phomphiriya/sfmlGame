#pragma once
#include<SFML/Graphics.hpp>
class Player
{
public:
	sf::Sprite spaceship01;
	Player(sf::Vector2f hi, int W, int H , sf::Vector2f); 
	~Player();
	
	void update();
	void draw(sf::RenderWindow& window);
	void move();
	const sf::Vector2f spaceship01_position();
private:
	sf::Texture ship;
	sf::Vector2f shipposition; 
	int W;
	int H;
};