#include "jsonhandler.h"

void JsonHandler::write_to_file()
{

}

void JsonHandler::read_from_file()
{

}

void JsonHandler::add(std::string ext, std::string path)
{
	// ADD Json::Value here
}

int JsonHandler::remove(std::string ext)
{
	/*
	if(tiles.empty())
		return 0;
	int index = contains(ext);
	if(index < 0)
		return -1;
	tiles.erase(tiles.begin() + index);
	*/
	return 1;
}

Json::Value JsonHandler::get_configs()
{
	return root;
}
