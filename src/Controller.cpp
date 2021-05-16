#include "Controller.h"

Controller::Controller() : m_clicks(0), m_window(sf::VideoMode(m_board.getCols()*10, m_board.getRows()*10), "Pipes")
{
}

void Controller::startGame()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
    }

}

int Controller::getClicks() const
{
    return m_clicks;
}
