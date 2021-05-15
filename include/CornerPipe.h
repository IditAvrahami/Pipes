#pragma once
#include "Pipe.h"

class CornerPipe
{
public:
	CornerPipe();
	~CornerPipe();
	virtual void rotation(const Direction& direction);
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:

};
