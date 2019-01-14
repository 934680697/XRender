#include "Film.h"
#include "Vector3.h"
#include <iostream>
#define SPACE " "

Film::Film():image_height(100),image_width(200),image_directory("G:/Project/C++/RayTracer/OutPut/"),image_name("NewFramework.ppm")
{
	
}
Film::~Film()
{
	image_file.close();
}
bool Film::Initialize(int image_height, int image_width)
{
	this->image_height = image_height;
	this->image_width  = image_width;
	image_file.open(image_directory + image_name);
	if (!image_file.is_open())
	{
		std::cout << "Film initialized failed."  << std::endl;
		std::cout << "The file name is illegal"<< std::endl;
		return false;
	}
	else
	{
		image_file << "P3\n" << image_width << SPACE << image_height << "\n255\n";
	}
}

void Film::Draw_On_Film_Normalized_Color_Vector(Vector3 color)
{
	Draw_On_Film_Normalized_Color(color.R(), color.G(), color.B());
}

void Film::Draw_On_Film_Normalized_Color(float normalized_r_color, float normalized_g_color, float normalized_b_color)
{
	float final_r_color  = int(normalized_r_color * 255.99);
	float final_g_color = int(normalized_g_color * 255.99);
	float final_b_color = int(normalized_b_color * 255.99);
	Draw_On_Film(final_r_color, final_g_color, final_b_color);
}
void Film::Draw_On_Film(float r_color, float g_color, float b_color)
{
	image_file << r_color << SPACE << g_color << SPACE << b_color << "\n";
}

int Film::Get_Image_Width()
{
	return this->image_width;
}

int Film::Get_Image_Height()
{
	return this->image_height;
}
#undef  SPACE