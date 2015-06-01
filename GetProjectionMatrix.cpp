//Skeletonization through the Zhang-Suen algorithm.  This function assumes the image is in 0 or 255 binary.

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "GetProjectionMatrix.h"

using namespace std;

vector<Mat> getProjectionMatrix(char* filename) {
	ifstream input(filename);
	assert(input);
	vector<Mat> projs;
	char line[1024];
	int num;

	input.getline(line, sizeof(line));
	sscanf(line, "%d", &num);

	// Creates projection matricies for all images
	for(int i=0; i < num; i++) {
		Mat P(3, 4, CV_32F);

		//Gets the next line (that contains data)
		input.getline(line, sizeof(line)); // blank

		//Goes through each row of the projection matrix (3 x 4 matrix)
		for(int j=0; j < 3; j++) {
			input.getline(line, sizeof(line));
			stringstream a(line);

			//Enters data into projection matrix from each column
			a >> P.at<float>(j, 0);
			a >> P.at<float>(j, 1);
			a >> P.at<float>(j, 2);
			a >> P.at<float>(j, 3);
		}

		// Adds the data in the last entry (increasing the vector size by 1)
		projs.push_back(P);
	}
	return projs;
}