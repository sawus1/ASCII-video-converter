#include <opencv2/opencv.hpp>
#include "config.hpp"
#include "video_processor.hpp"
#include "frame_processor.hpp"
#include "ascii_converter.hpp"
#include "video_exporter.hpp"
#include "renderer.hpp"
#include <iostream>
#include <string>

extern startConfiguration cfg;

int main(int argc, const char** argv) {
    parse_arguments(argc, argv);
    cv::VideoCapture video = get_video(cfg.videoPath);
    std::vector<cv::Mat> frames = extract_frames(video);
    std::cout << "Frames_count:" << frames.size() << "\n";
    std::cout << "Processing frames" << "\n";
    process_frames(frames);
    AsciiVideo ascii_video = convert_video_to_ascii(frames);
    std::cout << "Video is ready. Press any key to continue(type n to skip rendering)" << std::endl;
    std::cin.ignore();
    char key = std::cin.get();
    if(!key == 'n')
    {
        render_video(ascii_video);
    }
    if(!cfg.outputVideoPath.empty()) export_video_to_sh(ascii_video, cfg.outputVideoPath);
}