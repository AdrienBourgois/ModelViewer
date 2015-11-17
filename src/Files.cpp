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
    this->listFolder.erase(this->listFolder.begin());

    showFolder();
}

void FileManager::displayFolder()
{
    struct dirent **namelist;
    int count;
    int type = 0;
    (void)type;

    count = scandir(getPath().c_str(), &namelist, NULL, alphasort);
    if (count < 0)
    {
        std::cout << "Can't open " << getPath() << " folder !" << std::endl;
        perror("scandir");
    }

    std::cout << std::endl
              << "------------------------------- " << getPath() << " -------------------------------" << std::endl;


    for(int i = 0; i < count; ++i)
    {
        type = namelist[i]->d_type;
        if (type == 4)
            std::cout << '[' << namelist[i]->d_name << "] " << std::endl;
    }
    for(int i = 0; i < count; ++i)
    {
        type = namelist[i]->d_type;
        if (type == 8)
            std::cout << "  " << namelist[i]->d_name << std::endl;
    }

    std::cout << std::endl
              << "/------------------------------- " << getPath() << " -------------------------------/" << std::endl;
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
