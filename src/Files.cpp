#include "Files.h"

namespace id
{

FileManager::FileManager()
{
    setPath(realpath(".", nullptr));
}

std::string FileManager::getPath()
{
    std::string path = "";

    for (unsigned int i = 0; i < listFolder.size(); ++i)
    {
        path += listFolder[i];
        path += '/';
    }

    path.erase(path.size() - 1, 1);

    return path;
}

void FileManager::setPath(std::string path)
{
    path = slashToSpace(path);
    this->listFolder = explodePath(path);

    showFolder();
}

void FileManager::displayFolder()
{
    DIR* rep = opendir(getPath().c_str());
    struct dirent* file = nullptr;

    if (rep == nullptr)
    {
        std::cout << "Can't open " << getPath() << " folder !" << std::endl;
        return;
    }

    rewinddir(rep);

    std::cout << std::endl
              << "------------------------------- " << getPath() << " -------------------------------" << std::endl;


    while((file = readdir(rep)) != nullptr)
    {
        if(file->d_name[0] != '.')
            std::cout << '[' << file->d_name << "]" << std::endl;
    }

    std::cout << std::endl
              << "/------------------------------- " << getPath() << " -------------------------------/" << std::endl;


    closedir(rep);

}

std::vector<std::string> FileManager::explodePath(std::string path)
{
    std::vector<std::string> elements;

    std::string cur_element;

    for(unsigned int i = 0; i < path.size(); ++i)
    {
        if (path[i] == ' ')
        {
            elements.push_back(cur_element);
            cur_element.erase();
        }
        else
            cur_element += path[i];
    }
    
    elements.push_back(cur_element);

    return elements;
}

std::string FileManager::slashToSpace(std::string path)
{
    for (unsigned int i = 0; i < path.size(); ++i)
        if (path[i] == '/')
            path[i] = ' ';

    return path;
}

}// namespace id
