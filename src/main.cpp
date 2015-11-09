#include <iostream>
#include "Device.h"

int main ( int, char*[])
{
    auto device = new id::Device;
    device->create();

    return EXIT_SUCCESS;
}
