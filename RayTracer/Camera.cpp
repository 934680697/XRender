#include "Camera.h"
#include "Film.h"
#include "Ray.h"

Camera::Camera()
{
	film						= std::make_shared<Film>();
	image_width        = 200;
	image_height      = 100;
}
Camera::~Camera()
{

}
Ray Camera::Generate_Ray(int position_x, int position_y)
{
	Vector3 ray_end_position =  (this->Get_Position() + horizon_vector * position_x + vertical_vector * position_y);
	return Ray(Get_Position(), ray_end_position.Normalize());
}
bool Camera::Initialize()
{
	film->Initialize(image_height,image_width);
}
