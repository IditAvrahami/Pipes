#include "StraightPipe.h"

void StraightPipe::intiStruct(int number)
{
	if (number % 2 == 0)
	{
		m_positionNumber = 0;
		m_Position.up.first = false;
		m_Position.down.first = false;
		m_Position.left.first = true;
		m_Position.right.first = true;
	}
	else
	{
		m_positionNumber = 1;
		m_Position.left.first = false;
		m_Position.right.first = false;
		m_Position.up.first = true;
		m_Position.down.first = true;
		m_objectPng.rotate(90.f);
	}

}

Position StraightPipe::getPosition() const
{
	return m_Position;
}

void StraightPipe::updateCurrentBits(int rotation)
{
	m_positionNumber++;
	m_positionNumber %= 2;
	switch (m_positionNumber)
	{
	case 0:
		m_positionNumber = 0;
		m_Position.up.first = false;
		m_Position.down.first = false;
		m_Position.left.first = true;
		m_Position.right.first = true;
		break;
	case 1:
		m_positionNumber = 1;
		m_Position.left.first = false;
		m_Position.right.first = false;
		m_Position.up.first = true;
		m_Position.down.first = true;
		break;
	default:
		break;
	}
}
