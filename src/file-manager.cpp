#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include "file-manager.h"
#include "jsonhandler.h"

// CONVERT COMMAND INTO INTEGER
int get_command(const std::string str)
{

    switch(INPUT[str]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    default:
        return -1;
    }

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
        char* token = std::strtok(line.data(), " ");
        while(token != NULL)
        {
            command.push_back(token);
            token = std::strtok(NULL, " ");
        }

        switch (get_command(command[0]))
        {
        case 8:
            system("cls || clear");
            std::cout << "\nCONSOLE CONFIG:\n" << std::endl;
            break;
        case 7:
            handler.clean();
            break;
        case 5:
            // LOAD CONFIG 
            handler.load_config();
            break;
        case 6:
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
        case 4:
            // REMOVE
            if(handler.remove(command[1]) < 0)
            {
                std::cout << "Configuration could not be found" << std::endl;
            }
            break;
        case 1:
            // ADD
            if(command[2] == "TO")
                handler.add(command[1], command[3]);
            else
            std::cout << "Invalid command!" << std::endl;
            break;            
        case 0:
            // QUIT
            run = 0;
            handler.save_config();
            break;
        case -1:
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
