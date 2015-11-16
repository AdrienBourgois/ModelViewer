#include <iostream>
#include "System.h"

int main ( int, char*[])
{
	id::System* sys = new id::System();
	sys->init();
	sys->drawAll();
   	delete sys;
	
	return EXIT_SUCCESS;
}
