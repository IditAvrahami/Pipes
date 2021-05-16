#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class RotationObject : public Object
{
public:
	RotationObject(int x) :Object(x){};
	~RotationObject()=default;
//	virtual void rotation(const Direction& direction) = 0;
	virtual void printObject(sf::RenderWindow& window)const = 0;

private:
	
};
