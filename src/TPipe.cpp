#include "TPipe.h"

void TPipe::intiStruct(int number)
{
	if (number == 0)
	{
		m_Position.left.first = true;
		m_Position.right.first = true;
		m_Position.up.first = true;
	}
	else if (number == 1)
	{
		m_Position.left.first = true;
		m_Position.down.first = true;
		m_Position.up.first = true;
		m_objectPng.rotate(270.f);
	}
	else if (number == 2)
	{
		m_Position.left.first = true;
		m_Position.right.first = true;
		m_Position.down.first = true;
		m_objectPng.rotate(180.f);
	}
	else if (number == 3)
	{
		m_Position.up.first = true;
		m_Position.right.first = true;
		m_Position.down.first = true;
		m_objectPng.rotate(90.f);
	}
}
