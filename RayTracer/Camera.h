#pragma once
#include "Scence_Object.h"
#include "Film.h"
#include<memory>
struct Render_Config;
class Ray;
class Camera : public Scence_Object
{
public:
	Camera();

	~Camera();

	Ray Generate_Ray(float position_x , float position_y);

	bool Initialize(Render_Config render_config);

	int   Get_Image_Height();

	int   Get_Image_Width();

	std::shared_ptr<Film>Get_Film();

private:

	/* Uncopyable*/
	Camera(const Camera & camera) = delete;
	Camera(const Camera && camera) = delete;
	void operator=(const Camera & camera) = delete;
	void operator=(const Camera && camera) = delete;

	glm::vec3 horizon_vector;

	glm::vec3 vertical_vector;

	glm::vec3 lower_left_corner_position;

	std::shared_ptr<Film>film;

	int image_width;

	int image_height;

	



};

