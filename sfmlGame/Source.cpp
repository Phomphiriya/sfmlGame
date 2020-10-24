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

const int W = 607;
const int H = 1000;

int main()
{
	sf::Clock clock;
	srand(time(NULL));
	Enemy Enemy1(10);
	PBullet PBullet1(W, H);
	Sound Sound(10);
	Text Text1(10);
	Text Text2(10);
	Player Player1(sf::Vector2f(10.0, 10.0) ,W ,H , sf::Vector2f(280.0f,780.0f));
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(1000);
	
	//-------Wallpaper--------//
	sf::Texture wall;
	wall.loadFromFile("Wallpaper/wallpapertest03.jpg");
	sf::Sprite swall(wall);
	swall.setScale(2.2, 2);
	sf::Texture playerlaser;
	playerlaser.loadFromFile("Shoot/Laser.png");
	
	//sf::Texture
	sf::Texture enemyship;
	enemyship.loadFromFile("Spaceship/enemyship.png");
	sf::Sprite redship(enemyship);
	sf::Texture Boss1;
	Boss1.loadFromFile("Spaceship/boos1new.png");
	sf::Sprite bossstage1(Boss1);


	//--------Sprite Size--------//
	
	sf::Vector2f bossspawnPoint = { 120.f,-150.f };
	bossstage1.setPosition(bossspawnPoint);
	bossstage1.setScale(0.5, 0.5);
	
	int shootTimer = 20;
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
		
		if (shootTimer < 20)
			shootTimer++;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& shootTimer >= 20)
		{
			Sound.shoot_effect.play();
			
			PBullet1.update(Player1.spaceship01_position());
			shootTimer = 0;

		}
		if (bossstage1.getGlobalBounds().intersects(Player1.spaceship01.getGlobalBounds()))
		{
			printf("collide!!!!");
		}
		
		window.display();

		Player1.update();
		Player1.move();
		Enemy1.update();
		window.clear();
		
		//window.draw(swall);
		Enemy1.draw(window);
		Player1.draw(window);
		window.draw(PBullet1.PLaser);
		//window.draw(bossstage1);
		
		//Text1.text_1(Player1.spaceship01_position().x, sf::Vector2f(90.0f, 250.0), window);
		//Text2.text_1(Player1.spaceship01_position().y, sf::Vector2f(90.0f, 200.0f), window);
		
	}
	return 0;
}