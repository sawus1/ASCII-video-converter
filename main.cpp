#include <opencv2/opencv.hpp>
#include "config.hpp"
#include "video_processor.hpp"
#include "frame_processor.hpp"
#include "ascii_converter.hpp"
#include "renderer.hpp"
#include <iostream>
#include <string>

extern startConfiguration cfg;

int main(int argc, const char** argv) {
    parse_arguments(argc, argv);
    cv::VideoCapture video = get_video(cfg.videoPath);
    std::vector<cv::Mat> frames = extract_frames(video);
    std::cout << "Frames_count:" << frames.size() << "\n";
    process_frames(frames);
    AsciiVideo ascii_video = convert_video_to_ascii(frames);
    std::cout << "Video is ready. Press any key to continue" << std::endl;
    std::cin.ignore();
    std::cin.get();
    render_video(ascii_video);
}