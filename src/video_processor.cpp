#include "video_processor.hpp"

cv::VideoCapture get_video(std::string path)
{
    cv::VideoCapture cap(path);

    if (!cap.isOpened()) {
        std::cout << "Error opening video\n";
        exit(-1);
    }
    return cap;
}

std::vector<cv::Mat> extract_frames(cv::VideoCapture video)
{
    try
    {
        std::vector<cv::Mat> frames;
        for(int frameNum = 0; frameNum < video.get(cv::CAP_PROP_FRAME_COUNT);frameNum++)
        {
            cv::Mat frame;
            video >> frame;
            frames.push_back(frame);
        }
        return frames;
    }
    catch(cv::Exception& e) 
    {
        std::cerr << e.msg << std::endl;
        exit(1);
    }
}