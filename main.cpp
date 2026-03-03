#include <opencv2/opencv.hpp>
#include "video_processor.hpp"
#include "frame_processor.hpp"
#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    if(argc < 2){std::cout << "video path must be included as argument" << std::endl; return -1;}
    std::string path = argv[1];
    cv::VideoCapture video = get_video(path);
    std::vector<cv::Mat> frames = extract_frames(video);
    std::cout << "Frames_count:" << frames.size() << "\n";
    process_frames(frames);
    cv::imwrite("../assets/image.jpg", frames[20]);
}