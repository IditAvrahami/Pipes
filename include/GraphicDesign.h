#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

class GraphicDesign
{
public:
	~GraphicDesign() = default; // close all photos
	sf::Texture& getPicture(int index);
	sf::Sprite getSprite(int index);
	static GraphicDesign& instance();
	void printText(sf::RenderWindow& window, int clicks);
	void setTextPosition(int x, int y);

private:
	GraphicDesign(); // open pic
	std::vector<sf::Texture> m_pictures;
	sf::Text m_Clicks;
	sf::Font m_font;
	sf::Text m_Text;
};
