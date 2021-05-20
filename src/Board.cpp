#include "Board.h"
#include "Object.h"
#include "Tap.h"
#include "Sink.h"
#include "PlusPipe.h"
#include "TPipe.h"
#include "StraightPipe.h"
#include "CornerPipe.h"
#include "Utilities.h"
#include "GraphicDesign.h"
#include <stdlib.h>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <iostream>

Board::Board() : m_cols(5), m_rows(5), m_number(0),m_graph(25)
{
	//change this to dibug, for same result
	srand(23081999);
	//srand(time(NULL));
	m_rows = 3;
	m_cols = 3;
//	m_rows = (rand() % 10) + 5; // between 5-15
//	m_cols = (rand() % 10) + 5;
	m_graph.setVertexes(m_rows * m_cols);
	createBoard();
	GraphicDesign::instance().setTextPosition(m_rows, m_cols);
}

void Board::createBoard()
{
	std::pair<int, int> source, target;
	sf::Vector2f newLocation;
	resizeBoard();
	emptyBoard();


	//the start point of the level
	source = randomPoint();
	//create the tap object in this place
	m_currentBoard[source.first][source.second] = std::make_unique<Tap>(source.first * m_cols + source.second, TAP);
	m_currentBoard[source.first][source.second]->setLocation(source.first, source.second);
	m_tap.first = source.first;
	m_tap.second = source.second;
	m_currentBoard[source.first][source.second]->intiStruct(rand() % 4);


	//the target point of the level
	target = randomPoint();
	//check if the start and target points collide, if so random the point again
	target = checkCollision(target);
	//create the sink object in this place
	m_currentBoard[target.first][target.second] = std::make_unique<Sink>(target.first * m_cols + target.second, SINK); 
	m_currentBoard[target.first][target.second]->setLocation(target.first, target.second);
	m_sink.first = target.first;
	m_sink.second = target.second;
	m_currentBoard[target.first][target.second]->intiStruct(rand() % 4);

	//create dots in random place so the level wont be so easy
	std::vector<std::pair<int, int>> dots;
	dots.resize((m_rows * m_cols) / 30);
	for (size_t i = 0; i < dots.size(); i++)
	{
		dots[i] = randomPoint();
		checkCollision(dots[i]);
		m_currentBoard[dots[i].first][dots[i].second] = std::make_unique<PlusPipe>(dots[i].first * m_cols + dots[i].second, PLUS_PIPE);
		m_currentBoard[dots[i].first][dots[i].second]->setLocation(dots[i].first, dots[i].second);
		m_currentBoard[dots[i].first][dots[i].second]->intiStruct(rand() % 4);
	}
	//create the level itself, make sure the level is solveable
	makeTheBoard(source, target, dots);

}

void Board::createNewLevel()
{
	//	m_rows = (rand() % 10) + 5; // between 5-15
//	m_cols = (rand() % 10) + 5;
	m_graph.setVertexes(m_rows * m_cols);
	createBoard();
}

void Board::resizeBoard()
{
	m_currentBoard.resize(m_rows);
	for (size_t i = 0; i < m_rows; i++)
	{
		m_currentBoard[i].resize(m_cols);
	}
}

void Board::emptyBoard()
{
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
		{
			m_currentBoard[i][j] = nullptr;
		}
	}
}

std::pair<int, int> Board::randomPoint() const
{
	int x, y;
	x = (rand() % m_rows);
	y = (rand() % m_cols);
	return std::pair(x, y);
}

std::pair<int, int> Board::checkCollision(std::pair<int, int>& target) const
{
	while (true)
	{
		if (m_currentBoard[target.first][target.second] != nullptr)
			target = randomPoint();
		else
			return target;
	}
}

void Board::makeTheBoard(const std::pair<int, int>& source, const std::pair<int, int>& target,
	const std::vector<std::pair<int, int>>& dots)
{
	std::vector<int> temp;
	std::vector<int> road;
	int s, t;

	buildGraph();
	s = m_currentBoard[source.first][source.second]->getVertex();
	for (size_t i = 0; i < dots.size(); i++)
	{
		t = m_currentBoard[dots[i].first][dots[i].second]->getVertex();
		m_graph.BFS(s, t);
		temp = m_graph.getVertex();
		std::copy(temp.begin(), temp.end(), std::back_inserter(road));
		s = t;
	}
	t = m_currentBoard[target.first][target.second]->getVertex();
	m_graph.BFS(s, t);
	temp = m_graph.getVertex();
	std::copy(temp.begin(), temp.end(), std::back_inserter(road));	
	
	commited_pipes(road);
}

void Board::buildGraph()
{
	for (int i = 0; i < m_rows ; i++)
		for (int j = 0; j < m_cols; j++)
		{
			int current_index = i * m_cols + j;

			if (ifCanUp(i))
			{
				int up_index = (i - 1) * m_cols + j;
				m_graph.addEdge(current_index, up_index);
			}
			if (ifCanDown(i))
			{
				int down_index = (i + 1) * m_cols + j;
				m_graph.addEdge(current_index, down_index);
			}
			if (ifCanRight(j))
			{
				int right_index = i * m_cols + j + 1;
				m_graph.addEdge(current_index, right_index);
			}
			if (ifCanLeft(j))
			{
				int left_index = i * m_cols + j - 1;
				m_graph.addEdge(current_index, left_index);
			}
		}
}

void Board::commited_pipes(const std::vector<int>& road)
{
	std::vector<std::vector<bool>> boolRoad;
	boolRoad.resize(m_rows);
	for (size_t i = 0; i < m_rows; i++)
	{
		boolRoad[i].resize(m_cols);
	}
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
		{
			boolRoad[i][j] = false;
		}
	}
	int temp, x, y;
	for (size_t i = 0; i < road.size() ; i++)
	{
		temp = road[i];
		y = temp / m_cols;
		x = temp - y*m_cols;
		boolRoad[y][x] = true;
	}
	bulidBoard(boolRoad);
	

}

void Board::bulidBoard(const std::vector < std::vector<bool>>& boolRoad)
{
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols; j++)
		{
			if (!m_currentBoard[i][j])
			{
				if (boolRoad[i][j])
				{
					if (numberOfNeighboors(boolRoad, i, j) == 4)
					{
						m_currentBoard[i][j] = std::make_unique<PlusPipe>(i * m_cols + j, PLUS_PIPE);
					}
					else if (numberOfNeighboors(boolRoad, i, j) == 3)
					{
						m_currentBoard[i][j] = std::make_unique<TPipe>(i * m_cols + j, TPIPE);
					}
					else if (numberOfNeighboors(boolRoad, i, j) == 2)
					{
						m_currentBoard[i][j] = kindOfPipe(boolRoad, i, j);
					}
					else if (numberOfNeighboors(boolRoad, i, j) == 1)
					{
						m_currentBoard[i][j] = std::make_unique<StraightPipe>(i * m_cols + j, STRIGHT_PIIPE);
					}
				}
				else
				{
					m_currentBoard[i][j] = RandomPipe(i, j);
				}
				m_currentBoard[i][j]->setLocation(i, j);
				m_currentBoard[i][j]->intiStruct(rand() % 4);
			}
		}
	}
}

int Board::numberOfNeighboors(const std::vector<std::vector<bool>>& boolRoad, int i, int j)
{
	int counter = 0;
	int index;
	
	if (ifCanUp(i)) // check up
	{
		index = i - 1;
		if (boolRoad[index][j])
			counter++;
	}
	if (ifCanDown(i)) // check down
	{
		index = i + 1;
		if (boolRoad[index][j])
			counter++;
	}
	if (ifCanRight(j)) // check right
	{
		index = j + 1;
		if (boolRoad[i][index])
			counter++;
	}
	if (ifCanLeft(j)) // check left
	{
		index = j - 1;
		if (boolRoad[i][index])
			counter++;
	}

	return counter;
}

std::unique_ptr<RotationObject> Board::kindOfPipe(const std::vector<std::vector<bool>>& boolRoad, int i, int j)const
{
	int index1, index2;
	if (ifCanUp(i) && ifCanDown(i))
	{
		index1 = i - 1;
		index2 = i + 1;
		if (boolRoad[index1][j] == true && boolRoad[index2][j] == true)
			return std::make_unique<StraightPipe>(i * m_cols + j, STRIGHT_PIIPE);
	}
	if (ifCanLeft(j) && ifCanRight(j))
	{
		index1 = j - 1;
		index2 = j + 1;
		if (boolRoad[i][index1] == true && boolRoad[i][index2] == true)
			return std::make_unique<StraightPipe>(i * m_cols + j,STRIGHT_PIIPE);
	}
	return std::make_unique<CornerPipe>(i * m_cols + j, CORNER_PIPE);
}

std::unique_ptr<RotationObject> Board::RandomPipe(int i, int j) const
{
	int random = rand() % 12;
	if (random < 6)
		return std::make_unique<StraightPipe>(i * m_cols + j, STRIGHT_PIIPE);
	if (random < 9)
		return std::make_unique<CornerPipe>(i * m_cols + j, CORNER_PIPE);
	if (random < 11)
		return std::make_unique<TPipe>(i * m_cols + j, TPIPE);
	return std::make_unique<PlusPipe>(i * m_cols + j, PLUS_PIPE);
}

void Board::printBoard(sf::RenderWindow& window)const
{
	for (size_t i = 0; i < m_rows; i++)
	{
		for (size_t j = 0; j < m_cols ; j++)
		{
			m_currentBoard[i][j]->printObject(window);
		}
	}
}

void Board::rotate(int i, int j, int angel)
{
		m_currentBoard[i][j]->rotation(float(angel));
}

bool Board::ifCanUp(int i) const
{
	if (i != 0)
		return true;
	return false;
}

bool Board::ifCanDown(int i) const
{
	if (i != m_rows - 1)
		return true;
	return false;
}

bool Board::ifCanRight(int j) const
{
	if (j != m_cols - 1)
		return true;
	return false;
}

bool Board::ifCanLeft(int j) const
{
	if (j != 0)
		return true;
	return false;
}

size_t Board::getRows() const
{
	return m_rows;
}

size_t Board::getCols() const
{
	return m_cols;
}

bool Board::ifEndOfLevel() const
{
	if (m_currentBoard[m_tap.first][m_tap.second]->ifFull() && m_currentBoard[m_sink.first][m_sink.second]->ifFull())
		return true;
	return false;
}
