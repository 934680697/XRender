#include "Configfile_Parser.h"
#include <fstream>
#include <iostream>

using std::string;
using std::fstream;

Configfile_Parser::Configfile_Parser()
{
}


Configfile_Parser::~Configfile_Parser()
{
}

bool Configfile_Parser::Read_Config_File(std::string directory, Render_Config & render_config)
{
	fstream config_file(directory);
	if (!config_file.is_open())
	{
		return false;
	}
	else
	{
		string config_line;
		while (config_file >> config_line)
		{
			int sub_index  = config_line.find('=');
			int sub_lengh  = config_line.length() - sub_index;
			string key		   = config_line.substr(0, sub_index);
			string value     = config_line.substr(sub_index+1, sub_lengh);
			if (key == "image_width")
			{
				render_config.image_width = strtof(value.c_str(), 0);
			}
			else if (key == "image_height")
			{
				render_config.image_height = strtof(value.c_str(), 0);
			}
			else if (key == "sample_amount")
			{
				render_config.sample_amount = strtof(value.c_str(), 0);
			}
			else if (key == "image_directory")
			{
				render_config.image_directory = value;
			}
			else if (key == "image_name")
			{
				render_config.image_name = value;
			}
			else
			{
				std::cout << "can not found key" << key <<std::endl;
				return false;
			}
		}
	}
	return true;

}
