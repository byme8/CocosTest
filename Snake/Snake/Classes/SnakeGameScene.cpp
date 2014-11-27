#include "SnakeGameScene.h"
USING_NS_CC;

SnakeGameScene::SnakeGameScene()
{
	_screenSize = Director::sharedDirector()->getWinSize();
	_snake = new Snake(5, Point(_screenSize.width / 2, _screenSize.height / 2));
	_food = Food::create(_screenSize);

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
	this->addChild(_snake);
	this->addChild(_food);

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
			_snake->updateWay(SnakeWay::Right);
		else
			_snake->updateWay(SnakeWay::Left);
	else
		if (delta.y > 0)
			_snake->updateWay(SnakeWay::Up);
		else
			_snake->updateWay(SnakeWay::Down);
}

void SnakeGameScene::update(float t)
{
	static float waitTime = 0;
	if (waitTime > 0.1)
	{
		_snake->update(t);

		auto pos = _snake->getHead();

		if (pos.x<0 || pos.x>_screenSize.width || pos.y<0 || pos.y > _screenSize.height || _snake->isDead())
			_snake->reset();
		if (_food->getPosition() == _snake->getHead())
		{
			_snake->incLength();
			_food->respawn();
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

