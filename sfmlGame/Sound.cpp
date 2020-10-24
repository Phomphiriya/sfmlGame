#include "Sound.h"

Sound::Sound(int hi)
{
	intro.openFromFile("Sound/Sound01.ogg");
	shoot_effect_buffer.loadFromFile("SoundEffect/laser.ogg");
	shoot_effect.setBuffer(shoot_effect_buffer);
	//shoot_effect.play();
}

Sound::~Sound() {}