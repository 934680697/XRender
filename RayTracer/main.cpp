#include "Render.h"

int main()
{
	Render * render = new Render();
	render->Initialize();
	render->Start();
	delete render;
	return 0;
}
