#include "Parser_OBJ.h"

namespace id
{

void Parser_OBJ::openFile()
{
    stream.open(obj_path, std::fstream::in | std::fstream::binary);

    if(!stream.is_open())
        std::cout << "Error when open file " << obj_path << " !" << std::endl;
    else
        std::cout << "File open : " << obj_path << " !" << std::endl;
}

void Parser_OBJ::closeFile()
{
    stream.close();
}

void Parser_OBJ::loadObject()
{
    std::string cur_line;

    std::cout << "Start read file !" << std::endl;

    while(!stream.eof())
    {
        std::getline(stream, cur_line);
        if (stream.eof() || !stream.good())
            break;
        //std::cout << cur_line << std::endl;

        else if(cur_line[0] == 'v')
        {
            if(cur_line[1] == ' ')
                parseVertex(cur_line);
            else if(cur_line[1] == 't')
                parseTex(cur_line);
        }
        else if(cur_line[0] == 'f')
            parseFace(cur_line);
    }

    std::cout << "End read file !" << std::endl;
}

void Parser_OBJ::parseVertex(std::string line)
{
    char* char_line = nullptr;
    char* parsed = nullptr;

    char_line = strtochar(line, 2);
    parsed = strtok(char_line, " ");
    vertex.vertex_point1.push_back(strtof(parsed, nullptr));

    parsed = strtok(nullptr, " ");
    vertex.vertex_point2.push_back(strtof(parsed, nullptr));

    parsed = strtok(nullptr, " ");
    vertex.vertex_point3.push_back(strtof(parsed, nullptr));
}

void Parser_OBJ::parseTex(std::string line)
{
    char* char_line = nullptr;
    char* parsed = nullptr;

    char_line = strtochar(line, 3);
    parsed = strtok(char_line, " ");
    tex.tex_point1.push_back(strtof(parsed, nullptr));

    parsed = strtok(nullptr, " ");
    tex.tex_point2.push_back(strtof(parsed, nullptr));
}

void Parser_OBJ::parseNormal(std::string line)
{
    char* char_line = nullptr;
    char* parsed = nullptr;

    char_line = strtochar(line, 2);
    parsed = strtok(char_line, " ");
    normal.normal_point1.push_back(strtof(parsed, nullptr));

    parsed = strtok(nullptr, " ");
    normal.normal_point2.push_back(strtof(parsed, nullptr));

    parsed = strtok(nullptr, " ");
    normal.normal_point3.push_back(strtof(parsed, nullptr));
}

void Parser_OBJ::parseFace(std::string line)
{
    char* char_line = nullptr;
    char* parsed = nullptr;

    char_line = strtochar(line, 2);

    char* strPoint1 = strtok(char_line, " ");
    char* strPoint2 = strtok(NULL, " ");
    char* strPoint3 = strtok(NULL, " ");

    (void)strPoint3;

    parsed = strtok(strPoint1, "/");
    face.vertex1.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.tex1.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.normal1.push_back(strtof(parsed, nullptr));

    parsed = strtok(strPoint2, "/");
    face.vertex2.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.tex2.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.normal2.push_back(strtof(parsed, nullptr));

    parsed = strtok(strPoint3, "/");
    face.vertex3.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.tex3.push_back(strtof(parsed, nullptr));
    parsed = strtok(nullptr, "/");
    face.normal3.push_back(strtof(parsed, nullptr));

    displayData();
}

char* Parser_OBJ::strtochar(std::string string, int start)
{
    char* array = new char[string.size() + 3 - start]();

    for (unsigned int i = 0; i <= string.size(); ++i)
    {
        array[i] = string[i + start];
    }

    return array;
}

void Parser_OBJ::displayData()
{
    for(unsigned int i = 0; i < vertex.vertex_point1.size(); ++i)
        std::cout << vertex.vertex_point1[i] << " / " << vertex.vertex_point2[i] << " / " << vertex.vertex_point3[i] << std::endl;
}

} //namespace id
