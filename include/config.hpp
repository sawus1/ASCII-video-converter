#pragma once
#include <string>
#include <iostream>

#define DT_NORMAL 1
#define DT_INVERSED 2
#define DT_CONTRAST 3

void parse_arguments(int argc, const char** argv);
struct startConfiguration 
{
    int displayWidth;
    int displayType;
    std::string videoPath;
};