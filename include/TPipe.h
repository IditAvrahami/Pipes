#pragma once
#include "RotationObject.h"
#include "Utilities.h"

class TPipe : public RotationObject 
{
public:
	TPipe(int x, int i) :RotationObject(x,i) {};
	~TPipe() = default;
	virtual void randomEdges();
	virtual void intiStruct(int);

private:
	struct Position m_Position;
	//sf::Sprite m_Png;
};
