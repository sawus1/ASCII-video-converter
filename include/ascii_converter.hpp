#pragma once
#include "config.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
std::vector<std::string> convert_frame_to_ascii(const cv::Mat& frame);
std::vector<std::vector<std::string>>
convert_video_to_ascii(const std::vector<cv::Mat>& video);
char map_pixel_to_char(int color);