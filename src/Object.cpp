#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GraphicDesign.h"
#include "Utilities.h"

Object::Object(int x, int indexToPic) : m_myVertexNumber(x), m_full(false)// ,m_objectPng(sf::Sprite)
{
    m_objectPng = GraphicDesign::instance().getSprite(indexToPic);
   // m_objectPng.setTexture(GraphicDesign::instance().getPicture(indexToPic));
}

bool Object::ifFull() const
{
    return m_full;
}
void Object::setFull(bool x)
{
    m_full = x;
}

void Object::setSprite(const sf::Sprite& picture )//(const sf::Texture& picture)
{
    m_objectPng = picture;
//    m_objectPng.setTexture(picture);
}

void Object::printObject(sf::RenderWindow& window) const
{
    window.draw(m_objectPng);
}

void Object::setLocation(int x, int y)
{
    sf::Vector2f location;
    location.x  = x* RATIO;
    location.y = y * RATIO;
    m_objectPng.setPosition(location);
    location.x += 0.5 * RATIO;
    location.y += 0.5 * RATIO;
    m_objectPng.setOrigin(location);
}
