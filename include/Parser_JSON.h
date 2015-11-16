#ifndef _PARSER_JSON_H
#define _PARSEUR_JSON_H

#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include "Material.h"


namespace id{

    class Parser_JSON
    {

        public:
            static Material          loadMaterial(std::string const& path);
            static void              saveMaterial(Material const& material);
            void                     openFile(std::string const& path);
            void                     closeFile();
            Material                 readMaterial();
            std::string              readName(std::string const& line);
            std::string              readValue(std::string const& line);
            void                     writteMaterial(Material const& material);
        private:
            Parser_JSON()=default;
            ~Parser_JSON()=default;
            std::fstream stream;

    };

}//id

#endif
