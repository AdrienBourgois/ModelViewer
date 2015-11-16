#include "Parseur.h"

namespace id
{
	Parseur::Parseur()
	{
	}

	Parseur::~Parseur()
	{
	}

	std::string Parseur::doubleSlash(std::string s)
	{
                std::string s1 = "";
                for(unsigned int i = 0 ; i < s.size(); i++)
                {
                        if(i < s.size()-1 && s[i] == '/' && s[i+1] == '/')
                        {
                                s1 += "/1/";
                                i++;
                        }
                        else
                        s1 += s[i];
                }
                return s1;
        }

	std::string Parseur::remplacerSlash(std::string s)
	{
		std::string ret = "";
                for(unsigned int i = 0 ; i < s.size();i++)
                {
                        if(s[i] == '/')
                                ret += ' ';
                        else
                                ret += s[i];
                }
                return ret;
        }

	std::string Parseur::get_directory(std::string s)
	{
		std::string s1 = "", s2 = "";
                for ( unsigned int i = 0; i < s.size() ; ++i)
                {
                        if (s[i] == '/' || s[i] == '\\')
                        {
                                s1 += s2 + "/";
                                s2 = "";
                        }
                        else
                                s2 += s[i];
                }

                return s1;
        }

	std::vector<std::string> Parseur::splitSpace(std::string s)
        {
                std::vector<std::string> ret;
                std::string s1 = "";
                for(unsigned int i = 0; i < s.size(); i++)
                {
                        if(s[i] == ' ' || i == s.size()-1)
                        {
                                if(i == s.size()-1)
                                        s1 += s[i];

                                ret.push_back(s1);
                                s1 = "";
                        }
                        else
                                s1 += s[i];
                }
                return ret;
        }

	float* Parseur::vector2float(std::vector<float>& tableau)
        {
                float* t = NULL;
                t = (float*)malloc(tableau.size()* sizeof(float));
                if (t == NULL || tableau.empty())
                {
                        float *t1 = (float*)malloc(sizeof(float)*3);
                        for(int i=0;i<3;i++)
                              t1[i]=0.;
                        return t1;
                }

                for(unsigned int i=0;i<tableau.size();i++)
                        t[i]=tableau[i];

                return t;
        }
}
