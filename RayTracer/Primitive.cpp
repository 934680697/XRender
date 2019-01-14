#include "Primitive.h"
#include "Hitable.h"
#include "Sphere.h"
#include "Material.h"
#include "Light.h"


Primitive::Primitive()
{

}



Primitive::Primitive(std::shared_ptr<Hitable>shape, std::shared_ptr<Material>material):shape(shape), material(material)
{
}

Primitive::~Primitive()
{
	this->shape.reset();
}

bool Primitive::	Intersect_With_Ray(Ray & ray, Light & light, Hit_Data & hit_data)
{
	if (shape->Hit_Test(ray, hit_data))
	{
		this->material->Shading(ray, light, hit_data);
		return true;
	 }
	return false;

}
