#pragma once
#include<vector>
#include<memory>
struct Hit_Data;
struct Render_Config;
class Camera;
class Ray;
class Primitive;
class Light;
class Vector3;
class Scence
{
public:
	Scence();

	~Scence();

	bool Initialize(Render_Config render_config);

	Vector3 Render(Ray ray,int reflection_depth);

private:

	Scence(const Scence & scence) = delete;
	Scence(const Scence && scence) = delete;
	void operator=(const Scence & scence) = delete;
	void operator=(const Scence && scence) = delete;

	void Initialize_Objects();

	void Initialize_Lights();

	std::vector<std::shared_ptr<Primitive>>scence_objects;

	std::vector<std::shared_ptr<Light>>      scence_lights;
};

