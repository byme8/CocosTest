#pragma once
#include<cocos2d.h>
#include<Snake.h>
#include<Food.h>
#include<vector>

using namespace cocos2d;

class SnakeGameScene : public cocos2d::Layer
{
	Snake *snake;
	Food *food;
	Size screenSize;
	SnakeGameScene();
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);

	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(SnakeGameScene);

	void update(float dt);

	~SnakeGameScene();
};

