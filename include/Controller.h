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
	void createBoard();
	void endGame();
	void getLevel();
	int getClicks()const;
	//void addClick();
	
private:
	int m_clicks;
	Board m_board;
	sf::RenderWindow m_window;
};
