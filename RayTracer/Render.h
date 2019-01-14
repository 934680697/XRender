#pragma once
#include <memory>
using std::shared_ptr;
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

	shared_ptr<Scence>scence;

	shared_ptr<Camera>camera;

	int sample_ray_amount;

	int current_x_position;

	int current_y_position;

};

