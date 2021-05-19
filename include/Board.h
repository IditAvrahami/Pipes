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
	void createNewLevel();
	void resizeBoard();
	void emptyBoard();
	std::pair<int, int> randomPoint()const;
	std::pair<int, int> checkCollision(std::pair<int, int>& target)const;
	void makeTheBoard(const std::pair<int, int>&,const std::pair<int, int>&,const std::vector<std::pair<int, int>>&);
	void buildGraph();
	void commited_pipes(const std::vector<int>& road);
	void bulidBoard(const std::vector<std::vector<bool>>&  boolRoad);
	int numberOfNeighboors(const std::vector<std::vector<bool>>& boolRoad,int i,int j);
	std::unique_ptr<RotationObject> kindOfPipe(const std::vector<std::vector<bool>>& boolRoad, int i, int j)const;
	std::unique_ptr<RotationObject> RandomPipe(int i,int j)const;
	void printBoard(sf::RenderWindow& window)const;
	bool ifCanUp(int i)const;
	bool ifCanDown(int i)const;
	bool ifCanRight(int j)const;
	bool ifCanLeft(int j)const;
	size_t getRows()const;
	size_t getCols()const;

private:
	size_t m_rows;
	size_t m_cols;
	int m_number;
	//std::vector <std::vector<std::unique_ptr<RotationObject>>> m_currentBoard;
	std::vector <std::vector<std::unique_ptr<Object>>> m_currentBoard;
	Graph m_graph;

};
