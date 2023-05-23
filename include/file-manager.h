#ifndef _FILE_MANAGER_H_
#define _file_manager_H_
#include <string>

struct config_tile
{
    char* extension = nullptr;
    char* path = nullptr;
};

enum COMMANDS 
{
    ERROR = -2,
    QUIT = -1,
    ADD = 0,
    REMOVE = 1,
    SHOW = 2
};

void print_help();
void start_console_mode();
void read_config();
void write_config();
int get_command(const std::string str);

#endif