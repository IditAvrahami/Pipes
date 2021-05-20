#include "Controller.h"
#include "Utilities.h"

Controller::Controller() : m_clicks(0),m_level(0), m_window(sf::VideoMode(m_board.getCols()*RATIO, (m_board.getRows()+1)*RATIO), "Pipes")
{
    
}

void Controller::startGame()
{
    std::pair<int, int> index;
    sf::Vector2f location;
    while (m_window.isOpen())
    {
        m_window.clear();
        m_board.printBoard(m_window); // add click ti print
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
            if (ifValidClick(index.first)) // to check
                {
                    if (sf::Mouse::Left)
                    {
                        //rotation to left + add color      
                    }
                    else if(sf::Mouse::Right)
                    { }
                        //rotation to right + add color(if full)
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
