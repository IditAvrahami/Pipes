#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

Object::Object(int x) : m_myVertexNumber(x), m_full(false)
{}

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
