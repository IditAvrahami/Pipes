#include "TPipe.h"

void TPipe::intiStruct(int number)
{
	//static bool first = true;
	if (number == 0)
	{
		m_positionNumber = 0;
		m_Position.down.first = false;
		m_Position.left.first = true;
		m_Position.right.first = true;
		m_Position.up.first = true;
	}
	else if (number == 1)
	{
		m_positionNumber = 1;
		m_Position.right.first = false;
		m_Position.left.first = true;
		m_Position.down.first = true;
		m_Position.up.first = true;
	//	if (first)
			m_objectPng.rotate(270.f);
	}
	else if (number == 2)
	{
		m_positionNumber = 2;
		m_Position.up.first = false;
		m_Position.left.first = true;
		m_Position.right.first = true;
		m_Position.down.first = true;
	//	if (first)
			m_objectPng.rotate(180.f);
	}
	else if (number == 3)
	{
		m_positionNumber = 3;
		m_Position.left.first = false;
		m_Position.up.first = true;
		m_Position.right.first = true;
		m_Position.down.first = true;
	//	if (first)
			m_objectPng.rotate(90.f);
	}
	//if (first)
	//	first = !first;
}

Position TPipe::getPosition() const
{
	return m_Position;
}

void TPipe::updateCurrentBits(int rotation)
{
	if (rotation == 90)
		m_positionNumber += 3;
	else if (rotation == 270)
		m_positionNumber += 1;
	m_positionNumber %= 4;
	//intiStruct(m_positionNumber);
	switch (m_positionNumber)
	{
	case 0:
		m_positionNumber = 0;
		m_Position.down.first = false;
		m_Position.left.first = true;
		m_Position.right.first = true;
		m_Position.up.first = true;
		break;
	case 1:
		m_positionNumber = 1;
		m_Position.right.first = false;
		m_Position.left.first = true;
		m_Position.down.first = true;
		m_Position.up.first = true;
		break;
	case 2:
		m_positionNumber = 2;
		m_Position.down.first = true;
		m_Position.right.first = false;
		m_Position.left.first = false;
		m_Position.up.first = false;
		break;
	case 3:
		m_positionNumber = 3;
		m_Position.left.first = false;
		m_Position.up.first = true;
		m_Position.right.first = true;
		m_Position.down.first = true;
		break;
	default:
		break;
	}
}
