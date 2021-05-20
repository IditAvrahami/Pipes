#include "GraphicDesign.h"
#include "Utilities.h"

GraphicDesign::GraphicDesign() // singelton class
{
	m_pictures.resize(PIPES);
//	m_startPng.setPosition(400, 200);
	//m_startPng = sf::Sprite(m_start);
	//m_pictures[TAP].loadFromFile("tap.png");===========================
	m_pictures[TAP].loadFromFile("heart.png");
	m_pictures[STRIGHT_PIIPE].loadFromFile("stright_pipe.png");
	m_pictures[CORNER_PIPE].loadFromFile("corner-pipe.png");
	m_pictures[TPIPE].loadFromFile("t_pipe.png");
	m_pictures[PLUS_PIPE].loadFromFile("plus_pipe.png");
//	m_pictures[SINK].loadFromFile("sink.png");============================
	m_pictures[SINK].loadFromFile("heart.png");
}


sf::Texture& GraphicDesign::getPicture(int index)
{
	return m_pictures[index];
}

sf::Sprite GraphicDesign::getSprite(int index)
{
	return sf::Sprite(m_pictures[index]);
	// TODO: insert return statement here
}

GraphicDesign& GraphicDesign::instance()
{
	static GraphicDesign instance;
	return instance;
}
