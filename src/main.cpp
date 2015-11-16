#include <iostream>
#include "System.h"

int main (int argc,char** argv)
{
    (void) argc;
    std::string path = argv[1];
	id::System* sys = new id::System(path);
	sys->init();
	sys->drawAll();
   	delete sys;
	
	return EXIT_SUCCESS;
}
