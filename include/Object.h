#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Object
{
public:
	Object(int x)  : m_myVertexNumber(x) {};
	~Object() = default;
	virtual bool ifFull() = 0;
	virtual void printObject(sf::RenderWindow& window)const = 0;
	virtual int getVertex()const { return m_myVertexNumber; };

protected:
	int m_myVertexNumber;
private:
	
};
