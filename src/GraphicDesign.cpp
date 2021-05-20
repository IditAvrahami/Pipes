#include "GraphicDesign.h"
#include "Utilities.h"
#include "Controller.h"

GraphicDesign::GraphicDesign() // singelton class
{
	m_pictures.resize(PIPES);
	m_pictures[TAP].loadFromFile("tap.png");
	m_pictures[STRIGHT_PIIPE].loadFromFile("pipe.png");
	m_pictures[CORNER_PIPE].loadFromFile("corner_pipe.png");
	m_pictures[TPIPE].loadFromFile("t_pipe.png");
	m_pictures[PLUS_PIPE].loadFromFile("plus_pipe.png");
	m_pictures[SINK].loadFromFile("sink.png");
	m_pictures[FULL_SINK].loadFromFile("full_sink.png");
	m_pictures[WHITE].loadFromFile("white.png");
	m_font.loadFromFile("resources/sansation.ttf");
	m_back.setTexture(m_pictures[WHITE]);
}


sf::Texture& GraphicDesign::getPicture(int index)
{
	return m_pictures[index];
}

sf::Sprite GraphicDesign::getSprite(int index)
{
	return sf::Sprite(m_pictures[index]);
}

GraphicDesign& GraphicDesign::instance()
{
	static GraphicDesign instance;
	return instance;
}

void GraphicDesign::printText(sf::RenderWindow& window, int clicks)
{
	m_Text.setString("clicks :");
	window.draw(m_Text);
	m_Clicks.setString(std::to_string(clicks));
	window.draw(m_Clicks);
}

void GraphicDesign::printBack(sf::RenderWindow& window)
{
	window.draw(m_back);
}

void GraphicDesign::setTextPosition(int row, int col)
{
	m_Clicks.setFont(m_font);
	m_Clicks.setFillColor(sf::Color::Black);
	m_Clicks.setPosition((float)((row - 1) * RATIO), ((float)((col + 0.25) * RATIO)));

	m_Text.setFont(m_font);
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setPosition((float)((row - 3) * RATIO), ((float)((col + 0.25) * RATIO)));

}
