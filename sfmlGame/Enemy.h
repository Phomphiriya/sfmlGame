#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
public:
	int enemyshipX;
	int enemyshipY;
	Enemy(int EnemyHP);
	~Enemy();
	sf::RectangleShape HPbar;
	sf::Sprite redship;
	void draw(sf::RenderWindow& window);
	void update(const float& deltatime);
	void setPosition(float x);
	int EnemyHP;
	float dx = 1;
	float dy = 0;
	bool dead = false;
	float lifetime = 0.5;
	short int offsetBullet = 0;

	sf::Vector2f getCenter() { return sf::Vector2f(redship.getPosition().x + redship.getGlobalBounds().width / 2, redship.getPosition().y + redship.getGlobalBounds().height / 2); }

	//*
	const sf::Vector2f enemyship_position();
	const sf::Vector2f position() { return redship.getPosition(); };
private:
	sf::Texture enemyship;
	sf::Texture explosion;
	//*
	sf::Vector2f enemyposition;
};

