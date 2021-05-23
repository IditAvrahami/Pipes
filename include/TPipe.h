#pragma once
#include "RotationObject.h"
#include "Utilities.h"

class TPipe : public RotationObject 
{
public:
	TPipe(int x, int i) :RotationObject(x,i) {};
	~TPipe() = default;
//	virtual void randomEdges();
	virtual void intiStruct(int);
	virtual Position getPosition()const;
	virtual void updateCurrentBits(int rotation);

private:
	struct Position m_Position;
	//int m_positionNumber;
	//sf::Sprite m_Png;
};
