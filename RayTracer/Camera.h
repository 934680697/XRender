#pragma once
#include "Scence_Object.h"
#include<memory>
using 	std::shared_ptr;
class Vector3;
class Film;
class Ray;
class Camera : public Scence_Object
{
public:
	Camera();

	~Camera();

	Ray Generate_Ray(int position_x , int position_y);

	bool Initialize();

private:

	Vector3 horizon_vector;

	Vector3 vertical_vector;

	Vector3 top_left_corner_position;

	shared_ptr<Film>film;

	int image_width;

	int image_height;

	



};

