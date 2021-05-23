#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class RotationObject : public Object
{
public:
	RotationObject(int x, int i) :Object(x, i){};
	~RotationObject()=default;
	virtual bool rotation(const float direction);
	virtual void intiStruct(int)=0;
	virtual Position getPosition()const =0;
	virtual void updateCurrentBits(int rotation) = 0;

protected:
	int m_positionNumber = 0;

private:
	
};
