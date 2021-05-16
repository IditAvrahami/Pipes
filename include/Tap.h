#pragma once
#include "RotationObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Tap  : public RotationObject
{
public:
	Tap(int x) :RotationObject(x) {};
	~Tap() = default;
	virtual void printObject(sf::RenderWindow& window)const {};

private:
	sf::Sprite m_tapPng;

};
