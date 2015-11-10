#include <iostream>
#include "Parser_OBJ.h"

int main ( int, char*[])
{
    id::Parser_OBJ parser;

    parser.setPath("chara.obj");

    parser.openFile();

    parser.loadObject();

    parser.closeFile();

    return EXIT_SUCCESS;
}
