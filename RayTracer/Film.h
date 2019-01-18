#pragma once
#include <fstream>
#include <string>
#include "glm/vec3.hpp"
struct Render_Config;
class Film
{
public:

	Film();

	~Film();

	bool Initialize(Render_Config render_config);

	void Draw_On_Film_Normalized_Color_Vector(glm::vec3 color);

	int Get_Image_Width();

	int Get_Image_Height();

private:

	/* Uncopyable*/
	Film(const Film & film) = delete;
	Film(const Film && film) = delete;
	void operator=(const Film & film) = delete;
	void operator=(const Film && film) = delete;

	void Draw_On_Film_Normalized_Color(float normalized_r_color, float normalized_g_color, float normalized_b_color);

	void Draw_On_Film(float r_color, float g_color, float b_color);

	int				 image_width;

	int				 image_height;

	std::fstream   image_file;

	std::string	     image_name;

	std::string	     image_directory;
};

