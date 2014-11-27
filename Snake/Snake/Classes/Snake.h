#ifndef COCOSTEST_CLASSES_SNAKE_H
#define COCOSTEST_CLASSES_SNAKE_H

#include<cocos2d.h>
#include<vector>


enum SnakeWay
{
	Up = 0,
	Down,

	Left = 3,
	Right
};

class Snake : public cocos2d::Sprite
{
	size_t _startLen;			//Start length of snake
	cocos2d::Point _startPos;				//Start pos of snake
	std::vector<cocos2d::Sprite*> _body;	//Body of snake, which contain head on last position and other part
	SnakeWay _way;				//Direction, which snake is moving now
	bool _dead;					//Become false if snake eat part of its body
public:
	Snake(size_t len, cocos2d::Point StartPosition);
	void incLength();				//Increase length of snake by one
	void updateWay(SnakeWay way);	//Update direction
	void update(float t);			//basic update
	void reset();					//reset snake to start state
	bool isDead();					
	cocos2d::Point getHead();				//return position of snake's head
};


#endif COCOSTEST_CLASSES_SNAKE_H