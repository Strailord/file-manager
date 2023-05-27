#ifndef _JSON_HANDLER_H_
#define _JSON_HANDLER_H_
#include <string>
#include <vector>
#include <experimental/filesystem>
#include "json/json.h"

class JsonHandler
{
private:
	Json::Value root;
	bool contains(std::string ext, std::vector<std::string> &members);
	std::experimental::filesystem::path config_path = ".";
public:
	void clean();
	void save_config();
	void load_config();
	void set_config(std::experimental::filesystem::path);
	void add(std::string ext, std::string path);
	int remove(std::string ext);
	void print_show();
};

#endif
