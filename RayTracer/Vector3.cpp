#pragma once
#include "Vector3.h"
Vector3::Vector3()
{
	Value[0] = 0;
	Value[1] = 0;
	Value[2] = 0;
}
Vector3::Vector3(float x /*= 0*/, float y /*= 0 */, float z /*= 0*/)
{
	Value[0] = x;
	Value[1] = y;
	Value[2] = z;
}
