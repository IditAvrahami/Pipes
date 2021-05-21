#include "PlusPipe.h"

void PlusPipe::intiStruct(int number)
{
	m_Position.down.first = true;
	m_Position.left.first = true;
	m_Position.right.first = true;
	m_Position.up.first = true;
}

Position PlusPipe::getPosition() const
{
	return m_Position;
}
