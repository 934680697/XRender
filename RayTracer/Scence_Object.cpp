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
void Scence_Object::Set_Position(glm::vec3 position)
{
	this->position = position;
}

glm::vec3 Scence_Object::Get_Position()
{
	return this->position;
}

void Scence_Object::Set_Rotation(glm::vec3 rotation)
{
	this->rotation = rotation;
}

glm::vec3 Scence_Object::Get_Rotation()
{
	return rotation;
}

void Scence_Object::Set_Scale(glm::vec3 scale)
{
	if (scale != glm::vec3(0, 0, 0))
	{
		this->scale = scale;
	}
}

glm::vec3 Scence_Object::Get_Scale()
{
	return this->scale;
}