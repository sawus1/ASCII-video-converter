#include <fstream>
#include <string>

#define AsciiVideo std::vector<std::vector<std::string>>

void export_video_to_sh(const AsciiVideo& video, const std::string& filename);