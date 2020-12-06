#include "Boss1.h"

Boss1::Boss1(int BossHP)
{
	bossship.loadFromFile("Spaceship/bossjingna.png");
	UFO.setTexture(bossship);
	UFO.setScale(2, 2);

}

Boss1::~Boss1()
{
}
