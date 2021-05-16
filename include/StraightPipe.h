#pragma once
#include "RotationObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class  StraightPipe: public RotationObject // pipe
{
public:
	StraightPipe(int x) :RotationObject(x) {};
	~StraightPipe() = default;
	//virtual void rotation(const Direction& direction);
	virtual void printObject(sf::RenderWindow& window)const {};

private:
	sf::Sprite m_pipePng;

};