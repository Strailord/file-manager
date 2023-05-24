#include "jsonhandler.h"

void JsonHandler::write_to_file()
{

}

void JsonHandler::read_from_file()
{

}

void JsonHandler::add(std::string ext, std::string path)
{
	root["configs"].append(Tile(ext, path));
}

int JsonHandler::remove(std::string ext)
{
	if(tiles.empty())
		return 0;
	int index = contains(ext);
	if(index < 0)
		return -1;
	tiles.erase(tiles.begin() + index);
}

std::vector<Tile> JsonHandler::get_configs()
{
	return tiles;
}

int JsonHandler::contains(std::string ext)
{
	int size = tiles.size();
	for(int i = 0; i < size; ++i)
	{
		if(tiles[i].ext == ext)
			return i;
	}
	return -1;
}
