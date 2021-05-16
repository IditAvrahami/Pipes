#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

class GraphicDesign
{
public:
	GraphicDesign();
	~GraphicDesign(); // close all photos

private:
	std::vector<sf::Texture> m_pictures;
};
