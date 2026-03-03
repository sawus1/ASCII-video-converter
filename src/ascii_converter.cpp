#include "ascii_converter.hpp"

std::vector<std::string> convert_frame_to_ascii(const cv::Mat& frame)
{
    std::vector<std::string> asciiFrame;
    asciiFrame.reserve(frame.rows);

    for (int i = 0; i < frame.rows; i++)
    {
        std::string line;
        line.reserve(frame.cols);

        for (int j = 0; j < frame.cols; j++)
        {
            int pixel = frame.at<uchar>(i, j);
            line += map_pixel_to_char(pixel);
        }

        asciiFrame.push_back(line);
    }

    return asciiFrame;
}

std::vector<std::vector<std::string>>
convert_video_to_ascii(const std::vector<cv::Mat>& video)
{
    std::vector<std::vector<std::string>> asciiVideo;
    asciiVideo.reserve(video.size());

    for (const auto& frame : video)
    {
        asciiVideo.push_back(convert_frame_to_ascii(frame));
    }

    return asciiVideo;
}

char map_pixel_to_char(int color)
{
    char* charsSorted = " `.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
    int charsLen = 92;
    int index = color * (charsLen - 1) / 255;
    return charsSorted[index];
}