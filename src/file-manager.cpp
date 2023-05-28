#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <boost/tokenizer.hpp>  // BOOST-LIBRARY
#include "file-manager.h"
#include "jsonhandler.h"

// CONVERT COMMAND INTO INTEGER
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
    else if(str == "LOAD")
        return COMMANDS::LOAD;
    else if(str == "SAVE")
        return COMMANDS::SAVE;
    else if(str == "CLEAN")
        return COMMANDS::CLEAN;
    else if(str == "CLEAR")
        return COMMANDS::CLEAR;
    else
        return COMMANDS::ERROR;
}

// PRINT HELP MENU
void print_help()
{
    std::cout << "\nFile-Manager v0.1" << std::endl;
    std::cout << "\nfile-manager <options>" << std::endl;
    std::cout << "\nNote:" << std::endl;
    std::cout << "\tIf no option is given, the current directory will be cleaned" << std::endl;
    std::cout << "\nOptions:\n\t-h : Print help menu" << std::endl;
    std::cout << "\t-c : Start console-configuration mode" << std::endl;
    std::cout << "\nConsole Configuration Commands:" << std::endl;
    std::cout << "\tCLEAN: The currend directory gets cleaned" << std::endl;
    std::cout << "\tCLEAR: Clear the current screen" << std::endl;
    std::cout << "\tADD <ext> TO <dest_path> : Add the configuration for <ext> to the path <dest_path>. <ext> without the . in front of it" << std::endl;
    std::cout << "\tREMOVE <ext> : Remove the configuration for <ext>. <ext> without the . in front of it" << std::endl;
    std::cout << "\tSHOW : Prints out the current configurations" << std::endl;
    std::cout << "\tLOAD <path>: Loads the configuration from the config file at <path>" << std::endl;
    std::cout << "\tSAVE <path>: Saves the current configuration to path, if no path is given, the current directory is used" << std::endl; 
    std::cout << "\tCONFIG <path>: Sets the path to the directory of the config file" << std::endl;
    std::cout << "\tHELP : Prints out the helptext" << std::endl;
    std::cout << "\tQUIT : Quit the configuration and save the changes\n" << std::endl;
}

void start_console_mode(JsonHandler &handler)
{
    std::cout << "\nCONSOLE CONFIG:\n" << std::endl;
    int run = 1;

    while(run)
    {
        // GET COMMAND
        std::string line = "";
        std::vector<std::string> command;
        std::cout << ">>> ";
        std::getline(std::cin, line);
       
	// SPLIT COMMAND INTO WORDS
        boost::tokenizer<> tok(line);
        for (boost::tokenizer<>::iterator iter = tok.begin(); iter != tok.end(); ++iter)
            command.push_back(*iter);
        
        switch (get_command(command[0]))
        {
        case 7:
            system("cls || clear");
            std::cout << "\nCONSOLE CONFIG:\n" << std::endl;
            break;
        case 6:
            handler.clean();
            break;
        case 5:
            // LOAD CONFIG 
            handler.load_config();
            break;
        case 4:
            // SAVE CONFIG
            handler.save_config();
            break;
        case 3:
            // HELP
            std::cout << "\tCLEAN: The currend directory gets cleaned" << std::endl;
            std::cout << "\tCLEAR: Clear the current screen" << std::endl;
            std::cout << "\tADD <ext> TO <dest_path> : Add the configuration for <ext> to the path <dest_path>. <ext> without the . in front of it" << std::endl;
            std::cout << "\tREMOVE <ext> : Remove the configuration for <ext>. <ext> without the . in front of it" << std::endl;
            std::cout << "\tSHOW : Prints out the current configurations" << std::endl;
            std::cout << "\tLOAD <path>: Loads the configuration from the config file at <path>" << std::endl;
            std::cout << "\tSAVE <path>: Saves the current configuration to path, if no path is given, the current directory is used" << std::endl; 
            std::cout << "\tCONFIG <path>: Sets the path to the directory of the config file" << std::endl;
            std::cout << "\tHELP : Prints out the helptext" << std::endl;
            std::cout << "\tQUIT : Quit the configuration and save the changes" << std::endl;
            break;
        case 2:
            // SHOW
	        handler.print_show();
            break;
        case 1:
            // REMOVE
            if(handler.remove(command[1]) < 0)
            {
                std::cout << "Configuration could not be found" << std::endl;
            }
            break;
        case 0:
            // ADD
            if(command[2] == "TO")
                handler.add(command[1], command[3]);
            else
            std::cout << "Invalid command!" << std::endl;
            break;            
        case -1:
            // QUIT
            run = 0;
            handler.save_config();
            break;
        case -2:
            // FALSE INPUT
            std::cout << "No valid command!" << std::endl;
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
    JsonHandler handler;
    handler.load_config();
    if(argc == 1)
    {
	    handler.clean();
	    return 0;
    }

    int c;
    while((c = getopt(argc, argv, ":hc")) != -1)
    {
        switch (c)
        {
        case 'h':
	    // PRINT THE HELP PAGE
            print_help();
            return 0;
        case 'c':
	    // START CONSOLE CONFIGURATION MODE
            start_console_mode(handler);
            return 0;
        }
    }

}
