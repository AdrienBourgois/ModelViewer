#include "Parser_JSON.h"
#include <SDL.h>
#include <map>
#include <fstream>

namespace id
{

    void Parser_JSON::openFile(std::string const& path)
    {
        stream.open(path, std::fstream::in | std::fstream::binary | std::fstream::out);

        if (!stream.is_open())
        {
            SDL_LogInfo(SDL_LOG_CATEGORY_ERROR, "Error when open file");
        }
    }

    void Parser_JSON::closeFile()
    {
        stream.close();
    }

    Material Parser_JSON::loadMaterial(std::string const& path)
    {
        Parser_JSON* parser= new Parser_JSON();
        parser->openFile(path);
        
        if(parser->stream.is_open())
        {
            Material material = parser->readMaterial();
            parser->closeFile();
            delete parser; 
            return material;
        }
        delete parser;
        Material material;
        return material;
    }

    void Parser_JSON::saveMaterial(Material const& material)
    {
        Parser_JSON* parser = new Parser_JSON();
        parser->openFile(material.getName());
        if(!parser->stream.is_open())
            return;
        parser->writteMaterial(material);
        parser->closeFile();
        delete parser;
    }

    Material Parser_JSON::readMaterial()
    {
        std::string current_line;
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"Start reading material");
        std::map <std::string, std::string> data;
        while (!this->stream.eof() || !this->stream.good())
        {
            std::getline(this->stream, current_line);

            if (stream.eof() || !stream.good())
                break;
            current_line.erase(' ').erase('\t').erase('\n');
            if ( (current_line[0] != '{') || current_line[0] != '}' )
            {
                data[this->readName(current_line)] = this->readValue(current_line);
            }
        }
        Material material(std::stof(data["red"]), std::stof(data["green"]), std::stof(data["blue"]), data["name"]);
        return material;
    }

    std::string Parser_JSON::readName(std::string const& line)
    {

        std::string name;
        unsigned int i = 0;
        while (line[i] != ':')
        {
            name.push_back(line[i]);
            ++i;
        }
        if(line[i+1] != '{')  
            return name;
        else
            return NULL;
    }
    
    std::string Parser_JSON::readValue(std::string const& line)
    {
        std::string value;
        unsigned int i = 0;
        while (line[i] != ':')
            ++i;
        if(line[i] == '{')
            return NULL;
        else
            ++i;
            for (; i < line.size()-2; ++i)
            {
                value.push_back(line[i]);
            }
        return value;
    }

    void  Parser_JSON::writteMaterial(Material const& material)
    {
        this->stream << "{" << std::endl;
        this->stream << "\t name:\"" << material.getName() <<"\"," << std::endl;
        this->stream << "color:{" << std::endl;
        this->stream << "\t \t red:\"" << material.getRed() <<"\"," << std::endl;
        this->stream << "\t \t green:\"" << material.getGreen() <<"\"," << std::endl;
        this->stream << "\t \t blue:\"" << material.getBlue() <<"\"" << std::endl;
        this->stream << "\t}" <<std::endl;
        this->stream << "}"<<std::endl;
    }

    

    
    

}//id
