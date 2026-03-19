#include "video_exporter.hpp"

void export_video_to_sh(const AsciiVideo& video, const std::string& filename)
{
    std::ofstream out(filename);
    out << "#!/bin/bash\n\n";
    out << "clear\n\n";
    for(const auto& frame : video)
    {
        out << "echo -e \"\\033[H";
        for(const auto& line : frame)
        {
            for (char c : line)
            {
                if (c == '\\' || c == '"' || c == '$')
                    out << '\\';
                out << c;
            }
            out << "\\n";
        }
        out << "\"\n";
        out << "sleep 0.033\n\n";
    }
    out.close();
}