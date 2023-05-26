#ifndef _JSON_HANDLER_H_
#define _JSON_HANDLER_H_
#include "json/json.h"
#include <string>
#include <vector>
#include <experimental/filesystem>

class JsonHandler
{
private:
	Json::Value root;
	int contains(std::string ext);
	std::experimental::filesystem::path config_path = ".";
public:
	void save_config();
	void load_config();
	void set_config(std::experimental::filesystem::path);
	void add(std::string ext, std::string path);
	int remove(std::string ext);
	void print_show();
	Json::Value get_configs();
};

#endif
