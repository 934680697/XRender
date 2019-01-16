#include "Render.h"
#include "Configfile_Parser.h"
int main()
{
	std::string config_address = "G:/Project/C++/RayTracer/Render_Config.txt";
	Render_Config render_config;
	if (Configfile_Parser::Read_Config_File(config_address, render_config))
	{
		Render * render = new Render();
		render->Initialize(render_config);
		render->Start();
		delete render;
	}
	return 0;
}
