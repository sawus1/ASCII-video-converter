#include "renderer.hpp"

void render_frame(AsciiFrame frame)
{
    std::string buffer;
    buffer.reserve(frame.size() * frame[0].size());

    for (const auto& line : frame)
    {
        buffer += line;
        buffer += '\n';
    }

    std::cout << buffer;
}
void render_video(AsciiVideo video)
{
    for(const auto& frame : video)
    {
        std::cout << "\033[H";
        render_frame(frame);
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    
}