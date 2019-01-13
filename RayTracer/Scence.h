#pragma once
#include<vector>
#include<memory>
struct Hit_Data;
class Camera;
class Ray;
class Primitive;
class Light;
class Vector3;
using std::vector;
using std::shared_ptr;
class Scence
{
public:
	Scence();

	~Scence();

	bool Initialize();

	Vector3 Render(Ray ray);

private:


	void Initialize_Objects();

	void Initialize_Lights();

	vector<shared_ptr<Primitive>>scence_objects;

	vector<shared_ptr<Light>>      scence_lights;
};

