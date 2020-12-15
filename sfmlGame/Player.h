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
	void move(float deltatime);
	const sf::Vector2f spaceship01_position();
	const sf::Vector2f position() { return spaceship01.getPosition(); };
public:
	float dx = 0;
	float dy = 0;
	float speed = 200;

private:
	sf::Texture ship;
	sf::Vector2f shipposition; 
	int W;
	int H;
	
	sf::Vector2f movement;
};