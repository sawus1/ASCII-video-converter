#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
void process_frames(std::vector<cv::Mat>& original);
void convert_grayscale(cv::Mat& frame);
void convert_lowresolution(cv::Mat& frame);