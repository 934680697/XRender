#include "Scence_Object.h"



Scence_Object::Scence_Object()
	:position(0,0,0), 
	rotation(0,0,0), 
	scale(1,1,1)
{

}


Scence_Object::~Scence_Object()
{

}
void Scence_Object::Set_Position(Vector3 position)
{
	this->position = position;
}

Vector3 Scence_Object::Get_Position()
{
	return this->position;
}

void Scence_Object::Set_Rotation(Vector3 rotation)
{
	this->rotation = rotation;
}

Vector3 Scence_Object::Get_Rotation()
{
	return rotation;
}

void Scence_Object::Set_Scale(Vector3 scale)
{
	if (scale != Vector3(0, 0, 0))
	{
		this->scale = scale;
	}
}

Vector3 Scence_Object::Get_Scale()
{
	return this->scale;
}