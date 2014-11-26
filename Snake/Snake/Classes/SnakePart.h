#pragma once

#include<cocos2d.h>
#include<string>

using namespace cocos2d;

class SnakePart : public CCSprite 
{
public:
	SnakePart(void);


	static SnakePart* setSpriteFromFile(std::string sFileName);
	~SnakePart(void);
};