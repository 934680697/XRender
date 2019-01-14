#include "Scence.h"
#include "Camera.h"
#include "Ray.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Light.h"
#include "Material_Metal.h"
#include "Material_Lambertian.h"

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
	/*Gold
	shared_ptr<Sphere>sphere = make_shared<Sphere>(Vector3(0, 0, -0.7), 0.3);
	shared_ptr<Material_Metal>Mat = make_shared<Material_Metal>(Vector3(0,0,0),Vector3(1,0.78,0.34),6);
	shared_ptr<Primitive>First_Sphere = make_shared<Primitive>(sphere,Mat);
	*/
	shared_ptr<Sphere>bottom_sphere = make_shared<Sphere>(Vector3(0,-100.5, -1), 100);
	shared_ptr<Material_Lambertian>bottom_material = make_shared<Material_Lambertian>(Vector3(0.8, 0.8, 0.0));
	shared_ptr<Primitive>bottom = make_shared<Primitive>(bottom_sphere, bottom_material);


	shared_ptr<Sphere>middle_sphere = make_shared<Sphere>(Vector3(0, 0, -1), 0.5);
	shared_ptr<Material_Lambertian>middle_material = make_shared<Material_Lambertian>(Vector3(0.8, 0.3, 0.3));
	shared_ptr<Primitive>middle = make_shared<Primitive>(middle_sphere, middle_material);

	shared_ptr<Sphere>left_sphere = make_shared<Sphere>(Vector3(-1, 0, -1), 0.5);
	shared_ptr<Material_Metal>left_material = make_shared<Material_Metal>(Vector3(0.8, 0.6, 0.2), Vector3(1, 0.78, 0.34), 6);
	shared_ptr<Primitive>left = make_shared<Primitive>(left_sphere, left_material);

	shared_ptr<Sphere>right_sphere = make_shared<Sphere>(Vector3(1, 0, -1), 0.5);
	shared_ptr<Material_Metal>right_material = make_shared<Material_Metal>(Vector3(0.8, 0.8, 0.8), Vector3(1, 0.78, 0.34), 6);
	shared_ptr<Primitive>right = make_shared<Primitive>(right_sphere, right_material);

	this->scence_objects.push_back(bottom);
	this->scence_objects.push_back(left);
	this->scence_objects.push_back(right);
	this->scence_objects.push_back(middle);


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

Vector3 Scence::Render(Ray ray,int reflection_depth)
{
	Vector3 color(0,0,0);
	// reach the reflection depth
	if (reflection_depth == 0)
	{
		return color;
	}
	Hit_Data final_hit_data;
	float nearest_hit_distance = RAND_MAX;
	bool bHit_Something = false;
	for (auto light : scence_lights)
	{
		for (auto object : scence_objects)
		{
			// Hit something in the scence
			Hit_Data temp_hit_data;
			if (object->Intersect_With_Ray(ray,*light, temp_hit_data))
			{
				
				float current_hit_distance = (temp_hit_data.Hit_Position - ray.Get_Origin()).Lengh();
				if (current_hit_distance < nearest_hit_distance)
				{
					bHit_Something = true;
					nearest_hit_distance = current_hit_distance;
					final_hit_data = temp_hit_data;
				}
				
			}
			else
			{
				ray.Get_Direction().Normalize();
				float t = 0.5f * (ray.Get_Direction().Y() + 1.0f);
				// lerp the color from white to target color based on Y position.
				color =  Vector3(1.0, 1.0, 1.0) * (1.0 - t) + Vector3(0.5, 0.7, 1.0) * t;
			}
		}
		// calculating the reflection light
		if (bHit_Something)
		{
			
			if (final_hit_data.reflect_vector != Vector3(0, 0, 0))
			{
				// if we are using a reflectable shading model/
				color = final_hit_data.reflectance * Render(Ray(final_hit_data.Hit_Position, final_hit_data.reflect_vector), reflection_depth - 1);
			}
			else
			{
				// use for non reflectable shading model.
				color = final_hit_data.Color;
			}
		}
	}
	return color;
}

