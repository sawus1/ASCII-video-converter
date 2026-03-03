#include <opencv2/opencv.hpp>
#include "video_processor.hpp"
#include "frame_processor.hpp"
#include "ascii_converter.hpp"
#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    if(argc < 2){std::cout << "video path must be included as argument" << std::endl; return -1;}
    std::string path = argv[1];
    cv::VideoCapture video = get_video(path);
    std::vector<cv::Mat> frames = extract_frames(video);
    std::cout << "Frames_count:" << frames.size() << "\n";
    process_frames(frames);
    std::vector<std::vector<std::string>> ascii_video = convert_video_to_ascii(frames);
    std::vector<std::string> frame = ascii_video[20];
    for(auto &row : frame)
    {
        std::cout << row << std::endl;
    }
}