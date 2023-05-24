#include "json.h"
#include <iostream>

struct Tile
{
	Tile(std::string ext_t, std::string path_t) : ext(""), path("")
	{
		ext = ext_t;
		path = path_t;
	}

	std::string ext;
	std::string path;
};

Json::Value to_tile(Tile &tile)
{
	Json::Value res;
	res[tile.ext] = tile.path;
	return res;
}

int main()
{
	Json::Value root = Json::objectValue;
	Tile t1 = Tile("test1", "test1_path");
	Tile t2 = Tile("test2", "test2_path");
	Tile t3 = Tile("test3", "test3_path");
	root[0] = to_tile(t1);
	root[1] = to_tile(t2);
	root[2] = to_tile(t3);
	std::cout << root.toStyledString() << std::endl;

}
