#include "Camera.h"
#include "Ray.h"
#include "Configfile_Parser.h"
#include "glm/glm.hpp"
#include "glm/vec3.hpp"
using 	std::shared_ptr;
Camera::Camera()
	:image_width(200),
	image_height(100),
	horizon_vector(4,0,0),
	vertical_vector(0,2,0),
	film(std::make_shared<Film>()),
	lower_left_corner_position(-2,-1,-1)
{


}
Camera::~Camera()
{

}
Ray Camera::Generate_Ray(float position_x, float position_y)
{
	glm::vec3 ray_end_position = lower_left_corner_position + horizon_vector * position_x + vertical_vector * position_y;
	return Ray(Get_Position(), ray_end_position);
}
bool Camera::Initialize(Render_Config render_config)
{
	return film->Initialize(render_config);
}

int Camera::Get_Image_Height()
{
	return image_height;
}

int Camera::Get_Image_Width()
{
	return image_width;
}

shared_ptr<Film> Camera::Get_Film()
{
	return film;
}
