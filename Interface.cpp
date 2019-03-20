#include "Interface.h"
#include "Binarization.h"

using namespace cv;
using namespace std;




void ROI(Mat image)
{
	int opction;
	cout << "Input data successfully found.  Rows:" << image.rows << " cols:" << image.cols << " channels:" << image.channels() << endl;;
	cout << endl;
	cout << "Please select region of image to binarization:" << endl;
	cout << "1.Full image " << endl;
	cout << "2.ROI" << endl;
	cin >> opction;
	switch (opction)
	{
	case 1:
	{
		//get full image
		x = 0;
		y = 0;
		ROI_width = image.cols;
		ROI_height = image.rows;
		break;
	}
	case 2:
	{
		cout << "1. Coordinates of the starting point:" << endl;
		cout << "X(0-" << image.cols << "):" << " ";
		cin >> x;

		cout << "Y(0-" << image.rows << "):" << " ";
		cin >> y;
		cout << endl;
		cout << "2. Width of region(0-" << image.cols - x << "):" << " ";
		cin >> ROI_width;
		cout << endl;
		cout << "3. Height of region(0-" << image.rows - y << "):" << " ";
		cin >> ROI_height;
		break;
	}
	default:
	{
		cout << "Wrong values" << endl;
		break;
	}

	}

	//showing the selected area (ROI) on the input image
	line(image, Point(x,y), Point(x+ROI_width,y), Scalar(0, 0, 255), 5, 8);
	line(image, Point(x + ROI_width, y), Point(x + ROI_width, y+ROI_height), Scalar(0, 0, 255), 5, 8);
	line(image, Point(x + ROI_width, y + ROI_height), Point(x, y + ROI_height), Scalar(0, 0, 255), 5, 8);
	line(image, Point(x, y + ROI_height), Point(x, y), Scalar(0, 0, 255), 5, 8);
	
	namedWindow("ROI", WINDOW_NORMAL);
	imshow("ROI", image);
	waitKey(0);

	cout << "Click space to get histogram of image" << endl;
	creatHistogram(image,x,y,ROI_width,ROI_height);

}