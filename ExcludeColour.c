//Skeletonization through the Zhang-Suen algorithm.  This function assumes the image is in 0 or 255 binary.

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "ExcludeColour.h"
#include "DisplayFrames.h"

using namespace std;
using namespace cv;

void excludeColour(Mat image, Mat maskImage, int colour, int display, int position) {
	uchar* imagePtr;
	uchar* maskPtr;

	// maskImage = Mat::zeros(image.rows, image.cols, CV_8UC1);

	for( int l = 0; l < image.rows; ++l) {
		imagePtr = image.ptr<uchar>(l);
		maskPtr = maskImage.ptr<uchar>(l);
		for (int m = 0; m < 3*image.cols; m += 3) {
			switch (colour) {
				case 0:
				if (imagePtr[m] > imagePtr[m+1] && imagePtr[m] > imagePtr[m+2]) {
					imagePtr[m] = 0;
					imagePtr[m+1] = 0;
					imagePtr[m+2] = 0;
				}
				else {
					maskPtr[(m+1)/3] = WHITE;
				}
				break;
				case 1:
				if (imagePtr[m+1] > imagePtr[m] && imagePtr[m+1] > imagePtr[m+2]) {
					imagePtr[m] = 0;
					imagePtr[m+1] = 0;
					imagePtr[m+2] = 0;
				}
				else {
					maskPtr[(m+1)/3] = WHITE;
				}
				break;
				case 2:
				if (imagePtr[m+2] > imagePtr[m+1] && imagePtr[m+2] > imagePtr[m]) {
					imagePtr[m] = 0;
					imagePtr[m+1] = 0;
					imagePtr[m+2] = 0;
				}
				else {
					maskPtr[(m+1)/3] = WHITE;
				}
				break;
			}
		}
	}

	switch (colour) {
		case 0:
		if(display) {
			disImage((char *)"Blue Excluded", image, position);
			waitKey(20);

		}		
		break;
		case 1:
		if(display) {
			disImage((char *)"Green Excluded", image, position);
			waitKey(20);
		}		
		break;
		case 2:
		if(display) {
			disImage((char *)"Red Excluded", image, position);
			waitKey(20);
		}		
		break;
	}

}