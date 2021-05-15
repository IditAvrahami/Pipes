#pragma once
#include "RotationObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Pipe : public RotationObject
{
public:
	Pipe();
	~Pipe();
	virtual void rotation(const Direction& direction) {};
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:
	sf::Sprite m_pipePng;

};
