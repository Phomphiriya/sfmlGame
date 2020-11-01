#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
class Sound
{
public:
	Sound();
	~Sound();
public:
	sf::Sound shoot_effect;
	sf::Music intro;
private:
	sf::SoundBuffer shoot_effect_buffer;
};