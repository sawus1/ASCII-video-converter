#include "config.hpp"
#include <string>

startConfiguration cfg;

void parse_arguments(int argc, const char** argv) 
{
    if(argc < 2){std::cerr << "video path must be included as argument." << std::endl; exit(-1);}
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if((arg == "--file" || arg == "-f") && i + 1 < argc) {
            cfg.videoPath = argv[i + 1];
        }
        else if((arg == "--display-width" || arg == "-w") && i + 1 < argc) {
            cfg.displayWidth = atoi(argv[i+1]);
        }
        else if((arg == "--display-type" || arg == "-d") && i + 1 < argc) {
            std::string displayType = argv[i + 1];
            if(displayType == "normal") cfg.displayType = DT_NORMAL;
            else if(displayType == "inversed") cfg.displayType = DT_INVERSED;
            else if(displayType == "contrast") cfg.displayType = DT_CONTRAST;
        }
    }
    if(cfg.videoPath.empty()) {std::cerr << "video path must be included as argument." << std::endl; exit(-1);}
    if(cfg.displayWidth == 0) {cfg.displayWidth = 100; }
    if(cfg.displayType == 0) {cfg.displayType = DT_NORMAL; }
}
