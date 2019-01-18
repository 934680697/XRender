#pragma once
#include "Ray.h"
#include "glm/vec3.hpp"

struct Hit_Data
{
	glm::vec3 Color;
	glm::vec3 Hit_Position;
	glm::vec3 Hit_Normal;
	glm::vec3 reflectance;
	glm::vec3 reflect_vector;
};

class Hitable
{
public:

	Hitable();

	~Hitable();

	virtual bool Hit_Test(Ray & ray, Hit_Data & hit_data) { return false; }

};

