#pragma once
#include "glm/vec3.hpp"
struct  Hit_Data;
class Ray;
class Light;

class Material
{
public:

	Material();

	Material(glm::vec3 diffuse_Color);

	~Material();

	virtual void Shading(Ray & ray, Light & light, Hit_Data & hit_data);

protected:

	glm::vec3 Cal_Reflect_Vector(glm::vec3 incident_light, glm::vec3 normal);

	glm::vec3 diffuse_Color;

	


};

