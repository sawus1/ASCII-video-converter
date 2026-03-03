#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include <thread>
#define AsciiVideo std::vector<std::vector<std::string>>
#define AsciiFrame std::vector<std::string>
void render_frame(AsciiFrame frame);
void render_video(AsciiVideo video);
