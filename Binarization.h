#pragma once
#include"Interface.h"


using namespace cv;
using namespace std;

namespace
{

	int Hist[256] = { 0 }; //creating a place in memory for a histogram

}


void Otsu(int histogram[], Mat img, int x, int y, int ROI_width, int ROI_height); //function with Otsu's method

void creatHistogram(Mat img, int x, int y, int ROI_width, int ROI_height);

