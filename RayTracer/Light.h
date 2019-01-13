#pragma once
#include "Scence_Object.h"
class Light : public Scence_Object
{
public:
	Light();

	~Light();

	void Set_Color(Vector3 Color);

	Vector3 Get_Color();

private:

	Vector3 Color;

};

