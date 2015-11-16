#ifndef __LOG_H_INCLUDED__
#define __LOG_H_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>

namespace id
{
	class Log
	{
	  public:
		Log();
		~Log();
		
		void write_log(const char*, const char*);
	};
}

#endif
