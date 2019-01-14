#pragma once
#include "Vector3.h"
class Scence_Object
{
public:
	Scence_Object();

	~Scence_Object();

	void Set_Position(Vector3 poisition);

	Vector3 Get_Position();
	
	void Set_Rotation(Vector3 rotation);

	Vector3 Get_Rotation();
	
	void Set_Scale(Vector3 scale);

	Vector3 Get_Scale();


protected:

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
};

