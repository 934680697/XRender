#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Scence.h"
#include "Scence_Object.h"
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include "Render.h"
#define ANIT_ALIAS
#define SPACE " "
#define RAMDOM_ZERO_TO_ONE static_cast <float> (rand()) / static_cast <float> (RAND_MAX)
const int AA_Num = 150;
const int Width = 200;
const int Height = 100;
using std::fstream;

Vector3 Random_in_Unit_Sphere()
{
	Vector3 Point;
	do 
	{
		float x = RAMDOM_ZERO_TO_ONE;
		float y = RAMDOM_ZERO_TO_ONE;
		float z = RAMDOM_ZERO_TO_ONE;
		Point =  Vector3(RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE, RAMDOM_ZERO_TO_ONE) * 2 - Vector3(1,1,1);
	} while (Vector3::DotProduct(Point,Point)>= 1.0f);
	return Point;
}



void Image_Background(fstream & file, int Width, int Height , Vector3 Origin , Vector3 Lower_Left_Corner , Vector3 Horizontal , Vector3 Vertical)
{
	shared_ptr<Scence>scence = std::make_shared<Scence>();
	scence->Initialize();

	for (int j = Height - 1; j > 0; j--)
	{
		for (int i = 0; i < Width; i++)
		{
			Vector3 color;
			// Turn off AA;
#ifdef ANIT_ALIAS
			for (int z = 0; z < AA_Num; z++)
			{
				float random = RAMDOM_ZERO_TO_ONE;
				// getting the pixel position 
				float u = (float(i) + random) / float(Width);
				float v = (float(j) + random) / float(Height);
				// Because of the origin point is (0,0,0), so Lower_Left_Corner + Horizontal *u +  Vertical * v is the direction.
				Ray ray(Origin, Lower_Left_Corner + Horizontal * u + Vertical * v);
			//	color += Make_Color(ray, scence);

			}
			color /= AA_Num;
#else
			float u = float(i) / float(Width);
			float v = float(j) / float(Height);
			// Because of the origin point is (0,0,0), so Lower_Left_Corner + Horizontal *u +  Vertical * v is the direction.
			Ray ray(Origin, Lower_Left_Corner + Horizontal * u + Vertical * v);
			color += Make_Color(ray, scence);
#endif
			color = Vector3(color.R(),color.G(), color.B());
			float ir = int(255.99 * color.R());
			float ig = int(255.99 * color.G());
			float ib = int(255.99 * color.B());
			
			file << ir << SPACE << ig << SPACE << ib << "\n";

		}
	}
}


void Unit_Test_Vector()
{
	std::string Value = "Value";
	std::string Normalize = "Normalize";

	auto Display_Vector = [](Vector3 vec ,std::string des = "Value" ) {std::cout <<"The " << des << " of vector is x = " << vec.X() << " y = " << vec.Y() << " z = " << vec.Z() << std::endl; };
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
int main()
{
	/*fstream File;
	if (!Initialize_File(File, Width, Height))
	{
		std::cout << "file opened fail";
		system("pause");
		return 0;
	}
	Vector3 Camera_Position;
	Vector3  Lower_Left_Corner(-2, -1, -1);
	Vector3 Vertical(0, 2, 0);
	Vector3 Horizontal(4, 0, 0);
	Image_Background(File, Width, Height, Camera_Position, Lower_Left_Corner, Horizontal, Vertical);
	File.close();
	//Unit_Test_Vector();
	//system("pause");*/
	Render * render = new Render();
	render->Initialize();
	render->Start();
	return 0;
}