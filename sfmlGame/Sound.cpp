#include "Sound.h"

Sound::Sound()
{
	intro.openFromFile("Sound/Sound01.ogg");
	intro.setVolume(50.f);
	
	shoot_effect_buffer.loadFromFile("SoundEffect/laser.ogg");
	shoot_effect.setVolume(15.f);
	shoot_effect.setBuffer(shoot_effect_buffer);
	
	Game_over.openFromFile("Sound/aa.wav");
	Game_over.setVolume(100.f);

	bosscoming.openFromFile("Sound/BossAlarm.ogg");
	bosscoming.setVolume(50.f);

	Menusound.openFromFile("Sound/MenuSound.ogg");
	Menusound.setVolume(50.f);
}

Sound::~Sound() {}