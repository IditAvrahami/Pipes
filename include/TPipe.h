#pragma once
#include "RotationObject.h"

class TPipe : public RotationObject 
{
public:
	TPipe(int x) :RotationObject(x) {};
	~TPipe() = default;
//	virtual void rotation(const Direction& direction) {};
	virtual bool ifFull(){ return true; };
	virtual void printObject(sf::RenderWindow& window)const {};

private:

};
