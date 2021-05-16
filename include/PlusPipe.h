#pragma once
#include "Pipe.h"

class PlusPipe : public Pipe
{
public:
	PlusPipe();
	~PlusPipe();
//	virtual void rotation(const Direction& direction);
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:

};
