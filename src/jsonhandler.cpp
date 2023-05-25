#include "jsonhandler.h"
#include <iostream>
#include <string>
#include <vector>

void JsonHandler::write_to_file()
{

}

void JsonHandler::read_from_file()
{

}

// ADD ext TO root WITH path
void JsonHandler::add(std::string ext, std::string path)
{
	// ADD MEMBER
	root[ext] = path;
}

// REMOVE ext FROM root
int JsonHandler::remove(std::string ext = "")
{
	// CHECK IF root IS EMPTY
	if(root.empty())
		return -1;
	
	// CHECK IF root HAS MEMEBER ext
	if(root.isMember(ext))
	{
		// root HAS MEMBER ext AND DELETEDS IT
		root.removeMember(ext);
		std::cout << "DELETED " << ext << std::endl;
		return 1;
	}
	else
	{
		// root HAS NO MEMBER ext AND DID NOTHING
		std::cout << "ERROR! NOT FOUND!" << std::endl;
		return -1;
	}

}

void JsonHandler::print_show()
{
	// PRINT EXISTING CONFIGS
	std::vector<std::string> members = root.getMemberNames();
	for(int i = 0; i < members.size(); ++i)
		std::cout << members[i] << " : " << root[members[i]] << std::endl;
}

Json::Value JsonHandler::get_configs()
{
	return root;
}
