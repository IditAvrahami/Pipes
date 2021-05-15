#pragma once
#include "Board.h"

class Controller
{
public:
	Controller();
	~Controller();
	void startGame();
	void nextLevel();
	void createBoard();
	void endGame();
	void getLevel();
	int getClicks()const;
	void addClick();
	
private:
	int m_clicks;
	Board m_board;
	sf::RenderWindow m_window;
};
