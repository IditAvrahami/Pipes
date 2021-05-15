#pragma once
#include "Pipe.h"

class TPipe : public Pipe
{
public:
	TPipe();
	~TPipe();
	virtual void rotation(const Direction& direction);
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:

};
