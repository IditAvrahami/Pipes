#include "StraightPipe.h"

void StraightPipe::intiStruct(int number)
{
	if (number % 2 == 0)
	{
		m_Position.left.first = true;
		m_Position.right.first = true;
	}
	else
	{
		m_Position.up.first = true;
		m_Position.down.first = true;
		m_objectPng.rotate(90.f);
	}
}
