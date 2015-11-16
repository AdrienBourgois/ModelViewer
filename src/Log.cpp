#include "Log.h"
#include <istream>
#include <ctime> 

namespace id
{
	Log::Log()
	{
	}

	Log::~Log()
	{
	}
	
	void Log::write_log(const char *msg, const char* filename_log = "LOG.txt")
	{
		std::ofstream ofs(filename_log,std::ofstream::app);

		if(ofs)
		{
    			time_t a;
			time(&a);
			ofs << ctime(&a) << ' ' << msg << std::endl;
  		}
		ofs.close();
	}
}
