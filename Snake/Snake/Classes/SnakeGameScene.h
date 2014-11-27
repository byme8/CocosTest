#ifndef COCOSTEST_CLASSES_SNAKEGAMESCENE_H
#define COCOSTEST_CLASSES_SNAKEGAMESCENE_H

#include<cocos2d.h>
#include<Snake.h>
#include<Food.h>
#include<vector>

class SnakeGameScene : public cocos2d::Layer
{
	Snake *_snake;
	Food *_food;
	cocos2d::Size _screenSize;

	SnakeGameScene();
public:
	static cocos2d::Scene* createScene();
	virtual bool init() override;

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*) override;
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*) override;

	void menuCloseCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(SnakeGameScene);

	void update(float dt);

	~SnakeGameScene();
};

#endif COCOSTEST_CLASSES_SNAKEGAMESCENE_H

