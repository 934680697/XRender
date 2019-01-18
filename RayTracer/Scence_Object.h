#pragma once
#include "glm/vec3.hpp"
class Scence_Object
{
public:
	Scence_Object();

	~Scence_Object();

	void Set_Position(glm::vec3 poisition);

	glm::vec3 Get_Position();
	
	void Set_Rotation(glm::vec3 rotation);

	glm::vec3 Get_Rotation();
	
	void Set_Scale(glm::vec3 scale);

	glm::vec3 Get_Scale();


protected:

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

