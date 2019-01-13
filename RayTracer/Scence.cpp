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



void Scence::Initialize()
{
	Initialize_Camera();
	Initialize_Lights();
	Initialize_Objects();
}

void Scence::Initialize_Camera()
{
	Scence_Camera = make_shared<Camera>();
}

void Scence::Initialize_Objects()
{
	shared_ptr<Sphere>sphere = make_shared<Sphere>(Vector3(0, 0, -0.7), 0.3);
	shared_ptr<Material_Metal>Mat = make_shared<Material_Metal>(Vector3(0,0,0),Vector3(1,0.78,0.34),6);
	shared_ptr<Primitive>First_Sphere = make_shared<Primitive>(sphere,Mat);

	this->Scence_Objects.push_back(First_Sphere);
	/*sphere = make_shared<Sphere>(Vector3(0, -100.5, -1), 100);
	shared_ptr<Primitive>Second_Sphere = make_shared<Primitive>(sphere);
	this->Scence_Objects.push_back(Second_Sphere);*/
}

void Scence::Initialize_Lights()
{
	shared_ptr<Light>DirectionLight = make_shared<Light>();
	DirectionLight->Set_Color(Vector3(1, 1, 1));
	DirectionLight->Set_Position(Vector3(0, 0, 0));
	//DirectionLight->Set_Rotation(Vector3(-1, -1, -1));
	DirectionLight->Set_Rotation(Vector3(0, 0, -1));

	this->Scence_Lights.push_back(DirectionLight);
}

bool Scence::Render(Ray ray, Hit_Data & hitdata)
{
	float Nearest_Hit_Distance = RAND_MAX;
	Hit_Data Temp_hit_data;
	bool bHit_Something = false;
	for (auto light : Scence_Lights)
	{
		for (auto Scence_Object : Scence_Objects)
		{
			if (Scence_Object->Intersect_With_Ray(ray,*light, Temp_hit_data))
			{
				bHit_Something = true;
				float Current_Hit_Distance = (Temp_hit_data.Hit_Position - ray.GetOrigin()).Lengh();
				if (Current_Hit_Distance < Nearest_Hit_Distance)
				{
					Nearest_Hit_Distance = Current_Hit_Distance;
					hitdata = Temp_hit_data;
				}
			}
		}
	}
	return bHit_Something;
}

