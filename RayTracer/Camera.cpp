#include "Camera.h"
#include "Ray.h"

Camera::Camera()
{
	Position								= Vector3(0, 0, 0);
	image_width						= 200;
	image_height						= 100;
	horizon_vector					    = Vector3(4, 0, 0);
	vertical_vector					    = Vector3(0, 2, 0);
	film								        = std::make_shared<Film>();
	lower_left_corner_position  = Vector3(-2, -1, -1);

}
Camera::~Camera()
{

}
Ray Camera::Generate_Ray(float position_x, float position_y)
{
	Vector3 ray_end_position = lower_left_corner_position + horizon_vector * position_x + vertical_vector * position_y;
	return Ray(Get_Position(), ray_end_position);
}
bool Camera::Initialize()
{
	return film->Initialize(image_height,image_width);
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
