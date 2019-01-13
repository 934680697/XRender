#include "Light.h"



Light::Light()
{
}


Light::~Light()
{
}

void Light::Set_Color(Vector3 Color)
{
	this->Color = Color;
}

Vector3 Light::Get_Color()
{
	return this->Color;
}
