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

int JsonHandler::remove(std::string ext = "")
{
	return -1;
}

Json::Value JsonHandler::get_configs()
{
	return root;
}
