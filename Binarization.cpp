#include "Binarization.h"
#include "Interface.h"

using namespace cv;
using namespace std;

void Otsu(int histogram[], Mat img, int x, int y, int ROI_width, int ROI_height)
{
	double sum = 0; 
	int totalPixels = ROI_height*ROI_width; //number of all pixels in the ROI
	for (int i = 0; i < 256; i++)
		sum += i * histogram[i]; 


	double sumB = 0;
	int wB = 0;		// Weight Background
	int wF = 0;		// Weight Foreground

	double max = 0; // Maximizing inter-class variance
	int threshold = 0; 

	for (int i = 0; i < 256; i++)
	{
		wB += histogram[i]; //numers of background pixels
		if (wB == 0) continue;

		wF = totalPixels - wB; //numers of foreground pixels
		if (wF == 0) break;

		sumB += (double)(i * histogram[i]); 
		double mB = sumB / wB;            // Mean Background class
		double mF = (sum - sumB) / wF;    // Mean Foreground class

		// Calculate Between Class Variance
		double between = (double)wB * (double)wF * (mB - mF) * (mB - mF); // Inter-class variance

		// Check if new maximum found
		if (between > max) //check if actual inter-class variance is bigger then the last highest value of inter-class variance 
		{
			max = between;
			threshold = i; //if yes, save new value of threshold
		}
	}


	//Binarization
	int pixelValue;

	for (int i = y; i < y + ROI_height; i++)
	{
		for (int j = x; j < x + ROI_width; j++)
		{
			pixelValue = (int)img.at<uchar>(i, j);

			if (pixelValue > threshold) //if value of pixel is > then threshold, pixel is white
				img.at<uchar>(i, j) = 255;
			else //if value of pixel is < then threshold, pixel is black
				img.at<uchar>(i, j) = 0;

		}
	}

	namedWindow("Otso", WINDOW_NORMAL);

	imshow("Otso", img);

	waitKey(0);
	
 }




void creatHistogram(Mat img, int x, int y, int ROI_width, int ROI_height)
{
	
	int pixelIntensity; //value of pixel in gray image
	int maxPixels = 0;; //to find the most pixels with a given intensity

	
	
	//create histogram of input image
	for (int i = y; i < y + ROI_height; i++)
	{
		for (int j = x; j < x + ROI_width; j++)
		{
			pixelIntensity = (int)img.at<uchar>(i, j);
			Hist[pixelIntensity]++;
			
		}
	}
	
	//find max value of histogram. It will be helpful for draw histogram.
	for (int i = 0; i < 255; i++)  
	{
		if (Hist[i] > maxPixels)
			maxPixels = Hist[i];
	}
	//draw histogram
	Mat HistPlot(maxPixels, 256, CV_8UC3, Scalar(0, 0, 0));

	for (int i = 0; i < 255; i++)
	{
		line(HistPlot, Point(i, maxPixels), Point(i, maxPixels - Hist[i]), Scalar(0, 0, 255), 1, 8, 0);
	}
	namedWindow("Histogram", WINDOW_NORMAL);

	imshow("Histogram", HistPlot);

	waitKey(0);

	Otsu(Hist, img,x,y,ROI_width,ROI_height);
}