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
        std::cout << cur_line << std::endl;

        if(cur_line[0] == 'v')
            parseVertex(cur_line);
        else if(cur_line[0] == 'f')
            parseFace(cur_line);
    }

    std::cout << "End read file !" << std::endl;
}

void Parser_OBJ::parseVertex(std::string line)
{
    float x;
    float y;
    float z;

    char * char_line = nullptr;

    std::cout << char_line << std::endl;

    char_line = strtochar(line, 2);
    strtok(char_line, " ");
    x = strtof(char_line, nullptr);
    char_line = strtochar(line, 2);
    strtok(char_line, " ");
    y = strtof(char_line, nullptr);
    char_line = strtochar(line, 2);
    strtok(char_line, " ");
    z = strtof(char_line, nullptr);

    std::cout << "    --> " << x << std::endl;
    std::cout << "    --> " << y << std::endl;
    std::cout << "    --> " << z << std::endl;

    delete char_line;
}

void Parser_OBJ::parseFace(std::string line)
{
    (void)line;

}

char* Parser_OBJ::strtochar(std::string string, int start)
{
    char* array = new char[string.size() + 1 - start]();

    for (unsigned int i = 0; i <= string.size(); ++i)
    {
        array[i] = string[i + start];
    }

    return array;
}

} //namespace id
