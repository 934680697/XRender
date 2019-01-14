#include "Render.h"
#include "Scence.h"
#include "Camera.h"
#include "Ray.h"
#include "Hitable.h"
#include <random>
#include <iostream>
#define RAMDOM_ZERO_TO_ONE static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
#define INITIALIZE(OBJECT)\
if(!(OBJECT->Initialize()))\
{\
	std::cout << "Render Initialized failed" << std::endl;\
	return false;\
}\

using std::make_shared;

Render::Render()
	:current_x_position(0),
	current_y_position(0),
	sample_ray_amount(100)
{
}

bool Render::Initialize()
{
	scence  = make_shared<Scence>();
	camera = make_shared<Camera>();
	INITIALIZE(camera);
	INITIALIZE(scence);
	return true;
}

void Render::Start()
{
	int i = 0;
	for (current_y_position = camera->Get_Image_Height(); current_y_position != 0; current_y_position--)
	{
		current_x_position = 0;
		for (current_x_position; current_x_position != camera->Get_Image_Width(); current_x_position++)
		{
			Vector3 pixel_color = Vector3(0, 0, 0);
			for (int current_sample_ray = 0; current_sample_ray != sample_ray_amount; current_sample_ray++)
			{
				float end_location_x = (current_x_position + RAMDOM_ZERO_TO_ONE) / camera->Get_Image_Width();
				float end_location_y = (current_y_position + RAMDOM_ZERO_TO_ONE) / camera->Get_Image_Height();
				Ray ray = camera->Generate_Ray(end_location_x, end_location_y);
				pixel_color += scence->Render(ray);
			}
			pixel_color /= sample_ray_amount;
			camera->Get_Film()->Draw_On_Film_Normalized_Color_Vector(pixel_color);
		}
	}
}

Render::~Render()
{

}
#undef INITIALIZE