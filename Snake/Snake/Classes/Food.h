#pragma once
#include<cocos2d.h>

using namespace cocos2d;

class Food : public Sprite
{
	Size spawnRect;
	Food(Size SpawnRect);
public:

	void respawn();
	static Food* create(Size SpawnRect);
};

