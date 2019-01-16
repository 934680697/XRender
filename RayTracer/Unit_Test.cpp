#include "Unit_Test.h"
#include <iostream>

using std::cout;
using std::endl;
Unit_Test::Unit_Test()
{
}


Unit_Test::~Unit_Test()
{

}

void Unit_Test::Test_Vector()
{
	std::string Value = "Value";
	std::string Normalize = "Normalize";

	auto Display_Vector = [](Vector3 vec, std::string des = "Value") {std::cout << "The " << des << " of vector is x = " << vec.X() << " y = " << vec.Y() << " z = " << vec.Z() << std::endl; };
	auto Display_Vector_Dot = [](Vector3 vec1, Vector3 vec2) {std::cout << "The dot value of them is " << vec1.Dot(vec2) << std::endl; };
	auto Display_Vector_Length = [](Vector3 vec) {std::cout << "The length value  is " << vec.Lengh() << std::endl; };

	Vector3 Vec1(3, 3, 3);
	Vector3 Vec2(4, 2, 5);
	Vector3 Vec3(1, 0, 0);
	Vector3 Vec4(0.2, 0.1, 0.9);
	Display_Vector(1 - Vec4);
	Display_Vector(Vec1 + Vec2);
	Display_Vector(Vec1 - Vec2);
	Display_Vector(Vec1 * 3);
	Display_Vector_Length(Vec1);
	Display_Vector_Dot(Vec1, Vec2);
	Display_Vector(Vec1.Normalize(), Normalize);
}

void Unit_Test::Test_Configfile_Parser(std::string dreactory)
{
	Render_Config render_config;
	bool b_IsSuccsee = Configfile_Parser::Read_Config_File(dreactory, render_config);
	if (!b_IsSuccsee)
	{
		cout << "file parsing failed" << endl;
	}
	else
	{
		cout << "The image_width is" << render_config.image_width << endl;
		cout << "The image_height is" << render_config.image_height << endl;
		cout << "The sample_amount is" << render_config.sample_amount << endl;
		cout << "The image_directory is" << render_config.image_directory << endl;
		cout << "The image_name is" << render_config.image_name << endl;
	}
}
