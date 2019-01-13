#pragma once
#include <fstream>
#include <string>
using std::fstream;
using std::string;
class Film
{
public:

	Film();

	~Film();

	bool Initialize(int image_height, int image_width);

	void Draw_On_Film_Normalized_Color(float normalized_r_color, float normalized_g_color, float normalized_b_color);

	void Draw_On_Film(float r_color, float g_color, float b_color);


	int Get_Image_Width();

	int Get_Image_Height();


private:

	int		 image_width;

	int		 image_height;

	fstream image_file;

	string	 image_name;

	string	 image_directory;
};

