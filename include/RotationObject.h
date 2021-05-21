#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class RotationObject : public Object
{
public:
	RotationObject(int x, int i) :Object(x, i){};
	~RotationObject()=default;
	virtual bool rotation(const float direction) {
		Object::m_objectPng.rotate(direction);
		return true;
	};
//	virtual void randomEdges() = 0;
	virtual void intiStruct(int)=0;

private:
	
};
