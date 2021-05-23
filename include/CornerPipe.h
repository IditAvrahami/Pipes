#pragma once
#include "RotationObject.h"
#include "Utilities.h"

class CornerPipe : public RotationObject
{
public:
	CornerPipe(int x, int i) : RotationObject(x,i) {};
	~CornerPipe() = default;
	//virtual void randomEdges();
	virtual void intiStruct(int);
	virtual Position getPosition()const;
	virtual void updateCurrentBits(int rotation);


private:
	struct Position m_Position;

};
