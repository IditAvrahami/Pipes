#pragma once
#include "RotationObject.h"

class TPipe : public RotationObject 
{
public:
	TPipe(int x, int i) :RotationObject(x,i) {};
	~TPipe() = default;
//	virtual void rotation(const Direction& direction) {};
//	virtual void printObject(sf::RenderWindow& window)const {};

private:
	//sf::Sprite m_Png;
};
