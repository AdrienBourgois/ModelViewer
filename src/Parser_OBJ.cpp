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
    openFile();

    std::string cur_line;

    std::cout << "Start read file !" << std::endl;

    while(!stream.eof() && stream.good())
    {
        std::getline(stream, cur_line);
        if (stream.eof() || !stream.good())
            break;

        else if(cur_line[0] == 'v')
        {
            if(cur_line[1] == ' ')
                parseVertex(cur_line);
            else if(cur_line[1] == 't')
                parseTex(cur_line);
            else if(cur_line[1] == 'n')
                parseNormal(cur_line);
        }
        else if(cur_line[0] == 'f')
            parseFace(cur_line);
    }

    std::cout << "File " << obj_path << " loaded !" << std::endl;

    closeFile();
}

void Parser_OBJ::parseVertex(std::string line)
{
    std::string sub_line = line.substr(2);

    std::vector<std::string> elements = explodeLine(sub_line);

    vertex.vertex_point1.push_back(stod(elements[0]));
    vertex.vertex_point2.push_back(stod(elements[1]));
    vertex.vertex_point3.push_back(stod(elements[2]));
}

void Parser_OBJ::parseTex(std::string line)
{
    std::string sub_line = line.substr(3);

    std::vector<std::string> elements = explodeLine(sub_line);

    tex.tex_point1.push_back(stod(elements[0]));
    tex.tex_point2.push_back(stod(elements[1]));
}

void Parser_OBJ::parseNormal(std::string line)
{
    std::string sub_line = line.substr(3);

    std::vector<std::string> elements = explodeLine(sub_line);

    normal.normal_point1.push_back(stod(elements[0]));
    normal.normal_point2.push_back(stod(elements[1]));
    normal.normal_point3.push_back(stod(elements[2]));
}

void Parser_OBJ::parseFace(std::string line)
{
    line = slashToSpace(line);

    std::string sub_line = line.substr(2);

    std::vector<std::string> elements = explodeLine(sub_line);

    face.vertex1.push_back(stod(elements[0]));
    face.tex1.push_back(stod(elements[1]));
    face.normal1.push_back(stod(elements[2]));

    face.vertex2.push_back(stod(elements[3]));
    face.tex2.push_back(stod(elements[4]));
    face.normal2.push_back(stod(elements[5]));

    face.vertex3.push_back(stod(elements[6]));
    face.tex3.push_back(stod(elements[7]));
    face.normal3.push_back(stod(elements[8]));
}

std::vector<std::string> Parser_OBJ::explodeLine(std::string line)
{
    std::vector<std::string> elements;

    std::string cur_element;

    for(unsigned int i = 0; i < line.size(); ++i)
    {
        if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.' || line[i] == '-')
            cur_element += line[i];

        else if (line[i] == ' ')
        {
            elements.push_back(cur_element);
            cur_element.erase();
        }
    }
    
    elements.push_back(cur_element);

    return elements;
}

std::string Parser_OBJ::slashToSpace(std::string line)
{
    for (unsigned int i = 0; i < line.size(); ++i)
        if (line[i] == '/')
            line[i] = ' ';

    return line;
}

void Parser_OBJ::displayData()
{
    for(unsigned int i = 0; i < vertex.vertex_point1.size(); ++i)
        std::cout << "v : " << vertex.vertex_point1[i] << " / " << vertex.vertex_point2[i] << " / " << vertex.vertex_point3[i] << std::endl;
    for(unsigned int i = 0; i < tex.tex_point1.size(); ++i)
        std::cout << "vt : " << tex.tex_point1[i] << " / " << tex.tex_point2[i] << std::endl;
    for(unsigned int i = 0; i < normal.normal_point1.size(); ++i)
        std::cout << "vn : " << normal.normal_point1[i] << " / " << normal.normal_point2[i] << " / " << normal.normal_point3[i] << std::endl;
    for(unsigned int i = 0; i < face.vertex1.size(); ++i)
    {
        std::cout << "f1 : " << face.vertex1[i] << " / " << face.tex1[i] << " / " << face.normal1[i] << std::endl;
        std::cout << "f2 : " << face.vertex2[i] << " / " << face.tex2[i] << " / " << face.normal2[i] << std::endl;
        std::cout << "f3 : " << face.vertex3[i] << " / " << face.tex3[i] << " / " << face.normal3[i] << std::endl;
    }
}

} //namespace id
