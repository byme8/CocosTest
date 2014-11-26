#include "SnakeGameScene.h"
USING_NS_CC;

SnakeGameScene::SnakeGameScene()
{
	screenSize = Director::sharedDirector()->getWinSize();
	snake = Snake::create(5, Point(screenSize.width / 2, screenSize.height / 2));
	food = Food::create(screenSize);
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = CC_CALLBACK_2(SnakeGameScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(SnakeGameScene::onTouchMoved, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}
Scene* SnakeGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SnakeGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool SnakeGameScene::init()
{

	if (!Layer::init())
		return false;
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SnakeGameScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	this->addChild(snake);
	this->addChild(food);

	this->schedule(schedule_selector(SnakeGameScene::update));

	return true;
}

bool SnakeGameScene::onTouchBegan(Touch *touch, Event *e)
{
	return true;
}
void SnakeGameScene::onTouchMoved(Touch *touch, Event *e)
{
	auto delta = touch->getDelta();
	if (abs(delta.x) > abs(delta.y))
		if (delta.x > 0)
			snake->updateWay(SnakeWay::Right);
		else
			snake->updateWay(SnakeWay::Left);
	else
		if (delta.y > 0)
			snake->updateWay(SnakeWay::Up);
		else
			snake->updateWay(SnakeWay::Down);
}


void SnakeGameScene::update(float t)
{
	static float waitTime = 0;
	if (waitTime > 0.1)
	{
		snake->update(t);

		auto pos = snake->getHead();

		if (pos.x<0 || pos.x>screenSize.width || pos.y<0 || pos.y > screenSize.height || snake->isDead())
			snake->reset();
		if (food->getPosition() == snake->getHead())
		{
			snake->incLength();
			food->respawn();
		}
		waitTime = 0;
	}
	else
		waitTime += t;
}

void SnakeGameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}














SnakeGameScene::~SnakeGameScene()
{
}

