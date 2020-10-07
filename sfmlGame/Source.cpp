#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

const int W = 607;
const int H = 1000;
int main()
{
	sf::RenderWindow window(sf::VideoMode(W, H), "Adventure Time!", sf::Style::Close | sf::Style::Titlebar);
	
	sf::Texture wall;
	wall.loadFromFile("Wallpaper/wallpapertest03.jpg");
	sf::Sprite swall(wall);
	swall.setScale(2.2, 2);

	sf::Texture ship;
	ship.loadFromFile("Spaceship/spaceship01.png");
	
	sf::Sprite spaceshiptest(ship);
	int shipX = ship.getSize().x / 3;
	int shipY = ship.getSize().y / 3;
	spaceshiptest.setTextureRect(sf::IntRect(shipX * 1, shipY * 1, shipX, shipY));
	
	sf::Vector2f spawnPoint = { 280.f,880.f };
	spaceshiptest.setPosition(spawnPoint);
	spaceshiptest.setScale(1.5, 1.5);

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e));
		{
			if (e.type == e.Closed)
			{
				window.close();
			}
			spaceshiptest.setTextureRect(sf::IntRect(shipX * 1, shipY * 1, shipX, shipY));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				spaceshiptest.move(0.1f, 0.0f);
				spaceshiptest.setTextureRect(sf::IntRect(shipX * 2, shipY * 2, shipX, shipY));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				spaceshiptest.move(-0.1f, 0.f);
				spaceshiptest.setTextureRect(sf::IntRect(shipX * 0, shipY * 2, shipX, shipY));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && spaceshiptest.getPosition().y > 10)
			{
				spaceshiptest.move(0.f, -0.1f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && spaceshiptest.getPosition().y < H - 120)
			{
				spaceshiptest.move(0.f, 0.1f);
			}
			if (spaceshiptest.getPosition().x > W) 
			{
				spaceshiptest.setPosition(0, spaceshiptest.getPosition().y);
			}
			if (spaceshiptest.getPosition().x < -30) 
			{
				spaceshiptest.setPosition(W, spaceshiptest.getPosition().y);
			}
			window.clear();
			window.draw(swall);
			window.draw(spaceshiptest);
			window.display();
		}
	}
	return 0;
}