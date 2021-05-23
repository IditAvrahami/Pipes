#pragma once
#include "RotationObject.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tap  : public RotationObject
{
public:
	Tap(int x, int i) :RotationObject(x, i) {};
	~Tap() = default;
//	virtual void randomEdges();
	virtual void intiStruct(int);
	virtual Position getPosition()const;
	virtual void updateCurrentBits(int rotation);

private:
	struct Position m_Position;
	//sf::Sprite m_tapPng;

};
