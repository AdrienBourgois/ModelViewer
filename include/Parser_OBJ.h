#ifndef __PARSER_OBJ_INCLUDE__
#define __PARSER_OBJ_INCLUDE__

#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include <string>
#include <cstring>

namespace id
{
    struct Parser_OBJ
    {
    public:
        Parser_OBJ() = default;
        Parser_OBJ(std::string path) {obj_path = path;};
        ~Parser_OBJ() = default;

        void openFile();
        void closeFile();
        void loadObject();

        void parseVertex(std::string);
        void parseFace(std::string);

        char* strtochar(std::string, int = 0);

        //set
        void setPath(std::string path) {obj_path = path;}


    private:
        std::ifstream stream;

        std::string obj_path;

        std::vector<GLfloat> vertex_point1; 
        std::vector<GLfloat> vertex_point2; 
        std::vector<GLfloat> vertex_point3; 

        std::vector<GLfloat> tex_point1; 
        std::vector<GLfloat> tex_point2; 

        std::vector<GLfloat> normal_point1; 
        std::vector<GLfloat> normal_point2; 
        std::vector<GLfloat> normal_point3; 

    };

}

#endif
