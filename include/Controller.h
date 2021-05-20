#pragma once
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>



class Controller
{
public:
	Controller();
	~Controller() = default;
	void startGame();
	void nextLevel();
	void endGame() {}; // print bye message and picture
	int getClicks()const;
	std::pair<int, int> toIndex(const sf::Vector2f &location)const;
	bool ifValidClick(int)const;
	bool winTheLevel()const;

private:
	int m_clicks;
	int m_level;
	Board m_board;
	sf::RenderWindow m_window;
};
