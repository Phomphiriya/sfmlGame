
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<cstdlib>
#include "Player.h"
#include "Text.h"
#include "Sound.h"
#include "Enemy.h"
#include "Comet.h"
#include "PBullet.h"
#include "EBullet.h"
#include "wallstage1.h"
#include <vector>

const int W = 607;
const int H = 1000;
bool sortbysecdesc(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return a.second > b.second;
}
int main()
{
	std::ofstream fileWriter;
	sf::String playerInput;

	std::map<int, std::string> keepscore;
	std::ifstream fileReader;
	std::string word;

	sf::Clock clock;
	sf::Clock clock2;
	srand(time(NULL));
	Enemy Enemy1(3);
	PBullet PBullet1;
	EBullet EBullet1;
	wallstage1 wallstage1;
	Sound Sound;
	Text MenuText1;
	Text MenuText2;
	Text MenuText3;
	Text MenuText4;
	Text Textback_story;
	Text Textplay_story;
	Text Textback_htp;
	Text Text_timescore;
	Text Text_killed;
	Text Text_yourscore;
	Text Text_gameover;
	Text Text_htp1;
	Text Text_htp2;
	Text Text_htp3;
	Text Text_htp4;
	Text Enter_score;
	Text Textback_score;
	Text Text_head_score;
	Text Text_nameplayer;
	Text Text_scoreplayer;
	Player Player1(sf::Vector2f(10.0, 10.0) ,W ,H , sf::Vector2f(280.0f,1000.0f));
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);


	sf::Texture HPBar;
	HPBar.loadFromFile("HP/Heartjingna.png");
	sf::RectangleShape HPointBar(sf::Vector2f(25.0f,25.0f));
	HPointBar.setTexture(&HPBar);
	HPointBar.setPosition(20, 12);

	//------------Gameover---------------------------
	sf::Texture Gameover;
	Gameover.loadFromFile("Wallpaper/Gameovermenu.png");
	sf::RectangleShape Overicon(sf::Vector2f(607, 1000));
	Overicon.setTexture(&Gameover);
	Overicon.setPosition(0,0);

	sf::Font fontscore;
	fontscore.loadFromFile("font/8bitnew.ttf");
	std::ostringstream score;
	sf::Text Score;
	Score.setCharacterSize(20);
	Score.setPosition({ 300.f,500.f });
	Score.setString(score.str());
	Score.setFont(fontscore);
	Score.setFillColor(sf::Color(8, 72, 180));

	std::ostringstream keyname;
	sf::Text Keyname;
	Keyname.setCharacterSize(20);
	Keyname.setString("Keyname : ");
	Keyname.setFont(fontscore);
	Keyname.setFillColor(sf::Color(176, 52, 47));

	//------------MENU-----------------------
	sf::Texture Menu;
	Menu.loadFromFile("Wallpaper/Gamemenu.png");
	sf::RectangleShape Mainmenu(sf::Vector2f(607, 1000));
	Mainmenu.setTexture(&Menu);
	Mainmenu.setPosition(0, 0);

	//-----------Story-------------------------------
	float i_story = 0;
	float offset = 0;
	float speed = 0.01;
	float deltatime = 0;
	sf::Texture comic1;
	comic1.loadFromFile("Wallpaper/story.png");
	sf::Sprite story1;
	story1.setTexture(comic1);

	//--------------Score-----------------------------
	sf::Texture scoreim;
	scoreim.loadFromFile("Wallpaper/Score.png");
	sf::RectangleShape wallscore(sf::Vector2f(607, 1000));
	wallscore.setTexture(&scoreim);
	wallscore.setPosition(0, 0);

	sf::Text text_showscore[12];
	for(int s = 0; s<12; s++)
	{
		text_showscore[s].setFont(fontscore);
		text_showscore[s].setCharacterSize(30);
	}
	
	//-----------How to play-------------------------
	sf::Texture HTP;
	HTP.loadFromFile("Wallpaper/Howtoplaynew.png");
	sf::RectangleShape Howtoplay(sf::Vector2f(607, 1000));
	Howtoplay.setTexture(&HTP);
	Howtoplay.setPosition(0, 0);


	
	//----------Enemy&Bullet
	std::vector<Enemy> enemies;
	std::vector<PBullet> PBullets;
	std::vector<EBullet> EBullets;
	std::vector<Comet> Comets;

	int enemySpawnTimer = 0;
	int cometSpawnTimer = 0;
	int shootTimer = 0;
	int enemyshootingTime = 0;
	int EnemyKilled = 0;
	float TimeScore = 0;
	int HP = 1;

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


	// Start game loop
	bool flag1 = false;
	bool start_gameover = false;
	bool start_score = false;
	float count = 0;
	bool cs = false;
	bool start_game = false;
	bool start_story = false;
	bool start_htp = false;
	bool menu = true;
	bool Timecheck = false;
	bool flagsound = true;
	bool flag[10];
	std::vector<std::pair<std::string, int>> vec;
	for (size_t i = 0; i <= 9; i++)
	{
		flag[i] = true;
	}

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

		//---------------------Menu state-----------------------------

		if (menu == true)
		{
			Sound.Menusound.play();
		}
		while (menu == true)
		{
			window.clear();
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
			MenuText1.text_3(sf::Vector2f(window.getSize().x / 2, -10.f), window, (string)"START", 350);
			MenuText2.text_3(sf::Vector2f(window.getSize().x / 2, -110.f), window, (string)"SCORE", 420);
			MenuText3.text_3(sf::Vector2f(window.getSize().x / 2, -210.f), window, (string)"HOW TO PLAY", 490);
			MenuText4.text_3(sf::Vector2f(window.getSize().x / 2, -310.f), window, (string)"QUIT", 560);

			window.draw(cursorSprite);

			if (MenuText1.text3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				MenuText1.text3.setFillColor(sf::Color(176, 52, 47));
				MenuText1.text3.setScale(1.3, 1.3);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					menu = false;
					Timecheck = true;
					start_story = true;
				}
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) and flag[1])
					flag[1] = true;
				
			}
			else
			{
				MenuText1.text3.setFillColor(sf::Color(88, 111, 173));
				MenuText1.text3.setScale(1, 1);

			}

			if (MenuText2.text3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				MenuText2.text3.setFillColor(sf::Color(176, 52, 47));
				MenuText2.text3.setScale(1.3, 1.3);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					start_score = true;
					menu = false;
					std::string word;
					std::ifstream ReadFile("keepscore.txt");
					do {
						ReadFile >> word;
						std::string name = word.substr(0, word.find(','));
						int num = std::stoi(word.substr(word.find(',') + 1, word.length()));
						vec.push_back(std::make_pair(name, num));
					} while (ReadFile.good());
					ReadFile.close();
					std::sort(vec.begin(), vec.end(), sortbysecdesc);
					for (int i = 0; i < 5; i++)
					{
						text_showscore[2 * i + 2].setString(std::to_string(i + 1) + ". " + vec[i].first);
						text_showscore[2 * i + 3].setString(std::to_string(vec[i].second));
						text_showscore[0].setString("NAME");
						text_showscore[0].setFillColor(sf::Color(176, 52, 47));
						text_showscore[0].setPosition(80,180);
						text_showscore[1].setString("SCORE");
						text_showscore[1].setFillColor(sf::Color(176, 52, 47));
						text_showscore[1].setPosition(390, 180);
						std::cout << vec[i].first << "   " << vec[i].second << "\n";
					}
					for (int po = 0; po < 12; po += 2)
					{
						text_showscore[po].setPosition(70, 180 + po * 32);
						text_showscore[po + 1].setPosition(380, 180 + po * 32);
					}
					vec.clear();
				}
			}
			else
			{
				MenuText2.text3.setFillColor(sf::Color(88, 111, 173));
				MenuText2.text3.setScale(1, 1);

			}

			if (MenuText3.text3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				MenuText3.text3.setFillColor(sf::Color(176, 52, 47));
				MenuText3.text3.setScale(1.3, 1.3);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					menu = false;
					start_htp = true;
				}
			}
			else
			{
				MenuText3.text3.setFillColor(sf::Color(88, 111, 173));
				MenuText3.text3.setScale(1, 1);

			}

			if (MenuText4.text3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				MenuText4.text3.setFillColor(sf::Color(176, 52, 47));
				MenuText4.text3.setScale(1.3, 1.3);

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.close();
				}
			}
			else
			{
				MenuText4.text3.setFillColor(sf::Color(88, 111, 173));
				MenuText4.text3.setScale(1, 1);

			}

			window.display();
		}

		//--------------------------------Story-------------------------------------

		while (start_story == true)
		{
			if (window.pollEvent(e));
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
			story1.setTextureRect(sf::IntRect(0, i_story ,comic1.getSize().x, comic1.getSize().y));
			offset += 0.005;
			if (offset >= speed)
			{
				i_story += 1;
				offset -= speed;
			}
			if (i_story >= 720)
			{
				i_story = 720;
			}
			window.draw(story1);
			window.draw(cursorSprite);
			Textback_story.text_5(sf::Vector2f(20.f,3.f), window, (string)"Back");
			Textplay_story.text_5(sf::Vector2f(480.f, 3.f), window, (string)"Play");

			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			if (Textplay_story.text5.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Textplay_story.text5.setFillColor(sf::Color(176, 52, 47));
				Textplay_story.text5.setScale(1.3, 1.3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					start_story = false;
					start_game = true;

				}
			}
			else
			{
				Textplay_story.text5.setFillColor(sf::Color(88, 111, 173));
				Textplay_story.text5.setScale(1, 1);

			}
			if (Textback_story.text5.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Textback_story.text5.setFillColor(sf::Color(176,52,47));
				Textback_story.text5.setScale(1.3, 1.3);
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					start_story = false;
					menu = true;
				}
			}
			else
			{
				Textback_story.text5.setFillColor(sf::Color(88, 111, 173));
				Textback_story.text5.setScale(1, 1);

			}
			window.display();
			
		}
		//----------------------------------Score-------------------------------------

		while (start_score == true)
		{
			if (window.pollEvent(e));
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

			window.draw(wallscore);
			Textback_score.text_5(sf::Vector2f(20.f, 3.f), window, (string)"Back");
			Text_head_score.text_6(sf::Vector2f(155.f, 100.f), window, (string)"LEADERBOARD");
			window.draw(cursorSprite);
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			for (int i = 0; i < 12; i++)
			{
				window.draw(text_showscore[i]);
			}
		
			if (Textback_score.text5.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Textback_score.text5.setFillColor(sf::Color(176, 52, 47));
				Textback_score.text5.setScale(1.3, 1.3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					start_score = false;
					menu = true;
				}
			}
			else
			{
				Textback_score.text5.setFillColor(sf::Color(88, 111, 173));
				Textback_score.text5.setScale(1, 1);

			}

			window.display();
		}

		//--------------------------------How to play---------------------------------

		while (start_htp == true)
		{
			if (window.pollEvent(e));
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
			window.draw(Howtoplay);
			Textback_htp.text_5(sf::Vector2f(20.f, 3.f), window, (string)"Back");
			Text_htp1.text_6(sf::Vector2f(245.f, 280.f), window, (string)"MOVE");
			Text_htp2.text_6(sf::Vector2f(231.f, 440.f), window, (string)"SHOOT");
			Text_htp3.text_6(sf::Vector2f(130.f, 610.f), window, (string)"ULTIMATE SKILL");
			Text_htp4.text_6(sf::Vector2f(170.f, 790.f), window, (string)"PAUSE GAME");
			window.draw(cursorSprite);
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

			if (Textback_htp.text5.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				Textback_htp.text5.setFillColor(sf::Color(176, 52, 47));
				Textback_htp.text5.setScale(1.3, 1.3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					start_htp = false;
					menu = true;
				}
			}
			else
			{
				Textback_htp.text5.setFillColor(sf::Color(88, 111, 173));
				Textback_htp.text5.setScale(1, 1);

			}
			
			window.display();
		}

		//--------------------------------GamePlay------------------------------------

		if (start_game == true)
		{
			Sound.Menusound.stop();
			Sound.intro.play();
		}
		while (start_game == true) 
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{

				Sound.intro.pause();


				start_game = false;
			}

			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			sf::Event e;
			deltatime = clock.restart().asSeconds();
			if ((deltatime > 0 && Timecheck == true) || (TimeScore > 0 and Timecheck == true)) {
				TimeScore = 0;
				deltatime = 0;
				Timecheck = false;
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

			//------------------------------------SHOOTING--------------------------------------------------

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
				//PBullets[i].PLaser.move(7.14, -3.57);
				PBullets[i].PLaser.move(0.f, -8.f);
			}
			
			//------------------------------------Ultimate Skill-----------------------------------------
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			{
				Sound.shoot_effect.play();
				PBullet1.update(Player1.spaceship01_position());
				PBullets.push_back(PBullet(PBullet1));
			}

			//-------------------------------ENEMY---------------------------------------------
			cout << Comets.size() <<endl;
			
			if(cometSpawnTimer < 60 && cs == true)
				cometSpawnTimer++;
			{
				if (cometSpawnTimer >= 60)
				{
					Comets.push_back(Comet(rand() % 2 , rand() % window.getSize().x , &Texture_Comet_big, &Texture_Comet_small));
					cometSpawnTimer = 30;
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
			if (TimeScore >= 3)
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
					if (enemies[i].redship.getPosition().y > window.getSize().y) {

						enemies.erase(enemies.begin() + i);
					}
						
				}
				for (size_t i = 0; i < enemies.size(); i++)
				{
					enemies[i].redship.move(cos(i), 2.5f);
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
				//-------------------Enemy bullet
				if (TimeScore >= 3 )
				{
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (enemies[i].offsetBullet >= 40)
						{
							EBullet1.update(enemies[i].getCenter());
							EBullets.push_back(EBullet(EBullet1));
							enemies[i].offsetBullet = 0;
						}
					}
				}

				for (size_t o = 0; o < EBullets.size(); o++)
				{
					if (EBullets[o].ELaser.getPosition().y >= 1000)
						EBullets.erase(EBullets.begin() + o);
				}
				for (size_t o = 0; o < EBullets.size(); o++)
				{
					EBullets[o].ELaser.move(0.f, 8.f);
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
						break;
					}
					if (enemies[k].EnemyHP <= 0 )
					{
						enemies.erase(enemies.begin() + k);
						EnemyKilled += 5;
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
			for (size_t H = 0; H < EBullets.size(); H++)
			{
				if (Player1.spaceship01.getGlobalBounds().intersects(EBullets[H].ELaser.getGlobalBounds()))
				{
					HP--;
					EBullets.erase(EBullets.begin() + H);
				}
			}

			Player1.update();
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].update(deltatime);
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
			for (size_t i = 0; i < EBullets.size(); i++)
			{
				window.draw(EBullets[i].ELaser);
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
			Text_timescore.text_1((int)TimeScore, sf::Vector2f(410.f, 15.f), window, (string)"Time Score : ");
			Text_killed.text_1((int)EnemyKilled, sf::Vector2f(410.f, 40.f), window, (string)"Killed : ");


			if (HP <= 0)
			{
				Sound.intro.pause();
				Sound.shoot_effect.pause();
				window.clear();
				start_game = false;
				start_gameover = true;
			}

		if ((int)TimeScore == 80 and flagsound )
		{
				Sound.bosscoming.play(); 
				flagsound = false;
		}

			window.display();
		}

		//-----------------------Gameover Menu-----------------------------

		window.clear();
		if (start_gameover == true)
		{
			Sound.Game_over.play();
			Player1.spaceship01.setPosition(sf::Vector2f(280, 1000));
			cs = false;
		}
		while (start_gameover == true)
		{
			for (size_t i = 0; i < Comets.size(); i++)
			{
					Comets.erase(Comets.begin() + i);
			}
			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies.erase(enemies.begin() + i);
			}
			for (size_t i = 0; i < EBullets.size(); i++)
			{
				EBullets.erase(EBullets.begin() + i);
			}
			 
			start_score = true;
			cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			window.draw(Overicon);
			Text_yourscore.text_2((int)(EnemyKilled * TimeScore), sf::Vector2f(100.f, 1020.f), window, (string)"Your score : " , 520);
			Text_gameover.text_4(sf::Vector2f(window.getSize().x / 2, -10.f), window, (string)" GAME OVER ", 410);
			window.draw(cursorSprite);
			//window.display();
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
				
				sf::Event event;

				Keyname.setPosition(137, 565);
				sf::Text text("", fontscore);
				text.setFillColor(sf::Color::Cyan);
				text.setString(playerInput);
				text.setPosition(290, 560);
				window.draw(text);
				window.draw(Keyname);
				window.display();
				while (window.pollEvent(event))
				{

					if (event.type == sf::Event::Closed)
						window.close();
				}
				if (event.type == sf::Event::TextEntered && start_score == true && clock2.getElapsedTime().asSeconds() >= 0.2f)
				{
					clock2.restart();
					if (event.text.unicode == 13) 
					{ //enter
						fileWriter.open("keepscore.txt", std::ios::out | std::ios::app);
						fileWriter << "\n" << playerInput.toAnsiString() << "," << EnemyKilled * TimeScore;
						fileWriter.close();
						playerInput.clear();
						menu = true;
						start_game = false;
						EnemyKilled = 0;
						TimeScore = 0;
						HP = 10;

					}
					if (event.text.unicode == 8)
					{ //backspace
						playerInput = playerInput.substring(0, playerInput.getSize() - 1);
					}
					else
					{
						if (playerInput.getSize() < 10 );
						{
								playerInput += event.text.unicode;
								
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{

						start_gameover = false;
						start_score = false;
						menu = true;

					}

					
				}
		}
		window.display();
	}
	return 0;
}