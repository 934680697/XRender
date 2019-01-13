#include "Scence.h"
#include "Camera.h"
#include "Ray.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Light.h"
#include "Material_Metal.h"

using std::make_shared;
using std::shared_ptr;

Scence::Scence()
{
}


Scence::~Scence()
{
	
}



bool Scence::Initialize()
{
	Initialize_Lights();
	Initialize_Objects();
	return true;
}



void Scence::Initialize_Objects()
{
	shared_ptr<Sphere>sphere = make_shared<Sphere>(Vector3(0, 0, -0.7), 0.3);
	shared_ptr<Material_Metal>Mat = make_shared<Material_Metal>(Vector3(0,0,0),Vector3(1,0.78,0.34),6);
	shared_ptr<Primitive>First_Sphere = make_shared<Primitive>(sphere,Mat);

	this->scence_objects.push_back(First_Sphere);
	/*sphere = make_shared<Sphere>(Vector3(0, -100.5, -1), 100);
	shared_ptr<Primitive>Second_Sphere = make_shared<Primitive>(sphere);
	this->Scence_Objects.push_back(Second_Sphere);*/
}

void Scence::Initialize_Lights()
{
	shared_ptr<Light>DirectionLight = make_shared<Light>();
	DirectionLight->Set_Color(Vector3(1, 1, 1));
	DirectionLight->Set_Position(Vector3(0, 0, 0));
	DirectionLight->Set_Rotation(Vector3(0, 0, -1));
	this->scence_lights.push_back(DirectionLight);
}

Vector3 Scence::Render(Ray ray)
{
	Vector3 color;
	float Nearest_Hit_Distance = RAND_MAX;
	Hit_Data Temp_hit_data;
	bool bHit_Something = false;
	for (auto light : scence_lights)
	{
		for (auto object : scence_objects)
		{
			// Hit something in the scence
			if (object->Intersect_With_Ray(ray,*light, Temp_hit_data))
			{
				bHit_Something = true;
				float Current_Hit_Distance = (Temp_hit_data.Hit_Position - ray.GetOrigin()).Lengh();
				if (Current_Hit_Distance < Nearest_Hit_Distance)
				{
					Nearest_Hit_Distance = Current_Hit_Distance;
					color = Temp_hit_data.Color;
				}
			}
			else
			{
				ray.GetDirection().Normalize();
				float t = 0.5f * (ray.GetDirection().Y() + 1.0f);
				// lerp the color from white to target color based on Y position.
				color =  Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Vector3(0.5, 0.7, 1.0) * t;
			}
		}
	}
	return color;
}

