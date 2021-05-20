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
	virtual void rotation(const float direction) {};
//	virtual void printObject(sf::RenderWindow& window)const {};
	virtual void randomEdges();
	virtual void intiStruct(int) {};

private:
	struct Position m_Position;
	//sf::Sprite m_sinkPng;
};
