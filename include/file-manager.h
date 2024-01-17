#ifndef _FILE_MANAGER_H_
#define _file_manager_H_
#include <string>
#include <map>

struct config_tile
{
    char* extension = nullptr;
    char* path = nullptr;
};

std::map<const std::string, int> INPUT = {
    {"QUIT", 0},
    {"ADD", 1},
    {"SHOW", 2},
    {"HELP", 3},
    {"REMOVE", 4},
    {"LOAD", 5},
    {"SAVE", 6},
    {"CLEAN", 7},
    {"CLEAR", 8}
};

void print_help();
void start_console_mode();
void read_config();
void write_config();
int get_command(const std::string str);

#endif