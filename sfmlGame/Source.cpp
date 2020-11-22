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
#include "Comet.h"
#include "PBullet.h"
#include "wallstage1.h"
#include <vector>

const int W = 607;
const int H = 1000;
using namespace std;
int main()
{
	sf::Clock clock;
	srand(time(NULL));
	Enemy Enemy1(3);
	PBullet PBullet1;
	wallstage1 wallstage1;
	Sound Sound;
	Text MenuText1;
	Text MenuText2;
	Text MenuText3;
	Text MenuText4;
	Text Text1;
	Text Text2;
	Text Text3;
	Text Text4;
	Text Text5;
	Player Player1(sf::Vector2f(10.0, 10.0) ,W ,H , sf::Vector2f(280.0f,1000.0f));
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	//sf::Texture
	/*sf::Texture Boss1;
	Boss1.loadFromFile("Spaceship/boos1new.png");
	sf::Sprite bossstage1(Boss1);*/

	sf::Texture HPBar;
	HPBar.loadFromFile("HP/Heartjingna.png");
	sf::RectangleShape HPointBar(sf::Vector2f(25.0f,25.0f));
	HPointBar.setTexture(&HPBar);
	HPointBar.setPosition(20, 12);

	//------------Gameover---------------------------
	sf::Texture Gameover;
	Gameover.loadFromFile("wallpaper/Gameovermenu.png");
	sf::RectangleShape Overicon(sf::Vector2f(607, 1000));
	Overicon.setTexture(&Gameover);
	Overicon.setPosition(0,0);

	//------------MENU-----------------------
	sf::Texture Menu;
	Menu.loadFromFile("wallpaper/Gamemenu.png");
	sf::RectangleShape Mainmenu(sf::Vector2f(607, 1000));
	Mainmenu.setTexture(&Menu);
	Mainmenu.setPosition(0, 0);

	//-----------Boss
	/*sf::Vector2f bossspawnPoint = { 120.f,-150.f };
	bossstage1.setPosition(bossspawnPoint);
	bossstage1.setScale(0.5, 0.5);*/
	
	//----------Enemy&Bullet
	std::vector<Enemy> enemies;
	std::vector<PBullet> PBullets;
	std::vector<Comet> Comets;
	int enemySpawnTimer = 0;
	int cometSpawnTimer = 0;
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

	//comet
	sf::Texture Texture_Comet_big;
	sf::Texture Texture_Comet_small;
	Texture_Comet_big.loadFromFile("Spaceship/BigComet.png");
	Texture_Comet_small.loadFromFile("Spaceship/SmallComet.png");

	Sound.intro.play();

	// Start game loop
	bool check = false;
	float count = 0;
	bool cs = false;
	bool start = false;
	bool menu = true;
	float deltatime = 0;
	bool c = false;
	bool tom = false;

	while (window.isOpen())
	{
		sf::Event e;
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
		
		while (menu == true)
		{
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

			TimeScore = 0;
			deltatime = 0;
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			window.clear();
			window.draw(Mainmenu);
			MenuText1.text_3(sf::Vector2f(140.f, -10.f), window, (string)"START", 310);
			MenuText2.text_3(sf::Vector2f(140.f, -110.f), window, (string)"SCORE", 410);
			MenuText3.text_3(sf::Vector2f(190.f, -210.f), window, (string)"QUIT", 510);

			window.draw(cursorSprite);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				menu = false;
				c = true;
				start = true;
				
			}
			window.display();
		}
		while (start == true) 
		{
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			sf::Event e;
			deltatime = clock.restart().asSeconds();
			if ((deltatime > 0 && c == true) || (TimeScore > 0 and c == true)) {
				TimeScore = 0;
				deltatime = 0;
				c = false;
			}
			TimeScore = TimeScore+deltatime;

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
			if(cometSpawnTimer < 60 && cs == true)
				cometSpawnTimer++;
			{
				if (cometSpawnTimer >= 60)
				{
					Comets.push_back(Comet(rand() % 2 , rand() % window.getSize().x , &Texture_Comet_big, &Texture_Comet_small));
					cometSpawnTimer = 0;
				}
				for (size_t i = 0; i < Comets.size(); i++)
				{
					if (Comets[i].Comet_obj.getPosition().y > window.getSize().y)
						Comets.erase(Comets.begin() + i);
				}
				for (size_t i = 0; i < Comets.size(); i++)
				{
					Comets[i].Comet_obj.move(cos(i), 3.f);
				}
			}

			if (TimeScore >= 30)
			{
				if (enemySpawnTimer < 100 )
					enemySpawnTimer++;
				if (enemySpawnTimer >= 100)
				{
					Enemy1.redship.setPosition(rand() % int((window.getSize().x - Enemy1.redship.getGlobalBounds().width) - Enemy1.redship.getGlobalBounds().width) + Enemy1.redship.getGlobalBounds().width, 0.f);
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
					enemies[i].redship.move(cos(i), 5.f);
					//std::cout << cos(i) << std::endl;
					if (cos(i) <= 0)
					{
						enemies[i].dx = 0;
					}
					if (cos(i) >= 0 < 1)
					{
						enemies[i].dx = 1;
					}
					if (cos(i) == 1)
					{
						enemies[i].dx = 2;
					}
				}
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

			for (size_t i = 0; i < PBullets.size(); i++)
			{
				for (size_t k = 0; k < Comets.size(); k++)
				{
					if (PBullets[i].PLaser.getGlobalBounds().intersects(Comets[k].Comet_obj.getGlobalBounds()))
					{
						PBullets.erase(PBullets.begin() + i);
						Comets[k].CometHP--;

						if (Comets[k].CometHP == 0)
						{
							Comets.erase(Comets.begin() + k);
							EnemyKilled++;
						}
						break;
					}

				}
			}

			sf::RectangleShape PlayerHP(sf::Vector2f(18 * HP, 10));
			PlayerHP.setFillColor(sf::Color(0, 137, 255));
			PlayerHP.setPosition(40, 18);

			for (size_t H = 0; H < enemies.size(); H++)
			{
				if (Player1.spaceship01.getGlobalBounds().intersects(enemies[H].redship.getGlobalBounds()))
				{
					HP--;
					enemies.erase(enemies.begin() + H);
				}
			}
			for (size_t H = 0; H < Comets.size(); H++)
			{
				if (Player1.spaceship01.getGlobalBounds().intersects(Comets[H].Comet_obj.getGlobalBounds()))
				{
					HP--;
					Comets.erase(Comets.begin() + H);
				}
			}

			Player1.update();
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].update();
			}
			for (size_t i = 0; i < Comets.size(); i++)
			{
				Comets[i].update(deltatime);
			}
			
			Player1.move(deltatime);

			window.clear();
			wallstage1.draw(window);
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].draw(window);
			}
			for (size_t i = 0; i < PBullets.size(); i++)
			{
				window.draw(PBullets[i].PLaser);
			}
			for (size_t i = 0; i < Comets.size(); i++)
			{
				Comets[i].draw(window);
			}

			window.draw(cursorSprite);
			window.draw(PlayerHP);
			window.draw(HPointBar);
			Player1.draw(window);
			
			if (cs == false)
			{
				Player1.spaceship01.move(0.0f, -2.5f);
			}
			if (TimeScore >= 2)
			{
				cs = true;
			}
			Text1.text_1((int)TimeScore, sf::Vector2f(410.f, 15.f), window, (string)"Time Score : ");
			Text2.text_1((int)EnemyKilled, sf::Vector2f(410.f, 40.f), window, (string)"Killed : ");


			if (HP <= 0)
			{
				Sound.intro.pause();
				Sound.shoot_effect.pause();
				window.clear();
				start = false;
				check = true;
			}
			window.display();
		}
		window.clear();
		if (check == true)
		{
			Sound.Game_over.play();
		}
		while (check == true)
		{
			
			window.clear();
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			window.draw(Overicon);
			Text3.text_2((int)(EnemyKilled * TimeScore * 10), sf::Vector2f(260.f, 1080.f), window, (string)"Your score : " , 600);
			Text4.text_3(sf::Vector2f(-20.f, -10.f), window, (string)" GAME OVER ", 480);
			window.draw(cursorSprite);
			window.display();
			sf::Event e;
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
		}
		window.display();
	}
	return 0;
}