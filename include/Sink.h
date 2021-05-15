#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Sink : public Object
{
public:
	Sink ();
	~Sink ();
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:
	sf::Sprite m_sinkPng;
};
