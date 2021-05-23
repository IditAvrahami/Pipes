#include "StraightPipe.h"

void StraightPipe::intiStruct(int number)
{
	//static bool first = true;
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
	//	if (first)
			m_objectPng.rotate(90.f);
	}
	//if (first)
	//	first = !first;
}

Position StraightPipe::getPosition() const
{
	return m_Position;
}

void StraightPipe::updateCurrentBits(int rotation)
{
	m_positionNumber++;
	m_positionNumber %= 2;
	//intiStruct(m_positionNumber);
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
