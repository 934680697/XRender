#include "Render.h"

int main()
{
	Render * render = new Render();
	render->Initialize();
	render->Start();
	delete render;
	return 0;
}

/*Vector3 Random_in_Unit_Sphere()
{
	Vector3 Point;
	do
	{
		float x = RAMDOM_ZERO_TO_ONE;
		float y = RAMDOM_ZERO_TO_ONE;
		float z = RAMDOM_ZERO_TO_ONE;
		Point = Vector3(RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE) * 2 - Vector3(1, 1, 1);
	} while (Vector3::DotProduct(Point, Point) >= 1.0f);
	return Point;
}

void Unit_Test_Vector()
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
}*/