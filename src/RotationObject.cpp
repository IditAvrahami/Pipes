#include "RotationObject.h"

bool RotationObject::rotation(const float direction)
{
	Object::m_objectPng.rotate(direction);
	return true;
}
