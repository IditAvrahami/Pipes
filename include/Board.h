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
	
	//inits funcs
	void createNewBoard();
	void createBoard();
	void createNewLevel();
	void resizeBoard();
	void emptyBoard();
	
	//for the checks and create of the start,end and Intermediate point
	std::pair<int, int> randomPoint()const;
	std::pair<int, int> checkCollision(std::pair<int, int>& target)const;

	//head func of create start,end and Intermediate point
	void makeTheBoard(const std::pair<int, int>&, std::pair<int, int>&, const std::vector<std::pair<int, int>>&);

	//Functions create a path and objects
	void buildGraph();
	void commited_pipes(const std::vector<int>& road);
	void bulidBoard(const std::vector<std::vector<bool>>&  boolRoad);
	std::unique_ptr<RotationObject> RandomPipe(int i, int j)const;

	//functions check the kind of pipe in the path from the start point to the end point
	int numberOfNeighboors(const std::vector<std::vector<bool>>& boolRoad,int i,int j);
	std::unique_ptr<RotationObject> kindOfPipe(const std::vector<std::vector<bool>>& boolRoad, int i, int j)const;
	
	void printBoard(sf::RenderWindow& window)const;
	
	//Rotate the target in relation to those from whom it is reached
	void rotateTarget(std::pair<int, int>& target, const std::vector<int>& road);
	bool rotate(int i, int j, int direction);

	//funcs of checks
	bool ifCanUp(int i)const;
	bool ifCanDown(int i)const;
	bool ifCanRight(int j)const;
	bool ifCanLeft(int j)const;
	bool ifEndOfLevel()const;
	void fillPipes(std::vector<int> road);

	//gets
	size_t getRows()const;
	size_t getCols()const;
	Graph getGraph()const;
	std::vector <std::vector<Object*>> getCurrentBoard()const;
	std::pair<int, int> getTap();
	std::pair<int, int> getSink();
	int getTapVertexNumber();
	int getSinkVertexNumber();

	void updateCurrentBits(int x, int y, int rotation);

private:
	size_t m_rows;
	size_t m_cols;
	int m_number;
	std::pair<int, int> m_sink, m_tap;
	std::vector <std::vector<std::unique_ptr<Object>>> m_currentBoard;
	Graph m_graph;


};
