#include <iostream>
#include "Parser_OBJ.h"

int main ( int, char*[])
{
    id::Parser_OBJ parser("chara.obj");

    parser.loadObject();

    return EXIT_SUCCESS;
}
