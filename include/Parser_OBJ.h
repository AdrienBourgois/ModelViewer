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
    struct Vertex
    {
        std::vector<GLfloat> vertex_point1; 
        std::vector<GLfloat> vertex_point2; 
        std::vector<GLfloat> vertex_point3; 
    };

    struct Tex
    {
        std::vector<GLfloat> tex_point1; 
        std::vector<GLfloat> tex_point2; 
    };

    struct Normal
    {
        std::vector<GLfloat> normal_point1; 
        std::vector<GLfloat> normal_point2; 
        std::vector<GLfloat> normal_point3; 
    };

    struct Face
    {
        std::vector<GLfloat> vertex1; 
        std::vector<GLfloat> vertex2; 
        std::vector<GLfloat> vertex3; 

        std::vector<GLfloat> tex1; 
        std::vector<GLfloat> tex2; 
        std::vector<GLfloat> tex3; 

        std::vector<GLfloat> normal1; 
        std::vector<GLfloat> normal2; 
        std::vector<GLfloat> normal3; 
    };

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
        void parseTex(std::string);
        void parseNormal(std::string line);
        void parseFace(std::string);

        void displayData();

        char* strtochar(std::string, int = 0);

        //set
        void setPath(std::string path) {obj_path = path;}


    private:
        std::ifstream stream;

        std::string obj_path;

        Vertex vertex;
        Tex tex;
        Normal normal;
        Face face;

        std::vector<GLfloat> normal_point1; 
        std::vector<GLfloat> normal_point2; 
        std::vector<GLfloat> normal_point3; 

    };
}

#endif
