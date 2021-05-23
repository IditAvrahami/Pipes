#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GraphicDesign.h"
#include "Utilities.h"
#include <iostream>

Object::Object(int x, int indexToPic) : m_myVertexNumber(x), m_full(false)
{
    m_objectPng = GraphicDesign::instance().getSprite(indexToPic);
    colorSprite();
}

bool Object::ifFull() const
{
    return m_full;
}
void Object::setFull(bool x)
{
    m_full = x;
    colorSprite();
}

void Object::setSprite(const sf::Sprite& picture )//(const sf::Texture& picture)
{
    m_objectPng = picture;
}

void Object::printObject(sf::RenderWindow& window) const
{
    window.draw(m_objectPng);
}

void Object::setLocation(int x, int y)
{
    m_objectPng.setOrigin(sf::Vector2f(0.5 * RATIO, 0.5 * RATIO));
    sf::Vector2f location;
    location.x = y * RATIO;
    location.y = x * RATIO;
    location += sf::Vector2f(0.5 * RATIO, 0.5 * RATIO);
    m_objectPng.setPosition(location);
}

void Object::colorObject()
{
    m_objectPng.setColor(sf::Color::Blue);
}

void Object::colorSprite()
{
    if(m_full)
        m_objectPng.setColor(sf::Color::Blue);
    else
        m_objectPng.setColor(sf::Color::Red);
}
