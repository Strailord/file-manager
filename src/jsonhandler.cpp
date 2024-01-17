#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <filesystem>
#include "jsonhandler.h"

// CLEAN THE CURRENT DIRECTORY
void JsonHandler::clean()
{
	bool got_cleaned = false;
	JsonHandler::load_config();
	std::vector<std::string> members = root.getMemberNames();		
	for (auto const& dir_entry : std::filesystem::directory_iterator{"."}) 
    {
        std::string extension = dir_entry.path().extension();
		if(JsonHandler::contains(extension, members))
		{
			// CHECK IF SPECIFIED DIR EXISTS
			if(!std::filesystem::exists(root[extension].asString()))
				std::filesystem::create_directory(root[extension].asString());
			std::filesystem::copy(dir_entry.path(), root[extension].asString() / dir_entry.path());
			std::filesystem::remove(dir_entry.path());
			got_cleaned = true;
		}
	}
	if(got_cleaned)
		std::cout << "CLEANED CURRENT DIRECTORY" << std::endl;
}

// SAVE THE CONFIG TO A FILE
void JsonHandler::save_config()
{
	std::ofstream conf(config_path/"file_manager_config.conf");

	if(conf.is_open())
	{
		Json::StreamWriterBuilder builder;
		conf << Json::writeString(builder, root);
	}
	else
	{
		std::cout << "Could not save the configs" << std::endl;
	}

	conf.close();
}

// LOAD CONFIG FROM FILE
void JsonHandler::load_config()
{
	std::ifstream conf(config_path/"file_manager_config.conf");
	Json::CharReaderBuilder builder;
	Json::String error;
	if(!Json::parseFromStream(builder, conf, &root, &error))
	{
		std::cout << "Could not load Configfile" << std::endl;
	}
	conf.close();
}

// SET THE PATH TO A CONFIGFILE
void JsonHandler::set_config(std::filesystem::path path)
{
	config_path = path;
}

// ADD ext TO root WITH path
void JsonHandler::add(std::string ext, std::string path)
{
	// ADD MEMBER
	root["." + ext] = path;
}

// REMOVE ext FROM root
int JsonHandler::remove(std::string ext = "")
{
	// CHECK IF root IS EMPTY
	if(root.empty())
		return -1;
	
	// CHECK IF root HAS MEMEBER ext
	if(root.isMember("." + ext))
	{
		// root HAS MEMBER ext AND DELETEDS IT
		root.removeMember("." + ext);
		std::cout << "DELETED " << ext << std::endl;
		return 1;
	}
	else
	{
		// root HAS NO MEMBER ext AND DID NOTHING
		std::cout << "ERROR! NOT FOUND!" << std::endl;
		return -1;
	}

}

void JsonHandler::print_show()
{
	// PRINT EXISTING CONFIGS
	std::vector<std::string> members = root.getMemberNames();
	for(int i = 0; i < members.size(); ++i)
		std::cout << members[i] << " : " << root[members[i]] << std::endl;
}

bool JsonHandler::contains(std::string ext, std::vector<std::string> &members)
{
	if(std::find(members.begin(), members.end(), ext) != members.end())
		return true;
	return false;
}