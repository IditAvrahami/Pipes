#include "Board.h"
#include "Object.h"
#include "Tap.h"
#include "Sink.h"
#include "PlusPipe.h"
#include <stdlib.h>
#include <time.h>

Board::Board() : m_cols(5), m_rows(5), m_number(0)
{
	//change this to dibug, for same result
	srand(23081999);
	//srand(time(NULL));
	m_rows = (rand() % 10) + 5; // between 5-15
	m_cols = (rand() % 10) + 5;
}

void Board::createBoard()
{
	std::pair<int, int> source, target;
	resizeBoard();
	emptyBoard();
	//the start point of the level
	source = randomPoint();
	//create the tap object in this place
	m_currentBoard[source.first][source.second] = std::make_unique<Tap*>(m_number);
	m_number++;
	//the target point of the level
	target = randomPoint();
	//check if the start and target points collide, if so random the point again
	target = checkCollision(target);
	//create the sink object in this place
	m_currentBoard[target.first][target.second] = std::make_unique<Sink*>(m_number);
	m_number++;
	//create dots in random place so the level wont be so easy
	std::vector<std::pair<int, int>> dots;
	dots.resize((m_rows * m_cols) / 30);
	for (size_t i = 0; i < dots.size(); i++)
	{
		dots[i] = randomPoint();
		checkCollision(dots[i]);
		m_currentBoard[target.first][target.second] = std::make_unique<PlusPipe*>(m_number);
		m_number++;
	}
	//create the level itself, make sure the level is solveable
	makeTheBoard(source, target, dots);

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
			m_currentBoard[i][j] = std::make_unique<RotationObject>(nullptr);
		}
	}
}

std::pair<int, int> Board::randomPoint() const
{
	int x, y;
	x = (rand() % m_rows);
	y = (rand() % m_cols);
	return (x, y);
}

std::pair<int, int> Board::checkCollision(std::pair<int x, int y>& target) const
{
	while (true)
	{
		if (m_currentBoard[target.first][target.second] != nullptr)
			target = randomPoint();
		else
//			m_currentBoard[target.first][target.second] = std::make_unique<type*>();
			return target;
	}
}

void Board::makeTheBoard(const std::pair<int, int>& source, const std::pair<int, int>& target,
	const std::vector<std::pair<int, int>>& dots)
{
	std::vector<int> road;
	int s, t;
	s = (*m_currentBoard[source.first][source.second])->getVertex();
	
	//numberOfVertex();
	//need to do
	buildGraph();

	for (size_t i = 0; i < dots.size(); i++)
	{
		t = (*m_currentBoard[dots[i].first][dots[i].second])->getVertex();
		m_graph.BFS(s, t);
		road += m_graph.getVertex();
		//road += m_graph.BFS(s, t);
		//update board
		s = t;
	}
	t = (*m_currentBoard[target.first][target.second])->getVertex();
	m_graph.BFS(s, t);
	road += m_graph.getVertex();
	
	//need to do
	commited_pipes();
}

