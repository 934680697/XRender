#pragma once
#include "Scence_Object.h"
class Light : public Scence_Object
{
public:
	Light();

	~Light();

	void Set_Color(glm::vec3 color);

	glm::vec3 Get_Color();

private:

	glm::vec3 color;

};

