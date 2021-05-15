#pragma once
#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class  StraightPipe: public Pipe
{
public:
	StraightPipe();
	~StraightPipe();
	virtual void rotation(const Direction& direction);
	virtual bool ifFull();
	virtual void printObject(sf::RenderWindow& window)const;

private:
	sf::Sprite m_pipePng;

};