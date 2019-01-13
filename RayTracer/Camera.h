#pragma once
#include "Scence_Object.h"
#include "Film.h"
#include<memory>
using 	std::shared_ptr;
class Vector3;
class Ray;
class Camera : public Scence_Object
{
public:
	Camera();

	~Camera();

	Ray Generate_Ray(float position_x , float position_y);

	bool Initialize();

	int   Get_Image_Height();

	int   Get_Image_Width();

	shared_ptr<Film>Get_Film();

private:

	Vector3 horizon_vector;

	Vector3 vertical_vector;

	Vector3 lower_left_corner_position;

	shared_ptr<Film>film;

	int image_width;

	int image_height;

	



};

