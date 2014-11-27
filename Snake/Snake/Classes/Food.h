#ifndef COCOSTEST_CLASSES_FOOD_H
#define COCOSTEST_CLASSES_FOOD_H
#include<cocos2d.h>


class Food : public cocos2d::Sprite
{
	cocos2d::Size spawnRect;
	Food(cocos2d::Size SpawnRect);
public:

	void respawn();
	static Food* create(cocos2d::Size SpawnRect);
};

#endif COCOSTEST_CLASSES_FOOD_H
