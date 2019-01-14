#pragma once
#include "Scence_Object.h"
#include "Hitable.h"
#include <memory>
class Ray;
class Material;
class Light;
class Primitive : public Scence_Object
{
public:
	Primitive();

	Primitive(std::shared_ptr<Hitable>Shape,std::shared_ptr<Material>Mat);

	~Primitive();

	bool Intersect_With_Ray(Ray & ray , Light & light, Hit_Data & hit_data);

private:
	
	std::shared_ptr<Hitable>shape;
	std::shared_ptr<Material>material;

};

