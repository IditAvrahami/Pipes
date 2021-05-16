#pragma once
#include <iostream>
#include <vector>
#include <utility>  //declarations of unique_ptr
#include <memory>
#include "RotationObject.h"
#include "Object.h"
#include "Graph.h"
using std::unique_ptr;


class Board
{
public:
	Board();
	~Board() = default;
	void createBoard();
	void resizeBoard();
	void emptyBoard();
	std::pair<int, int> randomPoint()const;
	std::pair<int, int> checkCollision(std::pair<int, int>& target)const;
	void makeTheBoard(const std::pair<int, int>&,const std::pair<int, int>&,const std::vector<std::pair<int, int>>&);
	void buildGraph();

private:
	size_t m_rows;
	size_t m_cols;
	int m_number;
	//std::vector <std::vector<std::unique_ptr<RotationObject>>> m_currentBoard;
	std::vector <std::vector<std::unique_ptr<Object>>> m_currentBoard;
	Graph m_graph;

};
