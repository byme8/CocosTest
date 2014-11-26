#include "Snake.h"



Snake* Snake::create(unsigned int StartLength = 3, Point StartPosition = Point(0, 0))
{
	Snake *snake = new Snake(StartLength, StartPosition);

	return snake;
}
Snake::Snake(unsigned int StartLength = 3, Point StartPosition = Point(0,0))
{
	startPos = StartPosition;
	startLen = StartLength;
	dead = false;
	way = SnakeWay::Up;

	//making start body
	Sprite *temp;
	for (int i = 0; i < StartLength; i++)
	{
		temp = Sprite::create("body.png");
		temp->setScale(0.1f);
		temp->setPosition(StartPosition);
		body.push_back(temp);
		this->addChild(temp);
	}
	//increase head
	body[body.size() - 1]->setScale(0.15);

}
void Snake::update(float dt)
{
	//if dead do nothing
	if (dead)
		return;

	//moving snake's part foward
	int i = 0;
	for (; i < body.size() - 1; i++)
		body[i]->setPosition(body[i+1]->getPosition());

	//move head
		auto pos = body[i]->getPosition();
		switch (way)
		{
		case SnakeWay::Up:
			body[i]->setPositionY(pos.y + 10);
			break;
		case SnakeWay::Down:
			body[i]->setPositionY(pos.y - 10);
			break;
		case SnakeWay::Left:
			body[i]->setPositionX(pos.x - 10);
			break;
		case SnakeWay::Right:
			body[i]->setPositionX(pos.x + 10);
			break;
		}

		//cheak for suicide
		auto head = getHead();
		for (int i = 0; i < body.size()-1; i++)
		if (body[i]->getPosition() == head)
		{
			dead = true;
		}
}
void Snake::updateWay(SnakeWay newWay)
{
	if (abs(newWay - way) == 1)
		return;

	way = newWay;
}
void Snake::reset()
{
	int len = body.size();
	for (int i = 0; i < len - startLen; i++)
	{
		this->removeChild(body[i], true);
		body[i];
	}

	body.erase(body.begin(), body.end() - startLen);

	len = body.size();
	for (int i = 0; i < len; i++)
		body[i]->setPosition(startPos);
	
	dead = false;
	way = SnakeWay::Up;
}
void Snake::incLength()
{
	auto temp = Sprite::create("body.png");//load new part
	temp->setPosition(this->getHead());
	temp->setScale(0.1);
	body.insert(body.begin(), temp);
	this->addChild(temp);//adding new part
}
bool Snake::isDead()
{
	return dead;
}
Point Snake::getHead()
{
	return body[body.size() - 1]->getPosition();
}

