#pragma once
#include "RotationObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tap  : public RotationObject
{
public:
	Tap(int number) {};
	~Tap() = default;
	virtual bool ifFull() {};
	virtual void printObject(sf::RenderWindow& window)const;

private:
	sf::Sprite m_tapPng;

};
