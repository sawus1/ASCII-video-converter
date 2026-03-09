#include "config.hpp"

struct startConfiguration 
{
    int displayWidth;
    int displayType;
    int maxFrames;
    std::string videoPath;
};

enum cliArguments { dwidth, dtype, vpath, maxframes};

startConfiguration get_configuration(const char** arguments)
{
    
}
