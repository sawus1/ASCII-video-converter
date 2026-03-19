#include "frame_processor.hpp"

extern startConfiguration cfg;

void process_frames(std::vector<cv::Mat>& original)
{
    size_t total = original.size();
    const int barWidth = 50;

    for (size_t i = 0; i < total; ++i)
    {
        auto& frame = original[i];

        convert_grayscale(frame);
        convert_lowresolution(frame);

        float progress = (float)(i + 1) / total;
        int pos = progress * barWidth;

        std::cout << "\r[";
        for (int j = 0; j < barWidth; ++j)
        {
            if (j < pos) std::cout << "=";
            else if (j == pos) std::cout << ">";
            else std::cout << " ";
        }

        std::cout << "] " << int(progress * 100.0) << "%";
        std::cout.flush();
    }

    std::cout << std::endl;
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
