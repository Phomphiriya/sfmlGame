#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<math.h>
#include<cstdlib>
#include "Player.h"
#include "Text.h"
#include "Sound.h"
#include "Enemy.h"
#include "PBullet.h"
#include "wallstage1.h"
#include <vector>

const int W = 607;
const int H = 1000;




int main()
{
	sf::Clock clock;
	srand(time(NULL));
	Enemy Enemy1;
	PBullet PBullet1;
	wallstage1 wallstage1;
	Sound Sound;
	Text Text1;
	Text Text2;
	Player Player1(sf::Vector2f(10.0, 10.0) ,W ,H , sf::Vector2f(280.0f,780.0f));
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	//sf::Texture
	sf::Texture Boss1;
	Boss1.loadFromFile("Spaceship/boos1new.png");
	sf::Sprite bossstage1(Boss1);
	sf::Texture playerlaser;
	playerlaser.loadFromFile("Shoot/Laser.png");
	
	
	//-----------Boss
	sf::Vector2f bossspawnPoint = { 120.f,-150.f };
	bossstage1.setPosition(bossspawnPoint);
	bossstage1.setScale(0.5, 0.5);
	
	//----------Enemy&Bullet
	std::vector<Enemy> enemies;
	std::vector<PBullet> PBullets;
	int enemySpawnTimer = 0;
	int shootTimer = 0;
	
	
	Sound.intro.play();
	// Start game loop
	while (window.isOpen())
	{
		
		sf::Time time = clock.restart();
		sf::Event e;
		float deltatime = time.asSeconds();
		float totaltime = 0;
		while (window.pollEvent(e));
		{
			if (e.type == e.Closed)
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		//----------SHOOTING
		if (shootTimer < 15)
			shootTimer++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 15)
		{
			Sound.shoot_effect.play();
			PBullet1.update(Player1.spaceship01_position());
			PBullets.push_back(PBullet(PBullet1));
			shootTimer = 0;
		}
		for (size_t i = 0; i < PBullets.size(); i++)
		{


			if (PBullets[i].PLaser.getPosition().y <= 0)
				PBullets.erase(PBullets.begin() + i);
		}
		for (size_t i = 0; i < PBullets.size(); i++)
		{
			PBullets[i].PLaser.move(0.f, -10.f);

		}
		//-----------ENEMY
		if (enemySpawnTimer < 50)
			enemySpawnTimer++;
		if (enemySpawnTimer >= 50)
		{
			Enemy1.redship.setPosition( rand() % int(window.getSize().x - Enemy1.redship.getGlobalBounds().width) + Enemy1.redship.getGlobalBounds().width  , 0.f);
			enemies.push_back(Enemy(Enemy1));
			enemySpawnTimer = 0;
		}
		for (size_t i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].redship.getPosition().y > window.getSize().y)
				enemies.erase(enemies.begin() + i);
		}
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].redship.move(0, 3.f);
		}
		wallstage1.update(deltatime);

		//-----------Collision
		for (size_t i = 0; i < PBullets.size(); i++)
		{
			for (size_t k = 0; k < enemies.size(); k++)
			{
				if (PBullets[i].PLaser.getGlobalBounds().intersects(enemies[k].redship.getGlobalBounds()))
				{
					PBullets.erase(PBullets.begin() + i);
					enemies.erase(enemies.begin() + k);
					break;
				}
			}
		}

		window.clear();
		Player1.update();
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].update();
		}
		
		Player1.move(deltatime);
		wallstage1.draw(window);

		//window.draw(swall);
		for (size_t i = 0; i < enemies.size(); i++)
		{
			window.draw(enemies[i].redship);
		}
		for (size_t i = 0; i < PBullets.size(); i++)
		{
			window.draw(PBullets[i].PLaser);
		}
		//Enemy1.draw(window);
		Player1.draw(window);
		window.display();
		
		//window.draw(bossstage1);
		
		//Text1.text_1(Player1.spaceship01_position().x, sf::Vector2f(90.0f, 250.0), window);
		//Text2.text_1(Player1.spaceship01_position().y, sf::Vector2f(90.0f, 200.0f), window);
		
	}
	return 0;
}