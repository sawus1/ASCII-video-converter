#include "frame_processor.hpp"

extern startConfiguration cfg;

void process_frames(std::vector<cv::Mat>& original)
{
    for(auto &frame : original)
    {
        convert_grayscale(frame);
        convert_lowresolution(frame);
    }
}

void convert_grayscale(cv::Mat& frame)
{
    cv::Mat greyMat;
    cv::cvtColor(frame, greyMat, cv::COLOR_BGR2GRAY);
    frame = greyMat;
}

void convert_lowresolution(cv::Mat& frame)
{
    int targetWidth = cfg.displayWidth;
    double aspectRatio = (double)frame.rows / frame.cols;
    double charAspect = 0.5;
    int targetHeight = static_cast<int>(targetWidth * aspectRatio * charAspect);
    cv::Mat resized;
    cv::resize(frame, resized, cv::Size(targetWidth, targetHeight), 0, 0, cv::INTER_AREA);
    frame = resized;
}
