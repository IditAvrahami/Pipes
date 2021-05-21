#include "Controller.h"
#include "Utilities.h"
#include "GraphicDesign.h"

Controller::Controller() : m_clicks(0),m_level(0), m_window(sf::VideoMode(m_board.getCols()*RATIO, (m_board.getRows()+1)*RATIO), "Pipes")
{
    
}

void Controller::startGame()
{
    std::pair<int, int> index;
    sf::Vector2f location;
    int rotation = 0;
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

            if (ifValidClick(index.second))
                {
                    //m_clicks++;
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    rotation = 270;
                    if (m_board.rotate(index.second, index.first, 270))
                        m_clicks++;
                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    rotation = 90;
                    if (m_board.rotate(index.second, index.first, 90))
                        m_clicks++;
                }
                else
                    rotation = 0;
                    /* instead of double if in the left right
                    if (m_board.rotate(index.second, index.first, rotation))
                            m_clicks++;
                     */


                     //add color(if full)
                     //check if full or have a path                        
                     //add color
                    if (winTheLevel()) // check if win
                        m_level++;
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
