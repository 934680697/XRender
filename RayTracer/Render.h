#pragma once
#include <memory>
class Scence;
class Camera;
class Render
{
public:

	Render();

	bool Initialize();

	void Start();

	~Render();

private:
	/* Uncopyable*/
	Render(const Render & render)	   = delete;
	Render(const Render && render)  = delete;
	Render& operator=(const Render & render) = delete;
	Render& operator=(const Render && render) = delete;

	std::shared_ptr<Scence>scence;

	std::shared_ptr<Camera>camera;

	int reflection_depth;

	int sample_ray_amount;

	int current_x_position;

	int current_y_position;

};

