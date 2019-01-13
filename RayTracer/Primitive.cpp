#include "Primitive.h"
#include "Hitable.h"
#include "Sphere.h"
#include "Material.h"
#include "Light.h"


Primitive::Primitive()
{

}



Primitive::Primitive(std::shared_ptr<Hitable>Shape, std::shared_ptr<Material>Mat)
{
	this->Shape = Shape;
	this->Mat = Mat;
}

Primitive::~Primitive()
{
	this->Shape.reset();
}

bool Primitive::	Intersect_With_Ray(Ray & ray, Light & light, Hit_Data & hit_data)
{
	if (Shape->Hit_Test(ray, hit_data))
	{
		this->Mat->Shading(ray, light, hit_data);
		return true;
	 }
	return false;

}
