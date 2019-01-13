#pragma once
#include "Vector3.h"
class Scence_Object
{
public:
	Scence_Object();

	~Scence_Object();

	void Set_Position(Vector3 Poisition);

	Vector3 Get_Position();
	
	void Set_Rotation(Vector3 Rotation);

	Vector3 Get_Rotation();
	
	void Set_Scale(Vector3 Scale);

	Vector3 Get_Scale();


protected:

	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

