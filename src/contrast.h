#pragma once
#include <iostream>
#include "image_enhancement.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

class contrast
{
public:
	
	std::vector<cv::Mat> ImageResult(Mat img);

};

