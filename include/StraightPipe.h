#pragma once
#include "RotationObject.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class  StraightPipe: public RotationObject // pipe
{
public:
	StraightPipe(int x, int i) :RotationObject(x,i) {};
	~StraightPipe() = default;
	virtual void randomEdges();
	virtual void intiStruct(int);

private:
	struct Position m_Position;
	//sf::Sprite m_pipePng;

};