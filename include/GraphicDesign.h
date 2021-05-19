#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>

class GraphicDesign
{
public:
	~GraphicDesign() = default; // close all photos
	sf::Texture getPicture(int index)const;
	static GraphicDesign& instance();

private:
	GraphicDesign(); // open pic
	std::vector<sf::Texture> m_pictures;
};
