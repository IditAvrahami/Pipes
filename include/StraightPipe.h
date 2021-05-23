#pragma once
#include "RotationObject.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class  StraightPipe: public RotationObject
{
public:
	StraightPipe(int x, int i) :RotationObject(x,i) {};
	~StraightPipe() = default;
	virtual void intiStruct(int);
	virtual Position getPosition()const;
	virtual void updateCurrentBits(int rotation);

private:
	struct Position m_Position;
	sf::Sprite m_back;

};