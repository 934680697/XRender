#pragma once
#include<vector>
#include<memory>
struct Hit_Data;
class Camera;
class Ray;
class Primitive;
class Light;
using std::vector;
using std::shared_ptr;
class Scence
{
public:
	Scence();

	~Scence();

	void Initialize();

	bool Render(Ray ray, Hit_Data & hitdata);

private:

	void Initialize_Camera();

	void Initialize_Objects();

	void Initialize_Lights();

	shared_ptr<Camera>				  Scence_Camera;

	vector<shared_ptr<Primitive>>Scence_Objects;

	vector<shared_ptr<Light>>      Scence_Lights;
};

