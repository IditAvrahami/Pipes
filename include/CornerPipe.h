#pragma once
#include "RotationObject.h"

class CornerPipe : public RotationObject
{
public:
	CornerPipe(int x, int i) : RotationObject(x,i) {};
	~CornerPipe() = default;
//	virtual void rotation(const Direction& direction);
	//virtual void printObject(sf::RenderWindow& window)const {};

private:
	//sf::Sprite m_Png;
};
