#pragma once
#include "RotationObject.h"

class PlusPipe : public RotationObject // pipe
{
public:
	PlusPipe(int x) :RotationObject(x) {};
	~PlusPipe() = default;
//	virtual void rotation(const Direction& direction);
	virtual bool ifFull() { return true; };
	virtual void printObject(sf::RenderWindow& window)const {};

private:

};
