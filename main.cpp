#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    if(argc < 2){std::cout << "video path must be included as argument" << std::endl; return -1;}
    std::string path = argv[1];
    cv::VideoCapture cap(path);

    if (!cap.isOpened()) {
        std::cout << "Error opening video\n";
        return -1;
    }

    std::cout << "OpenCV works!\n";
}