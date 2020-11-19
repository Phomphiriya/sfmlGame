#include "Player.h"
Player::Player(sf::Vector2f hi , int W , int H ,sf::Vector2f position)
{
	this->W = W;
	this->H = H;
	ship.loadFromFile("Spaceship/shipA1.png");
	spaceship01.setTexture(ship);
	shipposition.x = ship.getSize().x / 3;
	shipposition.y = ship.getSize().y / 3;
	spaceship01.setPosition(position);
}

void Player::update()
{
	spaceship01.setTextureRect(sf::IntRect(shipposition.x * 1, shipposition.y * 1, shipposition.x, shipposition.y));
	spaceship01.setScale(1.5,1.5);
}


Player::~Player() {}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(spaceship01);
}

void Player::move(float deltatime)
{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& spaceship01.getPosition().x < W - 60)
			{
				dx = 1;
				spaceship01.setTextureRect(sf::IntRect(shipposition.x * 2, shipposition.y * 2, shipposition.x, shipposition.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && spaceship01.getPosition().x > 5)
			{
				dx = -1;
				spaceship01.setTextureRect(sf::IntRect(shipposition.x * 0, shipposition.y * 2, shipposition.x, shipposition.y));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && spaceship01.getPosition().y > 10)
			{
				dy = -1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && spaceship01.getPosition().y < H - 70)
			{
				dy = 1;
			}
			
			if (spaceship01.getPosition().x > W)
			{
				spaceship01.setPosition(0, spaceship01.getPosition().y);
			}
			if (spaceship01.getPosition().x < -30) 
			{
				spaceship01.setPosition(W, spaceship01.getPosition().y);
			}
			movement.x = dx * speed * deltatime;
			movement.y = dy * speed * deltatime;
			spaceship01.move(movement);
			dx = 0;
			dy = 0;
}
const sf::Vector2f Player::spaceship01_position()
{
	return sf::Vector2f(spaceship01.getPosition());
}