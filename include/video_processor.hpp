#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
cv::VideoCapture get_video(std::string path);
std::vector<cv::Mat> extract_frames(cv::VideoCapture video);