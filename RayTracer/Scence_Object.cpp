#include "Scence_Object.h"



Scence_Object::Scence_Object()
{
	this->Position = Vector3(0.0, 0.0, 0.0);
	this->Rotation = Vector3(0.0, 0.0, 0.0);
	this->Scale = Vector3(1.0, 1.0, 1.0);
}


Scence_Object::~Scence_Object()
{

}
void Scence_Object::Set_Position(Vector3 Poisition)
{
	this->Position = Position;
}

Vector3 Scence_Object::Get_Position()
{
	return this->Position;
}

void Scence_Object::Set_Rotation(Vector3 Rotation)
{
	this->Rotation = Rotation;
}

Vector3 Scence_Object::Get_Rotation()
{
	return Rotation;
}

void Scence_Object::Set_Scale(Vector3 Scale)
{
	if (Scale != Vector3(0, 0, 0))
	{
		this->Scale = Scale;
	}
}

Vector3 Scence_Object::Get_Scale()
{
	return this->Scale;
}