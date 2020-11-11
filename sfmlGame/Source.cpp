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
	Enemy Enemy1(3);
	PBullet PBullet1;
	wallstage1 wallstage1;
	Sound Sound;
	Text Text1;
	Text Text2;
	Player Player1(sf::Vector2f(10.0, 10.0) ,W ,H , sf::Vector2f(280.0f,780.0f));
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	//sf::Texture
	/*sf::Texture Boss1;
	Boss1.loadFromFile("Spaceship/boos1new.png");
	sf::Sprite bossstage1(Boss1);*/

	sf::Texture HPBar;
	HPBar.loadFromFile("HP/HPYOU.png");
	sf::RectangleShape HPointBar(sf::Vector2f(330.0f,45.0f));
	HPointBar.setTexture(&HPBar);
	HPointBar.setPosition(270, 10);

	//------------Gameover---------------------------
	sf::Texture Gameover;
	Gameover.loadFromFile("Gameover/Oicon.png");
	sf::RectangleShape Overicon(sf::Vector2f(400, 200));
	Overicon.setTexture(&Gameover);
	Overicon.setOrigin(200, 100);
	Overicon.setPosition(303, 500);
	 
	//-----------Boss
	/*sf::Vector2f bossspawnPoint = { 120.f,-150.f };
	bossstage1.setPosition(bossspawnPoint);
	bossstage1.setScale(0.5, 0.5);*/
	
	//----------Enemy&Bullet
	std::vector<Enemy> enemies;
	std::vector<PBullet> PBullets;
	int enemySpawnTimer = 0;
	int shootTimer = 0;
	int EnemyKilled = 0;
	float TimeScore = 0;
	int HP = 10;

	//------------mouse
	sf::Texture mouse;
	mouse.loadFromFile("Wallpaper/mouse.png");
	window.setMouseCursorVisible(false);
	sf::Sprite cursorSprite(mouse);
	cursorSprite.setScale(0.10f, 0.10f);

	Sound.intro.play();
	// Start game loop
	while (window.isOpen())
	{

		cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		sf::Time time = clock.restart();
		sf::Event e;
		float deltatime = time.asSeconds();
		float totaltime = 0;
		TimeScore += deltatime;
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
		if (shootTimer < 20)
			shootTimer++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 20)
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
			PBullets[i].PLaser.move(0.f, -8.f);

		}

		//-----------ENEMY
		if (enemySpawnTimer < 70)
			enemySpawnTimer++;

		if (enemySpawnTimer >= 70)
		{
			Enemy1.redship.setPosition( rand() % int((window.getSize().x - Enemy1.redship.getGlobalBounds().width) - Enemy1.redship.getGlobalBounds().width) + Enemy1.redship.getGlobalBounds().width  , 0.f);
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
			enemies[i].redship.move(sin(i), 5.f);
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
					enemies[k].EnemyHP--;

					if (enemies[k].EnemyHP == 0)
					{
						enemies.erase(enemies.begin() + k);
						EnemyKilled++;
					}
					break;
				}
				
			}
		}

		int R = rand()% 1000;
		int G = rand()% 1000;
		int B = rand()% 1000;
		sf::RectangleShape PlayerHP(sf::Vector2f(30 * HP, 30));
		PlayerHP.setFillColor(sf::Color(R,G,B));
		PlayerHP.setPosition(295, 18);

		for (size_t H = 0; H < enemies.size(); H++)
		{
			if (Player1.spaceship01.getGlobalBounds().intersects(enemies[H].redship.getGlobalBounds()))
			{
				HP--;
				enemies.erase(enemies.begin() + H);
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

		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].draw(window);
		}
		for (size_t i = 0; i < PBullets.size(); i++)
		{
			window.draw(PBullets[i].PLaser);
		}


		window.draw(cursorSprite);
		window.draw(PlayerHP);
		window.draw(HPointBar);
		Player1.draw(window);
		Text1.text_1((int)TimeScore, sf::Vector2f(0.f,0.f), window , (string) "Time Score : ");
		Text2.text_1((int)EnemyKilled, sf::Vector2f(0.f, 20.f), window , (string) "Killed : ");
		if (HP <= 0)
		{
			window.clear();
			Sound.intro.pause();
			window.draw(Overicon);
		}

		window.display();
		
		//window.draw(bossstage1);
		
	}
	return 0;
}