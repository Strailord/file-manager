#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <boost/tokenizer.hpp>  // BOOST-LIBRARY
#include "file-manager.h"

int get_command(const std::string str)
{

    if(str == "QUIT")
        return COMMANDS::QUIT;
    else if(str == "ADD")
        return COMMANDS::ADD;
    else if(str == "SHOW")
        return COMMANDS::SHOW;
    else if(str == "HELP")
        return COMMANDS::HELP;
    else if(str == "REMOVE")
        return COMMANDS::REMOVE;
    else
        return COMMANDS::ERROR;
}

void print_help()
{
    std::cout << "\nFile-Manager v0.1" << std::endl;
    std::cout << "\nfile-manager <options>" << std::endl;
    std::cout << "Options:\n\t-h : Print help menu" << std::endl;
    std::cout << "\t-c : Start console-configuration mode" << std::endl;
    std::cout << "\t-m : Move the files according to their configuration, if no configuration exists for the file, the file will be skipped" << std::endl;
    std::cout << "\nConsole Configuration Commands:" << std::endl;
    std::cout << "\tADD <ext> TO <dest_path> : Add the configuration for <ext> to the path <dest_path>" << std::endl;
    std::cout << "\tREMOVE <ext> : Remove the configuration for <ext>" << std::endl;
    std::cout << "\tSHOW : Prints out the current configurations" << std::endl;
    std::cout << "\tHELP : Prints out the helptext" << std::endl;
    std::cout << "\tQUIT : Quit the configuration and save the changes\n" << std::endl;
}

void start_console_mode()
{
    std::cout << "\nCONSOLE CONFIG:\n" << std::endl;
    int run = 1;

    while(run)
    {
        
        std::string line = "";
        std::vector<std::string> command;
        std::cout << ">>> ";
        std::getline(std::cin, line);
        
        boost::tokenizer<> tok(line);
        for (boost::tokenizer<>::iterator iter = tok.begin(); iter != tok.end(); ++iter)
            command.push_back(*iter);
        
        switch (get_command(command[0]))
        {
        case 3:
            // HELP
            std::cout << "\tADD <ext> TO <dest_path> : Add the configuration for <ext> to the path <dest_path>" << std::endl;
            std::cout << "\tREMOVE <ext> : Remove the configuration for <ext>" << std::endl;
            std::cout << "\tSHOW : Prints out the current configurations" << std::endl;
            std::cout << "\tHELP : Prints out the helptext" << std::endl;
            std::cout << "\tQUIT : Quit the configuration and save the changes" << std::endl;
            break;
        case 2:
            // SHOW
            break;
        case 1:
            // REMOVE
            break;
        case 0:
            // ADD
            break;            
        case -1:
            // QUIT
            run = 0;
            break;
        case -2:
            // FALSE INPUT
            std::cout << "You dump piece of shit, insert a correct command !!" << std::endl;
            break;
        }    
        command.clear();
        line.clear();
    }
    return;
}

void read_config();
void write_config();

int main(int argc, char* argv[])
{
    int c;
    while((c = getopt(argc, argv, ":hcm")) != -1)
    {
        switch (c)
        {
        case 'h':
            print_help();
            return 0;
        case 'c':
            start_console_mode();
            return 0;
        case 'm':
            //std::cout<< (char)c << std::endl;
            break;
        }
    }

}