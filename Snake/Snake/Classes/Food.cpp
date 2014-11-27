#include "Food.h"

Food* Food::create(cocos2d::Size SpawnRect)
{
	Food* food = new Food(SpawnRect);
	return food;
}

Food::Food(cocos2d::Size SpawnRect)
{	
	srand((unsigned int)this);
	this->spawnRect = SpawnRect;

	initWithFile("body.png");
	setScale(0.2);

	respawn();
}

void Food::respawn()
{
	int x = rand() % (int)spawnRect.width / 10;
	int y = rand() % (int)spawnRect.height / 10;
	setPosition(cocos2d::Vec2(x * 10, y * 10));
}
