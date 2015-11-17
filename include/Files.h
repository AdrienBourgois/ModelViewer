#ifndef __FILES_INCLUDE__
#define __FILES_INCLUDE__

#include <iostream>
#include <vector>
#include <dirent.h>
#include <sys/types.h>

namespace id
{

class FileManager
{
    public:
        FileManager();
        ~FileManager() = default;

        std::string getPath();
        std::vector<std::string> getListFolder() {return this->listFolder;}
        std::string getListFolder(int n) {return this->listFolder[n];}
        std::vector<struct dirent*> getList();

        void showFolder() {std::cout << "Actual path : " << getPath() << std::endl;}
        void setPath(std::string);

        void parentFolder() {this->listFolder.erase(listFolder.end());}
        void displayFolder();

        std::vector<std::string> explodePath(std::string);
        std::string slashToSpace(std::string);

    private:
        std::vector<std::string> listFolder;
        std::vector<struct dirent*> list;
};

}// namespace id

#endif
