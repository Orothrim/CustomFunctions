#ifndef _getprojectionmatrix_included_h_
#define _getprojectionmatrix_included_h_

#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include "GetProjectionMatrix.cpp"

vector<Mat> getProjectionMatrix(char* filename);

#endif
