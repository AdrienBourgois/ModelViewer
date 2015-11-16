#ifndef __PARSEUR_H_INCLUDED__
#define __PARSEUR_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>

namespace id
{
	class Parseur
	{
	  public:
		Parseur();
		~Parseur();

		std::string doubleSlash(std::string);
                std::string remplacerSlash(std::string);
                std::string get_directory(std::string);
                std::vector<std::string> splitSpace(std::string);

		float* vector2float(std::vector<float>& tableau);
	};
}

#endif
