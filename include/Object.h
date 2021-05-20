#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

class Object
{
public:
	Object(int x, int indexToPic);
	~Object() = default;
	virtual bool ifFull()const;
	virtual void setFull(bool x);
	virtual int getVertex()const { return m_myVertexNumber; };
	virtual void setSprite(const sf::Sprite& picture); // (const sf::Texture&);
	void printObject(sf::RenderWindow& window)const ; 
	virtual void setLocation(int x, int y);//(const sf::Vector2f& location);
	virtual void rotation(const float direction) = 0;

protected:
	int m_myVertexNumber;
	sf::Sprite m_objectPng;
	bool m_full;

private:
	
};
