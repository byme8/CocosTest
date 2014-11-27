#include "Snake.h"

Snake::Snake(unsigned int StartLength = 3, cocos2d::Point StartPosition = cocos2d::Point(0, 0))
{
	_startPos = StartPosition;
	_startLen = StartLength;
	_dead = false;
	_way = SnakeWay::Up;

	//making start _body
	Sprite *temp;
	for (int i = 0; i < StartLength; i++)
	{
		temp = Sprite::create("body.png");
		temp->setScale(0.1f);
		temp->setPosition(StartPosition);
		_body.push_back(temp);
		this->addChild(temp);
	}
	//increase head
	_body[_body.size() - 1]->setScale(0.15);

}

void Snake::update(float dt)
{
	//if _dead do nothing
	if (_dead)
		return;

	//moving snake's part foward
	int i = 0;
	for (; i < _body.size() - 1; i++)
		_body[i]->setPosition(_body[i+1]->getPosition());

	//move head
		auto pos = _body[i]->getPosition();
		switch (_way)
		{
		case SnakeWay::Up:
			_body[i]->setPositionY(pos.y + 10);
			break;
		case SnakeWay::Down:
			_body[i]->setPositionY(pos.y - 10);
			break;
		case SnakeWay::Left:
			_body[i]->setPositionX(pos.x - 10);
			break;
		case SnakeWay::Right:
			_body[i]->setPositionX(pos.x + 10);
			break;
		}

		//cheak for suicide
		auto head = getHead();
		for (int i = 0; i < _body.size()-1; i++)
		if (_body[i]->getPosition() == head)
		{
			_dead = true;
		}
}

void Snake::updateWay(SnakeWay newWay)
{
	if (abs(newWay - _way) == 1)
		return;

	_way = newWay;
}

void Snake::reset()
{
	int len = _body.size();
	for (int i = 0; i < len - _startLen; i++)
	{
		this->removeChild(_body[i], true);
		_body[i];
	}

	_body.erase(_body.begin(), _body.end() - _startLen);

	len = _body.size();
	for (int i = 0; i < len; i++)
		_body[i]->setPosition(_startPos);
	
	_dead = false;
	_way = SnakeWay::Up;
}

void Snake::incLength()
{
	auto temp = Sprite::create("body.png");//load new part
	temp->setPosition(this->getHead());
	temp->setScale(0.1);
	_body.insert(_body.begin(), temp);
	this->addChild(temp);//adding new part
}

bool Snake::isDead()
{
	return _dead;
}

cocos2d::Point Snake::getHead()
{
	return _body[_body.size() - 1]->getPosition();
}

