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
	void endGame() { m_window.close(); }; // print bye message and picture
	int getClicks()const;
	std::pair<int, int> toIndex(const sf::Vector2f &location)const;
	bool ifValidClick(int)const;
	bool winTheLevel()const;
	//void updatePath();
	void buildGraph();
	void print();
	void updateGraph(int x, int y);

private:
	int m_clicks;
	int m_level;
	Board m_board;
	Graph m_levelGraph;
	sf::RenderWindow m_window;
};
