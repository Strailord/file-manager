#ifndef _JSON_HANDLER_H_
#define _JSON_HANDLER_H_
#include "json/json.h"
#include <string>
#include <vector>

struct Tile
{
	Tile(std::string ext_t, std::string path_t):ext(""), path("")
	{
		ext = ext_t;
		path = path_t;
	}
	std::string ext;
	std::string path;
};

class JsonHandler
{
private:
	Json::Value root;
	int contains(std::string ext);
public:
	void write_to_file();
	void read_from_file();
	void add(std::string ext, std::string path);
	int remove(std::string ext);
	void print_show();
	Json::Value get_configs();
};

#endif
