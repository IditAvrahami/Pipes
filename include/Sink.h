#pragma once
#include "Object.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Sink : public Object
{
public:
	Sink(int x, int i) :Object(x,i) {};
	~Sink ()= default;
	virtual bool rotation(const float direction) { return false; };
	virtual void intiStruct(int);
	virtual Position getPosition()const { return m_Position; };
	virtual void updateCurrentBits(int rotation) {};

private:
	struct Position m_Position;
};
