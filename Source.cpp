/*
-------------Globalny próg na podstawie minimalizacji wariancji (Otsu)----------------

Nale¿y obliczyæ histogram dla obrazu oraz zaimplementowaæ algorytm binaryzacji Otsu. 
Operacja przeprowadzana bêdzie na obrazie w skali szaroœci.
Nale¿y przedyskutowaæ skutecznoœæ algorytmu (wskazaæ klasê obrazów dla których algorytm dzia³a najlepiej).

Definicja ROI, Parametry obliczania histogramu

*/

#include "Binarization.h"
#include "Interface.h"

using namespace std;
using namespace cv;

void RGB2GRAY(Mat &input, Mat &output)
{
	output = Mat(input.rows, input.cols, CV_8UC1); //create mat with the same size like input image and 1 channel (gray image)

	for (int i = 0; i < input.rows; i++)
	{
		for (int j = 0; j < input.cols; j++)
		{
			output.at<uchar>(i, j) = 1.0 / 3.0 * (double)(input.at<Vec3b>(i, j)[0]+ input.at<Vec3b>(i, j)[1]+ input.at<Vec3b>(i, j)[2]);

		}
	}


}

int main()
{
	Mat inputImg;
	inputImg = imread("C://Users/Mikolaj/Pictures/image.jpg"); //path to image
	
															   
	// check how many channels have input image (3-RGB, 1-gray)
	int channels = inputImg.channels(); 

	switch (channels)
	{
	case 1: //input image is gray
	{
		ROI(inputImg);
		break;
	}
	case 3: //input image is RGB
	{
		Mat gray; 
		RGB2GRAY(inputImg, gray);
		ROI(gray);
		break;
	}
	default:
		break;
	}


	return 0;

}