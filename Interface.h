#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace 

{

	int x, y, ROI_width, ROI_height; //ROI parameters

}



void ROI(Mat image); //select ROI area from image

