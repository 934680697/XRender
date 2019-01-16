#pragma once
#include <string>
struct Render_Config
{
	int			 image_width		= 200;
	int			 image_height		= 100;
	int			 sample_amount	= 100;
	std::string  image_directory = " ";
	std::string  image_name	    = "";
};
class Configfile_Parser
{
public:
	Configfile_Parser();
	~Configfile_Parser();

	static bool Read_Config_File(std::string directory,Render_Config & render_config);
};

