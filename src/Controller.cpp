#include "Controller.h"
#include "Utilities.h"
#include "GraphicDesign.h"

Controller::Controller() : m_clicks(0),m_level(0), m_window(sf::VideoMode(m_board.getCols()*RATIO, (m_board.getRows()+1)*RATIO), "Pipes"),
m_levelGraph(m_board.getCols()*m_board.getRows())
{
    
}

void Controller::startGame()
{
    std::pair<int, int> index;
    sf::Vector2f location;
    m_levelGraph = m_board.getGraph();
    buildGraph();
    while (m_window.isOpen())
    {
        if (m_level == 4)
            endGame();
        // check of end of game and print bye message
        m_window.clear(sf::Color::White);
        //m_window.clear();
        GraphicDesign::instance().printBack(m_window);

        m_board.printBoard(m_window); // add click to print
        GraphicDesign::instance().printText(m_window, m_clicks);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case event.MouseButtonPressed:
              //  m_board.printBoard(m_window);
                location.x = event.mouseButton.x;
                location.y = event.mouseButton.y;
                
                index = toIndex(location);
                m_clicks++;
            if (ifValidClick(index.first))
                {
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                        m_board.rotate(index.second, index.first, 270);          
                    }
                    else if(event.mouseButton.button == sf::Mouse::Left )
                    {
                        m_board.rotate(index.second, index.first, 90);
                    }
                   // updatePath();///////////////////////////////////////
                     //check if full or have a path                        
                     //add color(if full)
                    if (winTheLevel()) // check if win
                    {
                        m_level++;
                       // buildNewGraph(); call to func that build new level
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
    return std::pair<int, int>(x,y);
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
            {
                if (!(board[i][j]->getPosition().up.first == true && board[i-1][j]->getPosition().down.first == true))
                {
                    m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i - 1][j]->getVertex());
                }
                else
                {///// update something
                }
                if (m_board.ifCanDown(i))
                {
                    if (!(board[i][j]->getPosition().down.first == true && board[i + 1][j]->getPosition().up.first == true))
                    {
                        m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i + 1][j]->getVertex());
                    }
                    else
                    {///// update something
                    }
                }
                if (m_board.ifCanLeft(j))
                {
                    if (!(board[i][j]->getPosition().left.first == true && board[i][j+1]->getPosition().right.first == true))
                    {
                        m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j + 1]->getVertex());
                    }
                    else
                    {///// update something
                    }
                }
                if (m_board.ifCanRight(j))
                {
                    if (!(board[i][j]->getPosition().right.first == true && board[i][j - 1]->getPosition().left.first == true))
                    {
                        m_levelGraph.reduceEdge(board[i][j]->getVertex(), board[i][j - 1]->getVertex());
                    }
                    else
                    {///// update something
                    }
                }
            }
            
        }
    }
}
