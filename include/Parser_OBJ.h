#ifndef __PARSER_OBJ_INCLUDE__
#define __PARSER_OBJ_INCLUDE__

#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <iostream>
#include <string>

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

    class Parser_OBJ
    {
    public:
        Parser_OBJ() = default;
        Parser_OBJ(std::string path) {obj_path = path;};
        ~Parser_OBJ() = default;

        void openFile();
        void closeFile();
        void loadObject();

        std::vector<std::string> explodeLine(std::string);
        std::string slashToSpace(std::string);

        void parseVertex(std::string);
        void parseTex(std::string);
        void parseNormal(std::string line);
        void parseFace(std::string);

        void displayData();

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
