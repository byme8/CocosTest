#include "Food.h"


Food* Food::create(Size SpawnRect)
{
	Food* food = new Food(SpawnRect);
	return food;
}

Food::Food(Size SpawnRect)
{
	this->spawnRect = SpawnRect;
	initWithFile("body.png");
	setScale(0.2);
	srand((unsigned int)this);
	respawn();
}

void Food::respawn()
{
	int x = rand() % (int)spawnRect.width / 10;
	int y = rand() % (int)spawnRect.height / 10;
	setPosition(Vec2(x * 10, y * 10));
}
