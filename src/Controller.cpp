#include "Controller.h"
#include "Utilities.h"
#include "GraphicDesign.h"

Controller::Controller() : m_clicks(0), m_level(0), m_window(sf::VideoMode(m_board.getCols()* RATIO, (m_board.getRows() + 1)* RATIO), "Pipes"),
m_levelGraph(m_board.getCols()* m_board.getRows())
{

}

void Controller::startGame()
{
	std::pair<int, int> index;
	sf::Vector2f location;
	int rotation = 0;
	m_levelGraph = m_board.getGraph();
	buildGraph();
	while (m_window.isOpen())
	{
		if (m_level == 4)
			endGame(); // check of end of game and print bye message

		print();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case event.MouseButtonPressed:

				location.x = event.mouseButton.x;
				location.y = event.mouseButton.y;
				index = toIndex(location);

				if (ifValidClick(index.second))
				{
					//rotation check
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						rotation = 270;
						/*if (m_board.rotate(index.second, index.first, 270))
							m_clicks++;*/
							//m_board.updateCurrentBits(); //update the struct
					}
					else if (event.mouseButton.button == sf::Mouse::Left)
					{
						rotation = 90;
						/*if (m_board.rotate(index.second, index.first, 90))
							m_clicks++;*/
					}
					else
						rotation = 0;

					//the rotation
					if (m_board.rotate(index.second, index.first, rotation) && rotation != 0)
					{
						m_clicks++;
						m_board.updateCurrentBits(index.second, index.first, rotation);
					}

					updateGraph(index.second, index.first); // update level graph 2 update color of all the pipes check id end
					m_levelGraph.BFS(m_board.getTapVertexNumber(), m_board.getSinkVertexNumber());
					m_board.fillPipes(m_levelGraph.getVertex());

					// updatePath();///////////////////////////////////////
					  //check if full or have a path                        
					  //add color(if full)
					if (m_board.ifEndOfLevel()) // check if win
					{
						m_level++;
						// buildNewGraph(); call to func that build new level
						m_window.close();
					}
				}
				break;
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
	}
}

void Controller::nextLevel()
{
	m_board.createNewLevel();
}

int Controller::getClicks() const
{
	return m_clicks;
}

std::pair<int, int> Controller::toIndex(const sf::Vector2f& location)const
{
	int x = location.x / RATIO;
	int y = location.y / RATIO;
	return std::pair<int, int>(x, y);
}

bool Controller::ifValidClick(int place) const
{
	return place < m_board.getRows();
}

bool Controller::winTheLevel() const
{
	if (m_board.ifEndOfLevel())
		return true;
	return false;
}

/*
void Controller::updatePath()
{
	for (size_t i = 0; i < m_board.getRows(); i++)
	{
		for (size_t j = 0; j < m_board.getCols(); j++)
		{

		}
	}
}*/

void Controller::buildGraph()
{
	std::vector <std::vector<Object*>> board = m_board.getCurrentBoard();

	for (size_t i = 0; i < m_board.getRows(); i++)
	{
		for (size_t j = 0; j < m_board.getCols(); j++)
		{
			if (m_board.ifCanUp(i))
				if (!(board[i][j]->getPosition().up.first == true && board[i - 1][j]->getPosition().down.first == true))
					m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i - 1][j]->getVertex());
			if (m_board.ifCanDown(i))
				if (!(board[i][j]->getPosition().down.first == true && board[i + 1][j]->getPosition().up.first == true))
					m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i + 1][j]->getVertex());
			if (m_board.ifCanLeft(j))
				if (!(board[i][j]->getPosition().left.first == true && board[i][j - 1]->getPosition().right.first == true))
					m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j - 1]->getVertex());
			if (m_board.ifCanRight(j))
				if (!(board[i][j]->getPosition().right.first == true && board[i][j + 1]->getPosition().left.first == true))
					m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j + 1]->getVertex());
		}
	}
}

/*void Controller::buildGraph()
{
	std::vector <std::vector<Object*>> board = m_board.getCurrentBoard();
	for (size_t i = 0; i < m_board.getRows(); i++)
		for (size_t j = 0; j < m_board.getCols(); j++)
		{
			int current_index = i * m_board.getCols() + j;

			if (m_board.ifCanUp(i) && board[i][j]->getPosition().up.first == true)
			{

				int up_index = (i - 1) * m_board.getCols() + j;
				m_levelGraph.addEdge(current_index, up_index);
			}
			if (m_board.ifCanDown(i) && board[i][j]->getPosition().down.first == true)
			{
				int down_index = (i + 1) * m_board.getCols() + j;
				m_levelGraph.addEdge(current_index, down_index);
			}
			if (m_board.ifCanRight(j) && board[i][j]->getPosition().right.first == true)
			{
				int right_index = i * m_board.getCols() + j + 1;
				m_levelGraph.addEdge(current_index, right_index);
			}
			if (m_board.ifCanLeft(j) && board[i][j]->getPosition().left.first == true)
			{
				int left_index = i * m_board.getCols() + j - 1;
				m_levelGraph.addEdge(current_index, left_index);
			}
		}
}
*/

void Controller::print()
{
	m_window.clear(sf::Color::White);
	m_board.printBoard(m_window);
	GraphicDesign::instance().printText(m_window, m_clicks);
	m_window.display();
}

void Controller::updateGraph(int i, int j)
{
	std::vector <std::vector<Object*>> board = m_board.getCurrentBoard();
	if (m_board.ifCanUp(i))
		if (!(board[i][j]->getPosition().up.first == true && board[i - 1][j]->getPosition().down.first == true))
			m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i - 1][j]->getVertex());
		else if (board[i][j]->getPosition().up.first == true && board[i - 1][j]->getPosition().down.first == true)
		{
			m_levelGraph.addEdge(board[i][j]->getVertex(), board[i - 1][j]->getVertex());
			m_levelGraph.addEdge(board[i - 1][j]->getVertex(), board[i][j]->getVertex());
		}

	if (m_board.ifCanDown(i))
		if (!(board[i][j]->getPosition().down.first == true && board[i + 1][j]->getPosition().up.first == true))
			m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i + 1][j]->getVertex());
		else if (board[i][j]->getPosition().down.first == true && board[i + 1][j]->getPosition().up.first == true)
		{
			m_levelGraph.addEdge(board[i][j]->getVertex(), board[i + 1][j]->getVertex());
			m_levelGraph.addEdge(board[i + 1][j]->getVertex(), board[i][j]->getVertex());
		}

	if (m_board.ifCanLeft(j))
		if (!(board[i][j]->getPosition().left.first == true && board[i][j - 1]->getPosition().right.first == true))
			m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j - 1]->getVertex());
		else if (board[i][j]->getPosition().left.first == true && board[i][j - 1]->getPosition().right.first == true)
		{
			m_levelGraph.addEdge(board[i][j]->getVertex(), board[i][j - 1]->getVertex());
			m_levelGraph.addEdge(board[i][j - 1]->getVertex(), board[i][j]->getVertex());
		}

	if (m_board.ifCanRight(j))
		if (!(board[i][j]->getPosition().right.first == true && board[i][j + 1]->getPosition().left.first == true))
			m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j + 1]->getVertex());
		else if (board[i][j]->getPosition().right.first == true && board[i][j + 1]->getPosition().left.first == true)
		{
			m_levelGraph.addEdge(board[i][j]->getVertex(), board[i][j + 1]->getVertex());
			m_levelGraph.addEdge(board[i][j + 1]->getVertex(), board[i][j]->getVertex());
		}
}
