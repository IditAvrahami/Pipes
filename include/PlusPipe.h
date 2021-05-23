#pragma once
#include "RotationObject.h"
#include "Utilities.h"

class PlusPipe : public RotationObject // pipe
{
public:
	PlusPipe(int x, int i) :RotationObject(x, i) {};
	~PlusPipe() = default;
//	virtual void randomEdges();
	virtual void intiStruct(int);
	virtual Position getPosition()const;
	virtual void updateCurrentBits(int rotation) {};

private:
	struct Position m_Position;
};
