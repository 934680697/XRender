#include "Render.h"
#include "Scence.h"
#include "Camera.h"
#include "Ray.h"
#include "Hitable.h"
#include <random>
#include <iostream>
#include "Configfile_Parser.h"
#define RAMDOM_ZERO_TO_ONE static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
#define INITIALIZE(OBJECT,RENDER_CONFIG)\
if(!(OBJECT->Initialize(RENDER_CONFIG)))\
{\
	std::cout << "Render Initialized failed" << std::endl;\
	return false;\
}\

using std::shared_ptr;
using std::make_shared;

Render::Render()
	:current_x_position(0),
	current_y_position(0),
	sample_ray_amount(100),
	reflection_depth(50)
{
}

bool Render::Initialize(Render_Config render_config)
{
	scence  = make_shared<Scence>();
	camera = make_shared<Camera>();
	sample_ray_amount = render_config.sample_amount;
	reflection_depth		 = render_config.render_depth;
	INITIALIZE(camera,render_config);
	INITIALIZE(scence,render_config);
	return true;
}

void Render::Start()
{
	for (current_y_position = camera->Get_Image_Height(); current_y_position != 0; current_y_position--)
	{
		current_x_position = 0;
		for (current_x_position; current_x_position != camera->Get_Image_Width(); current_x_position++)
		{
			glm::vec3 pixel_color = glm::vec3(0, 0, 0);
			for (int current_sample_ray = 0; current_sample_ray != sample_ray_amount; current_sample_ray++)
			{
				float end_location_x = (current_x_position + RAMDOM_ZERO_TO_ONE) / camera->Get_Image_Width();
				float end_location_y = (current_y_position + RAMDOM_ZERO_TO_ONE) / camera->Get_Image_Height();
				Ray ray = camera->Generate_Ray(end_location_x, end_location_y);
				pixel_color += scence->Render(ray, reflection_depth);
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