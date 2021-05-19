#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GraphicDesign.h"

Object::Object(int x, int indexToPic) : m_myVertexNumber(x), m_full(false)
{
    m_objectPng.setTexture(GraphicDesign::instance().getPicture(indexToPic));
}

bool Object::ifFull() const
{
    return m_full;
}
void Object::setFull(bool x)
{
    m_full = x;
}

void Object::setSprite(const sf::Texture& picture)
{
    m_objectPng.setTexture(picture);
}

void Object::printObject(sf::RenderWindow& window) const
{
    window.draw(m_objectPng);
}

void Object::setLocation(const sf::Vector2f& location)
{
    m_objectPng.setPosition(location);
}
