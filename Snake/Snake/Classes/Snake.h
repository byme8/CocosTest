#pragma once
#include<cocos2d.h>
#include<vector>

using namespace cocos2d;

enum SnakeWay
{
	Up = 0,
	Down,

	Left = 3,
	Right
};

class Snake : public Sprite
{
	size_t startLen;			//Start length of snake
	Point startPos;				//Start pos of snake
	std::vector<Sprite*> body;	//Body of snake, which contain head on last position and other part
	SnakeWay way;				//Direction, which snake is moving now
	bool dead;					//Become false if snake eat part of its body
	Snake(size_t len, Point StartPosition);
public:
	void incLength();				//Increase length of snake by one
	void updateWay(SnakeWay way);	//Update direction
	void update(float t);			//basic update
	void reset();					//reset snake to start state
	bool isDead();					
	Point getHead();				//return position of snake's head


	static Snake* create(size_t StartLength, Point StartPosition);
};
