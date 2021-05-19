#pragma once
#include "RotationObject.h"

class PlusPipe : public RotationObject // pipe
{
public:
	PlusPipe(int x, int i) :RotationObject(x, i) {};
	~PlusPipe() = default;
//	virtual void rotation(const Direction& direction);
//	virtual void printObject(sf::RenderWindow& window)const {};

private:
	//sf::Sprite m_Png;
};
