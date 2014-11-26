#include "SnakePart.h"



SnakePart* SnakePart::setSpriteFromFile(std::string sFileName)
{
	SnakePart *part = new SnakePart();
	if (part->initWithFile(sFileName))
	{
		part->autorelease();
		return part;
	}
	CC_SAFE_DELETE(part);
	return NULL;
}
SnakePart::SnakePart() :CCSprite()
{

}

SnakePart::~SnakePart()
{
	release();
}
